#include "VertexArray.h"

Engine::VertexArray::VertexArray()
{
	glGenVertexArrays(1, &_id);
}

Engine::VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &_id);
}

void Engine::VertexArray::AddBuffer(VertexBuffer& vb, BufferLayout& layout)
{
	Bind();
	vb.Bind();

	auto& elements = layout.GetElements();
	unsigned int offset = 0;
	for (int i = 0; i < elements.size(); i++)
	{
		auto& e = elements[i];
		glVertexAttribPointer(i, e.size, e.type, e.normalized, layout.GetStride(), (void*)offset);
		glEnableVertexAttribArray(i);
		offset += e.size * e.sizeOfType;
	}

	Unbind();
	vb.Unbind();
}
