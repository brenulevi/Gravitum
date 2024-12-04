#pragma once

#include "Window.h"
#include "Event/WindowEvent.h"

namespace Engine
{
	class Application
	{
	public:
		Application();
		~Application();

		void Run();

		void Close(WindowCloseEvent& e);

	private:
		void OnEvent(Event& e);

	protected:
		virtual void Init() = 0;
		virtual void Update() = 0;
		virtual void Render() = 0;
		virtual void Shutdown() = 0;

	protected:
		Window window;

	private:
		bool _running;
	};
}