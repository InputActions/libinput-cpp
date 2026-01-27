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

#include "LibinputEvent.h"
#include "LibinputGestureEvent.h"
#include "LibinputKeyboardEvent.h"
#include "LibinputPointerEvent.h"
#include "LibinputTouchEvent.h"

namespace InputActions
{

LibinputEvent::LibinputEvent(libinput_event *event)
    : m_event(event)
{
}

LibinputEvent::LibinputEvent(LibinputEvent &&other)
{
    *this = std::move(other);
}

LibinputEvent::~LibinputEvent()
{
    if (!m_event) {
        return;
    }

    libinput_event_destroy(m_event);
}

libinput_event_type LibinputEvent::type() const
{
    return libinput_event_get_type(m_event);
}

std::optional<LibinputGestureEvent> LibinputEvent::gestureEvent() const
{
    auto *event = libinput_event_get_gesture_event(m_event);
    if (!event) {
        return {};
    }

    return LibinputGestureEvent(event);
}

std::optional<LibinputKeyboardEvent> LibinputEvent::keyboardEvent() const
{
    auto *event = libinput_event_get_keyboard_event(m_event);
    if (!event) {
        return {};
    }

    return LibinputKeyboardEvent(event);
}

std::optional<LibinputPointerEvent> LibinputEvent::pointerEvent() const
{
    auto *event = libinput_event_get_pointer_event(m_event);
    if (!event) {
        return {};
    }

    return LibinputPointerEvent(event);
}

std::optional<LibinputTouchEvent> LibinputEvent::touchEvent() const
{
    auto *event = libinput_event_get_touch_event(m_event);
    if (!event) {
        return {};
    }

    return LibinputTouchEvent(event);
}

LibinputEvent &LibinputEvent::operator=(LibinputEvent &&other)
{
    std::swap(m_event, other.m_event);
    return *this;
}

}