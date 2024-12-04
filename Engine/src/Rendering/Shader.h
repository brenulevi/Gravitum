#pragma once

#include <glad/glad.h>
#include <unordered_map>
#include <string>

namespace Engine
{
	class Shader
	{
	public:
		Shader(const char* vertexPath, const char* fragmentPath);
		~Shader();

		inline void SetUniform(const std::string name, int value) { glUniform1i(GetUniformLocation(name), value); }

		inline void Bind() const { glUseProgram(_id); }
		inline void Unbind() const { glUseProgram(0); }

	private:
		int GetUniformLocation(std::string name);
		GLuint CreateShader(GLenum type, const char* path);

	private:
		GLuint _id;
		std::unordered_map<std::string, int> _uniforms;
		const char* _vPath;
		const char* _fPath;
	};
}