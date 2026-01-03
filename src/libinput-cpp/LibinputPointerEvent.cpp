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

#include "LibinputPointerEvent.h"

namespace InputActions
{

LibinputPointerEvent::LibinputPointerEvent(libinput_event_pointer *event)
    : m_event(event)
{
}

bool LibinputPointerEvent::hasAxis(libinput_pointer_axis axis) const
{
    return libinput_event_pointer_has_axis(m_event, axis) != 0;
}

qreal LibinputPointerEvent::axisValue(libinput_pointer_axis axis) const
{
    return libinput_event_pointer_get_axis_value(m_event, axis);
}

uint32_t LibinputPointerEvent::button() const
{
    return libinput_event_pointer_get_button(m_event);
}

bool LibinputPointerEvent::state() const
{
    return libinput_event_pointer_get_button_state(m_event) == LIBINPUT_BUTTON_STATE_PRESSED;
}

QPointF LibinputPointerEvent::delta() const
{
    return {libinput_event_pointer_get_dx(m_event), libinput_event_pointer_get_dy(m_event)};
}

QPointF LibinputPointerEvent::deltaUnaccelerated() const
{
    return {libinput_event_pointer_get_dx_unaccelerated(m_event), libinput_event_pointer_get_dy_unaccelerated(m_event)};
}

}