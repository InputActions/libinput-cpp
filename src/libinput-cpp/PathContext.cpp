/*
    libevdev-cpp - Minimal C++ libinput wrapper for InputActions
    Copyright (C) 2026 Marcin Woźniak

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "PathContext.h"
#include "Device.h"
#include "Event.h"
#include <fcntl.h>
#include <libinput.h>
#include <linux/input.h>
#include <sys/ioctl.h>

namespace InputActions::libinput
{

PathContext::PathContext()
{
    static libinput_interface interface{
        .open_restricted = &PathContext::openRestricted,
        .close_restricted = &PathContext::closeRestricted,
    };
    m_libinput = libinput_path_create_context(&interface, this);

    m_notifier = std::make_unique<QSocketNotifier>(fd(), QSocketNotifier::Read);
    connect(m_notifier.get(), &QSocketNotifier::activated, this, [this]() {
        Q_EMIT eventsAvailable();
    });
}

PathContext::~PathContext()
{
    m_devices.clear();
    libinput_unref(m_libinput);
}

int PathContext::fd() const
{
    return libinput_get_fd(m_libinput);
}

Device *PathContext::addDevice(const QString &path, bool grab)
{
    m_grab = grab;
    auto *libinputDevice = libinput_path_add_device(m_libinput, path.toStdString().c_str());
    if (!libinputDevice) {
        return {};
    }
    libinput_device_ref(libinputDevice);

    auto device = std::make_unique<Device>(libinputDevice);
    auto *devicePtr = device.get();
    m_devices.push_back(std::move(device));
    return devicePtr;
}

void PathContext::removeDevice(Device *device)
{
    libinput_path_remove_device(device->raw());
    std::erase_if(m_devices, [device](auto &existingDevice) {
        return existingDevice.get() == device;
    });
}

void PathContext::dispatch()
{
    libinput_dispatch(m_libinput);
}

std::optional<Event> PathContext::getEvent()
{
    auto *event = libinput_get_event(m_libinput);
    if (!event) {
        return {};
    }

    return {event};
}

int PathContext::openRestricted(const char *path, int flags, void *data)
{
    const auto *self = static_cast<PathContext *>(data);
    const auto fd = open(path, flags);
    if (fd < 0) {
        return -errno;
    }

    if (self->m_grab) {
        ioctl(fd, EVIOCGRAB, 1);
    }
    return fd;
}

void PathContext::closeRestricted(int fd, void *data)
{
    close(fd);
}

}