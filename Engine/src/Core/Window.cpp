#include "Window.h"

#include "Event/WindowEvent.h"

namespace Engine
{
	Window::Window()
		: _window(nullptr), _width(0), _height(0)
	{
	}

	Window::~Window()
	{
	}

	bool Window::Init(int width, int height, const char* title, std::function<void(Event&)> eventFunc)
	{
		_eventCallback = eventFunc;

		glfwSetErrorCallback([](int error_code, const char* description) {
			// TODO: Any glfw error occured, log it
			});

		if (!glfwInit())
		{
			// TODO: Failed to initialize glfw library, log it
			return false;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		_width = width;
		_height = height;

		_window = glfwCreateWindow(width, height, title, NULL, NULL);
		if (!_window)
		{
			// TODO: Failed to create window, log it
			return false;
		}

		glfwMakeContextCurrent(_window);
		glfwSetWindowUserPointer(_window, this);

		glfwSetWindowCloseCallback(_window, [](GLFWwindow* window) {
			auto wnd = (Window*)glfwGetWindowUserPointer(window);

			WindowCloseEvent event;
			wnd->_eventCallback(event);
			});

		return true;
	}

	void Window::Update()
	{
		glfwPollEvents();
	}

	void Window::Present()
	{
		glfwSwapBuffers(_window);
	}

	void Window::Shutdown()
	{
		glfwTerminate();
	}
}
