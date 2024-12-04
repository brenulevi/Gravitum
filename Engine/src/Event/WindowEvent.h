#pragma once

#include "Event.h"

namespace Engine
{
	class WindowCreateEvent : public Event
	{
	public:
		WindowCreateEvent() {}
		~WindowCreateEvent() {}

		static EventType GetStaticType() { return EventType::WindowCreate; }
		virtual EventType GetType() { return EventType::WindowCreate; }
		virtual std::string GetString() override { return "WindowCreate"; }
	};

	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}
		~WindowCloseEvent() {}

		static EventType GetStaticType() { return EventType::WindowClose; }
		virtual EventType GetType() { return EventType::WindowClose; }
		virtual std::string GetString() override { return "WindowClose"; }
	};
}