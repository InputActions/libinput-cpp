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

#include "LibinputGestureEvent.h"
#include <libinput.h>

namespace InputActions
{

LibinputGestureEvent::LibinputGestureEvent(libinput_event_gesture *event)
    : m_event(event)
{
}

int LibinputGestureEvent::fingerCount() const
{
    return libinput_event_gesture_get_finger_count(m_event);
}

bool LibinputGestureEvent::cancelled() const
{
    return libinput_event_gesture_get_cancelled(m_event) == 1;
}

qreal LibinputGestureEvent::angleDelta() const
{
    return libinput_event_gesture_get_angle_delta(m_event);
}

qreal LibinputGestureEvent::scale() const
{
    return libinput_event_gesture_get_scale(m_event);
}

QPointF LibinputGestureEvent::delta() const
{
    return {libinput_event_gesture_get_dx(m_event), libinput_event_gesture_get_dy(m_event)};
}

QPointF LibinputGestureEvent::deltaUnaccelerated() const
{
    return {libinput_event_gesture_get_dx_unaccelerated(m_event), libinput_event_gesture_get_dy_unaccelerated(m_event)};
}

}