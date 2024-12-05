#pragma once

#include <glad/glad.h>

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

namespace Engine
{
	class Renderer
	{
	public:
		static bool Init();
		static void Shutdown();

		static void BeginDraw();
		static void DrawIndexed(VertexArray& va, IndexBuffer& ib, Shader& shader);
	};
}