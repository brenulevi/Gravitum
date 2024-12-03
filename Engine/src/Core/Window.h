#pragma once

namespace Engine
{
	class Window
	{
	public:
		Window();
		~Window();

		bool Init(int width, int height, const char* title);
		void Shutdown();

	private:
		int _width;
		int _height;
	};
}