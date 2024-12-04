#include "Renderer.h"

#include <GLFW/glfw3.h>

namespace Engine
{
	bool Renderer::Init()
	{
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			// Log error
			return false;
		}

		return true;
	}

	void Renderer::Shutdown()
	{
	}

	void Renderer::BeginDraw()
	{
	}

	void Renderer::Draw()
	{
	}
}
