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

#include "LibinputTouchEvent.h"
#include <libinput.h>

namespace InputActions
{

LibinputTouchEvent::LibinputTouchEvent(libinput_event_touch *event)
    : m_event(event)
{
}

int32_t LibinputTouchEvent::slot() const
{
    return libinput_event_touch_get_slot(m_event);
}

QPointF LibinputTouchEvent::position() const
{
    return {libinput_event_touch_get_x(m_event), libinput_event_touch_get_y(m_event)};
}


}