#include "Application.h"

namespace Engine
{
	Application::Application()
		: _running(false)
	{
		bool result;

		result = window.Init(800, 600, "Gravitum Window");
		if (!result)
		{

		}


	}

	Application::~Application()
	{
		window.Shutdown();
	}

	void Application::Run()
	{
		while (_running)
		{

		}
	}

	void Application::Close()
	{
		_running = false;
	}
}
