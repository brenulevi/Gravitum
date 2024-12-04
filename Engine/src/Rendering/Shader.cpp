#include "Shader.h"

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

	// TODO: Check if program was successful linked

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
	// TODO: Create and compile shader, check if compilation was success;
	return 0;
}
