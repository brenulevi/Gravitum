#include "Renderer.h"

#include <GLFW/glfw3.h>

namespace Engine
{
	bool Renderer::Init()
	{
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			// TODO: Error when initializing glad, log it
			return false;
		}

		return true;
	}

	void Renderer::Shutdown()
	{
	}

    void Renderer::BeginDraw()
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void Renderer::DrawIndexed(VertexArray& va, IndexBuffer& ib, Shader& shader)
	{
		shader.Bind();
		va.Bind();
		ib.Bind();
		glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, 0);
	}
}
