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

#include <QtClassHelperMacros>

struct udev_device;

namespace InputActions
{

class UdevDevice
{
public:
    UdevDevice(udev_device *device);
    UdevDevice(UdevDevice &&);
    ~UdevDevice();

    const char *propertyValue(const char *key) const;

    UdevDevice &operator=(UdevDevice &&);

private:
    Q_DISABLE_COPY(UdevDevice);

    udev_device *m_device{};
};

}