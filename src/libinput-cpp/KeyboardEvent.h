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

#include <cstdint>

struct libinput_event_keyboard;

namespace InputActions::libinput
{

class KeyboardEvent
{
public:
    KeyboardEvent(libinput_event_keyboard *event);

    /**
     * @see libinput_event_keyboard_get_key
     */
    uint32_t key() const;

    /**
     * @return True if LIBINPUT_KEY_STATE_PRESSED, false otherwise.
     * @see libinput_event_keyboard_get_key_state
     */
    bool state() const;

private:
    libinput_event_keyboard *m_event;
};

}