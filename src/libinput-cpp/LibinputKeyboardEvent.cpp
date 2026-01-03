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

#include "LibinputKeyboardEvent.h"
#include <libinput.h>

namespace InputActions
{

LibinputKeyboardEvent::LibinputKeyboardEvent(libinput_event_keyboard *event)
    : m_event(event)
{
}

uint32_t LibinputKeyboardEvent::key() const
{
    return libinput_event_keyboard_get_key(m_event);
}

bool LibinputKeyboardEvent::state() const
{
    return libinput_event_keyboard_get_key_state(m_event) == LIBINPUT_KEY_STATE_PRESSED;
}

}