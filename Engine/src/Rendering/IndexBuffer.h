#pragma once

#include <glad/glad.h>

namespace Engine
{
	class IndexBuffer
	{
	public:
		IndexBuffer(const unsigned int* data, unsigned int size);
		~IndexBuffer();

		inline void Bind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _id); }
		inline void Unbind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }

		inline unsigned int GetCount() const { return _count; }

	private:
		GLuint _id;
		unsigned int _count;
	};
}