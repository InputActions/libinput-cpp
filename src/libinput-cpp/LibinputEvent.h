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
#include <libinput.h>
#include <optional>

namespace InputActions
{

class LibinputGestureEvent;
class LibinputKeyboardEvent;
class LibinputPointerEvent;
class LibinputTouchEvent;

class LibinputEvent
{
public:
    LibinputEvent(libinput_event *event);
    ~LibinputEvent();

    Q_DISABLE_COPY_MOVE(LibinputEvent);

    libinput_event_type type() const;

    /**
     * @return The gesture event or std::nullopt if this event is not a gesture event. The returned object becomes invalid when its parent is deleted.
     * @see libinput_event_get_gesture_event
     */
    std::optional<LibinputGestureEvent> gestureEvent() const;
    /**
     * @return The keyboard event or std::nullopt if this event is not a keyboard event. The returned object becomes invalid when its parent is deleted.
     * @see libinput_event_get_keyboard_event
     */
    std::optional<LibinputKeyboardEvent> keyboardEvent() const;
    /**
     * @return The pointer event or std::nullopt if this event is not a pointer event. The returned object becomes invalid when its parent is deleted.
     * @see libinput_event_get_pointer_event
     */
    std::optional<LibinputPointerEvent> pointerEvent() const;
    /**
     * @return The touch event or std::nullopt if this event is not a touch event. The returned object becomes invalid when its parent is deleted.
     * @see libinput_event_get_touch_event
     */
    std::optional<LibinputTouchEvent> touchEvent() const;

private:
    libinput_event *m_event;
};

}