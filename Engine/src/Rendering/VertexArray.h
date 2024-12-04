#pragma once

#include <glad/glad.h>

#include "VertexBuffer.h"
#include "BufferLayout.h"

namespace Engine
{
	class VertexArray
	{
	public:
		VertexArray();
		~VertexArray();

		void AddBuffer(VertexBuffer& vb, BufferLayout& layout);

		inline void Bind() const { glBindVertexArray(_id); }
		inline void Unbind() const { glBindVertexArray(0); }

	private:
		GLuint _id;
	};
}