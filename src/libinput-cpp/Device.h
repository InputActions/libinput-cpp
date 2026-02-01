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

#pragma once

#include <QSizeF>
#include <QString>
#include <QtClassHelperMacros>

struct libinput_device;

namespace InputActions::libinput
{

class UdevDevice;

class Device
{
public:
    Device(libinput_device *device);
    ~Device();

    libinput_device *raw() { return m_device; }

    /**
     * @see libinput_device_get_name
     */
    QString name() const;
    /**
     * @see libinput_device_get_sysname
     */
    QString sysName() const;

    /**
     * @see libinput_device_get_size
     */
    QSizeF size() const;

    /**
     * @see libinput_device_get_udev_device
     */
    UdevDevice udevDevice() const;

    /**
     * @param value true - LIBINPUT_CONFIG_TAP_ENABLED, false - LIBINPUT_CONFIG_TAP_DISABLED
     * @see libinput_device_config_tap_set_enabled
     */
    void configTapSetEnabled(bool value);

private:
    Q_DISABLE_COPY_MOVE(Device);

    libinput_device *m_device;
};

}