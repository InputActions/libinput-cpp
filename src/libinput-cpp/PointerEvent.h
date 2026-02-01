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
#include <libinput.h>

namespace InputActions::libinput
{

class PointerEvent
{
public:
    PointerEvent(libinput_event_pointer *event);

    /**
     * @return True if the specified axis exists, false otherwise.
     * @see libinput_event_pointer_has_axis
     */
    bool hasAxis(libinput_pointer_axis axis) const;
    /**
     * @see libinput_event_pointer_get_axis_value
     */
    qreal axisValue(libinput_pointer_axis axis) const;

    /**
     * @see libinput_event_pointer_get_button
     */
    uint32_t button() const;
    /**
     * @return True if LIBINPUT_BUTTON_STATE_PRESSED, false otherwise.
     * @see libinput_event_pointer_get_button_state
     */
    bool state() const;

    /**
     * @see libinput_event_pointer_get_dx
     * @see libinput_event_pointer_get_dy
     */
    QPointF delta() const;
    /**
     * @see libinput_event_pointer_get_dx_unaccelerated
     * @see libinput_event_pointer_get_dy_unaccelerated
     */
    QPointF deltaUnaccelerated() const;

private:
    libinput_event_pointer *m_event;
};

}