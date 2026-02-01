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

#include "Device.h"
#include "UdevDevice.h"
#include <libinput.h>

namespace InputActions::libinput
{

Device::Device(libinput_device *device)
    : m_device(device)
{
}

Device::~Device()
{
    libinput_device_unref(m_device);
}

void Device::configTapSetEnabled(bool value)
{
    libinput_device_config_tap_set_enabled(m_device, value ? LIBINPUT_CONFIG_TAP_ENABLED : LIBINPUT_CONFIG_TAP_DISABLED);
}

QString Device::name() const
{
    return libinput_device_get_name(m_device);
}

QString Device::sysName() const
{
    return libinput_device_get_sysname(m_device);
}

QSizeF Device::size() const
{
    double width;
    double height;
    if (libinput_device_get_size(m_device, &width, &height)) {
        return {};
    }

    return {width, height};
}

UdevDevice Device::udevDevice() const
{
    return {libinput_device_get_udev_device(m_device)};
}

}