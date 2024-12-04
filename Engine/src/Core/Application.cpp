#include "Application.h"
#include "Rendering/Renderer.h"
#include <iostream>

namespace Engine
{
	Application::Application()
		: _running(false)
	{
		bool result;

		result = window.Init(800, 600, "Gravitum Window", std::bind(&Application::OnEvent, this, std::placeholders::_1));
		if (!result)
		{
			// TODO: Window creation failed, log it
			return;
		}

		result = Renderer::Init();
		if (!result)
		{
			// TODO: Renderer initialization failed, log it
			return;
		}

		_running = true;
	}

	Application::~Application()
	{
		Renderer::Shutdown();
		window.Shutdown();
	}

	void Application::Run()
	{
		Init();

		while (_running)
		{
			window.Update();

			Update();

			glClear(GL_COLOR_BUFFER_BIT);

			/* render */
			Render();

			window.Present();
		}

		Shutdown();
	}

	void Application::Close(WindowCloseEvent& e)
	{
		_running = false;
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(std::bind(&Application::Close, this, std::placeholders::_1));
	}
}
