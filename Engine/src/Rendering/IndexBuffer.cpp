#include "IndexBuffer.h"

namespace Engine
{
	IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int size)
		: _count(size / sizeof(unsigned int))
	{
		glGenBuffers(1, &_id);

		Bind();
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
		Unbind();
	}

	IndexBuffer::~IndexBuffer()
	{
		glDeleteBuffers(1, &_id);
	}
}
