#include "Shader.h"
#include <GL/glew.h>

#include <iostream>

using namespace Graphics;

bool Shader::GetCompileStatus(ShaderType shaderType)
{
	int result = 0;
	if (shaderType == ShaderType::Fragment)
	{
		glGetShaderiv(FragmentShader, GL_COMPILE_STATUS, &result);
	}
	else
	{
		glGetShaderiv(VertexShader, GL_COMPILE_STATUS, &result);
	}

	return result != 0;
}
char* Shader::GetCompileLog(ShaderType shaderType)
{
	int logLength = 0;
	char* log = nullptr;

	if (shaderType == ShaderType::Fragment)
	{
		glGetShaderiv(FragmentShader, GL_INFO_LOG_LENGTH, &logLength);
	}
	else
	{
		glGetShaderiv(VertexShader, GL_INFO_LOG_LENGTH, &logLength);
	}

	if (logLength > 0)
	{
		log = new char[logLength];
		if (shaderType == ShaderType::Fragment)
		{
			glGetShaderInfoLog(FragmentShader, logLength, nullptr, log);
		}
		else
		{
			glGetShaderInfoLog(VertexShader, logLength, nullptr, log);
		}
	}
	else
	{
		log = "";
	}
	return log;
} 

Shader& Shader::operator =(Shader& other)
{
	if (ShaderProgram > 0)
	{
		glDetachShader(ShaderProgram, VertexShader);
		glDetachShader(ShaderProgram, FragmentShader);
		glDeleteProgram(ShaderProgram);
	}
	if (VertexShader > 0) glDeleteShader(VertexShader);
	if (FragmentShader > 0) glDeleteShader(FragmentShader);

	ShaderProgram = other.ShaderProgram;
	VertexShader = other.VertexShader; 
	FragmentShader = other.FragmentShader; // TODO: should we copy matrices?

	other.ShaderProgram = 0;
	other.VertexShader = 0;
	other.FragmentShader = 0;

	return *this;
}

Shader::Shader()
{
}
Shader::Shader(const char* vertexShader, const char* fragmentShader)
{
	// TODO: if vertex/frag is null, error or replace with emptystring?
	VertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(VertexShader, 1, &vertexShader, nullptr);
	glCompileShader(VertexShader);

	FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(FragmentShader, 1, &fragmentShader, nullptr);
	glCompileShader(FragmentShader);

	ShaderProgram = glCreateProgram();
	glAttachShader(ShaderProgram, VertexShader);
	glAttachShader(ShaderProgram, FragmentShader);

	glLinkProgram(ShaderProgram);
}
Shader::~Shader()
{
	if (ShaderProgram > 0)
	{
		glDetachShader(ShaderProgram, VertexShader);
		glDetachShader(ShaderProgram, FragmentShader);
		glDeleteProgram(ShaderProgram);
	}
	if (VertexShader > 0) glDeleteShader(VertexShader);
	if (FragmentShader > 0) glDeleteShader(FragmentShader);
}