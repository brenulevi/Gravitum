#include "Shader.h"

#include <fstream>
#include <sstream>
#include <string>

Engine::Shader::Shader(const char* vertexPath, const char* fragmentPath)
	: _vPath(vertexPath), _fPath(fragmentPath)
{
	auto vShader = CreateShader(GL_VERTEX_SHADER, vertexPath);
	auto fShader = CreateShader(GL_FRAGMENT_SHADER, fragmentPath);

	if (vShader == 0 || fShader == 0)
	{
		// TODO: Error when creating or compilating shader, log it
		return;
	}

	_id = glCreateProgram();
	glAttachShader(_id, vShader);
	glAttachShader(_id, fShader);
	glLinkProgram(_id);

	int result;
	glGetProgramiv(_id, GL_LINK_STATUS, &result);
	if (!result)
	{
		char buf[256];
		glGetProgramInfoLog(_id, 256, 0, buf);
		// TODO: Program link goes wrong, log it
	}

	glDeleteShader(vShader);
	glDeleteShader(fShader);
}

Engine::Shader::~Shader()
{
	glDeleteProgram(_id);
}

int Engine::Shader::GetUniformLocation(std::string name)
{
	auto it = _uniforms.find(name);

	if (it == _uniforms.end())
	{
		auto uniform = glGetUniformLocation(_id, name.c_str());
		_uniforms[name] = uniform;
		return uniform;
	}

	return it->second;
}

GLuint Engine::Shader::CreateShader(GLenum type, const char* path)
{
	GLuint shader = glCreateShader(type);

	std::ifstream file(path);

	if (!file.is_open())
	{
		// TODO: Invalid path, log it
		return 0;
	}

	std::stringstream ss;
	ss << file.rdbuf();
	file.close();
	std::string str = ss.str();
	const char* source = str.c_str();

	glShaderSource(shader, 1, &source, 0);
	glCompileShader(shader);

	int result;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
	if (!result)
	{
		char buf[256];
		glGetShaderInfoLog(shader, 256, 0, buf);
		// TODO: Shader compilation error, log it
		return 0;
	}

	return shader;
}
