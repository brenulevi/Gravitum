#pragma once

#include <glad/glad.h>
#include <vector>

namespace Engine
{
	struct BufferElement
	{
		int size;
		GLenum type;
		bool normalized;
		unsigned int sizeOfType;
	};

	class BufferLayout
	{
	public:
		BufferLayout() : _stride(0) {}
		~BufferLayout() {}

		template <typename T>
		void Push(int size, bool normalized);

		template <>
		void Push<float>(int size, bool normalized);

		inline std::vector<BufferElement>& GetElements() { return _elements; }
		inline unsigned int GetStride() { return _stride; }

	private:
		std::vector<BufferElement> _elements;
		unsigned int _stride;
	};

	template<typename T>
	inline void BufferLayout::Push(int size, bool normalized)
	{
	}

	template<>
	inline void BufferLayout::Push<float>(int size, bool normalized)
	{
		_elements.push_back({ size, GL_FLOAT, normalized, sizeof(float) });
		_stride += sizeof(float);
	}
}