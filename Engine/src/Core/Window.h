#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <functional>

#include "Event/Event.h"

namespace Engine
{
	class Window
	{
	public:
		Window();
		~Window();

		bool Init(int width, int height, const char* title, std::function<void(Event&)> eventFunc);
		void Update();
		void Present();
		void Shutdown();

	private:
		GLFWwindow* _window;
		int _width;
		int _height;

		std::function<void(Event&)> _eventCallback;
	};
}