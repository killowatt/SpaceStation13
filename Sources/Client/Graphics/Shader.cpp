#include "Shader.h"
#include <GL/glew.h>

using namespace Graphics;

bool Shader::GetCompileStatus(ShaderType shaderType)
{
	int result;
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
	int logLength;
	glGetShaderiv(ShaderProgram, GL_INFO_LOG_LENGTH, &logLength);
	char* log = new char[logLength];
	glGetShaderInfoLog(ShaderProgram, *log, nullptr, log);
	return log;
} 

Shader::Shader()
{
}
Shader::Shader(const char* vertexShader, const char*fragmentShader)
{
	// TODO: if vertex/frag is null, error or replace with emptystring

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
	glDeleteShader(VertexShader);
	glDeleteShader(FragmentShader);
	glDeleteProgram(ShaderProgram);
}