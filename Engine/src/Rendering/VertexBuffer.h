#pragma once

#include <glad/glad.h>

namespace Engine
{
	class VertexBuffer
	{
	public:
		VertexBuffer(const void* data, unsigned int size);
		~VertexBuffer();

		inline void Bind() const { glBindBuffer(GL_ARRAY_BUFFER, _id); }
		inline void Unbind() const { glBindBuffer(GL_ARRAY_BUFFER, 0); }

	private:
		GLuint _id;
	};
}