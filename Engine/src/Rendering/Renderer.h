#pragma once

#include <glad/glad.h>

namespace Engine
{
	class Renderer
	{
	public:
		static bool Init();
		static void Shutdown();

		static void BeginDraw();
		static void Draw();
	};
}