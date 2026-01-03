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

#include <QPointF>

struct libinput_event_gesture;

namespace InputActions
{

class LibinputGestureEvent
{
public:
    LibinputGestureEvent(libinput_event_gesture *event);

    /**
     * @see libinput_event_gesture_get_finger_count
     */
    int fingerCount() const;
    /**
     * @see libinput_event_gesture_get_cancelled
     */
    bool cancelled() const;

    /**
     * @see libinput_event_gesture_get_angle_delta
     */
    qreal angleDelta() const;
    /**
     * @see libinput_event_gesture_get_scale
     */
    qreal scale() const;

    /**
     * @see libinput_event_gesture_get_dx
     * @see libinput_event_gesture_get_dy
     */
    QPointF delta() const;
    /**
     * @see libinput_event_gesture_get_dx_unaccelerated
     * @see libinput_event_gesture_get_dy_unaccelerated
     */
    QPointF deltaUnaccelerated() const;

private:
    libinput_event_gesture *m_event;
};

}