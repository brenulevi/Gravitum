#pragma once

#include "Window.h"

namespace Engine
{
	class Application
	{
	public:
		Application();
		~Application();

		void Run();

		void Close();

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