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

#include "Event.h"
#include "GestureEvent.h"
#include "KeyboardEvent.h"
#include "PointerEvent.h"
#include "TouchEvent.h"

namespace InputActions::libinput
{

Event::Event(libinput_event *event)
    : m_event(event)
{
}

Event::Event(Event &&other)
{
    *this = std::move(other);
}

Event::~Event()
{
    if (!m_event) {
        return;
    }

    libinput_event_destroy(m_event);
}

libinput_event_type Event::type() const
{
    return libinput_event_get_type(m_event);
}

std::optional<GestureEvent> Event::gestureEvent() const
{
    auto *event = libinput_event_get_gesture_event(m_event);
    if (!event) {
        return {};
    }

    return GestureEvent(event);
}

std::optional<KeyboardEvent> Event::keyboardEvent() const
{
    auto *event = libinput_event_get_keyboard_event(m_event);
    if (!event) {
        return {};
    }

    return KeyboardEvent(event);
}

std::optional<PointerEvent> Event::pointerEvent() const
{
    auto *event = libinput_event_get_pointer_event(m_event);
    if (!event) {
        return {};
    }

    return PointerEvent(event);
}

std::optional<TouchEvent> Event::touchEvent() const
{
    auto *event = libinput_event_get_touch_event(m_event);
    if (!event) {
        return {};
    }

    return TouchEvent(event);
}

Event &Event::operator=(Event &&other)
{
    std::swap(m_event, other.m_event);
    return *this;
}

}