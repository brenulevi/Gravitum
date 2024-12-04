#pragma once

#include <string>

namespace Engine
{
	enum class EventType {
		WindowCreate, WindowClose
	};

	class Event
	{
	public:
		Event() {}
		~Event() {}

		virtual EventType GetType() = 0;
		virtual std::string GetString() { return "Event"; }
	};

	class EventDispatcher
	{
	public:
		EventDispatcher(Event& e) : _event(e) {}
		~EventDispatcher() {}

		template<typename T>
		void Dispatch(std::function<void(T&)> func);

	private:
		Event& _event;
	};

	template<typename T>
	inline void EventDispatcher::Dispatch(std::function<void(T&)> func)
	{
		if (T::GetStaticType() == _event.GetType())
		{
			func(*(T*)&_event);
		}
	}
}