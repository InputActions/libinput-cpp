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

#include <QObject>
#include <QSocketNotifier>
#include <QString>
#include <QtClassHelperMacros>
#include <vector>

struct libinput;
struct libinput_device;

namespace InputActions
{

class LibinputDevice;
class LibinputEvent;

class LibinputPathContext : public QObject
{
    Q_OBJECT

public:
    /**
     * @see libinput_path_create_context
     */
    LibinputPathContext();
    ~LibinputPathContext() override;

    /**
     * @see libinput_get_fd
     */
    int fd() const;

    /**
     * @see libinput_path_add_device
     */
    LibinputDevice *addDevice(const QString &path, bool grab = false);
    void removeDevice(LibinputDevice *device);

    /**
     * @see libinput_dispatch
     */
    void dispatch();
    /**
     * @see libinput_get_event
     */
    std::optional<LibinputEvent> getEvent();

signals:
    void eventsAvailable();

private:
    static int openRestricted(const char *path, int flags, void *data);
    static void closeRestricted(int fd, void *data);

    Q_DISABLE_COPY_MOVE(LibinputPathContext);

    libinput *m_libinput;
    std::unique_ptr<QSocketNotifier> m_notifier;
    bool m_grab{};
    std::vector<std::unique_ptr<LibinputDevice>> m_devices;
};

}