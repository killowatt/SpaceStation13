#include "Shader.h"
#include "GL/glew.h"

// for shader txt loader
#include <string>
#include <fstream>
#include <iostream>


void Shader::Initialize()
{
	// TODO: renderer check call here maybe?
	glUseProgram(ShaderProgram);
}
void Shader::UploadTransform(const glm::mat4& transform)
{
	glm::mat4 scaley = glm::scale(glm::mat4(1.0f), glm::vec3(2, 2, 0)) * transform;

	glUseProgram(ShaderProgram);
	int32 location = glGetUniformLocation(ShaderProgram, "Model");
	if (location > -1)
		glUniformMatrix4fv(location, 1, false, &scaley[0][0]);


	int32 x = glGetUniformLocation(ShaderProgram, "View");
	int32 y = glGetUniformLocation(ShaderProgram, "Projection");

	glm::mat4 xx = glm::translate(glm::mat4(1.0f), glm::vec3(0.0, 0.0, 0.0));
	xx = glm::mat4(1.0f);
	glm::mat4 yy = glm::ortho(0.0f, 512.0f, 512.0f, 0.0f, 0.0f, 1.0f);

	xx = Renderer->GetCamera().GetView();
	yy = Renderer->GetCamera().GetProjection();

	glUniformMatrix4fv(x, 1, false, &xx[0][0]);
	glUniformMatrix4fv(y, 1, false, &yy[0][0]);
}

//void Shader::SetUniform(const char* name, uint32 texture)
//{
//	uint32 location = glGetUniformLocation(ShaderProgram, name);
//	glUniform1i(location, texture);
//}

bool Shader::GetCompileResult(ShaderType type)
{
	int32 result;
	uint32 targetShader;

	switch (type)
	{
	default:
	case ShaderType::Vertex:
		targetShader = VertexShader;
		break;
	case ShaderType::Pixel:
		targetShader = PixelShader;
		break;
	}
	glGetShaderiv(targetShader, GL_COMPILE_STATUS, &result);
	return result;
}
const char* Shader::GetCompileLog(ShaderType type)
{
	char* buffer = nullptr;
	int32 bufferSize;
	uint32 targetShader;

	switch (type)
	{
	default:
	case ShaderType::Vertex:
		targetShader = VertexShader;
		break;
	case  ShaderType::Pixel:
		targetShader = PixelShader;
		break;
	}
	glGetShaderiv(targetShader, GL_INFO_LOG_LENGTH, &bufferSize);
	buffer = new char[bufferSize + 1];
	glGetShaderInfoLog(targetShader, bufferSize, 0, buffer);
	return buffer;
}

std::string Shader::LoadFile(const char* fileName) // TODO:  redo this garbage
{
	std::string file;
	std::ifstream fileStream(fileName, std::ios::in);
	if (fileStream.is_open())
	{
		std::string line = "";
		while (getline(fileStream, line))
			file += "\n" + line;
		fileStream.close();
		return file;
	}
	throw std::exception("stop");
}

Shader::Shader(RendererGL* renderer, const char* vertexSource, const char* pixelSource,
	ShaderState state)
{
	Renderer = renderer;
	State = state;

	if (!Renderer)
		return; // TODO: error

	VertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(VertexShader, 1, &vertexSource, nullptr);
	glCompileShader(VertexShader);

	PixelShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(PixelShader, 1, &pixelSource, nullptr);
	glCompileShader(PixelShader);

	ShaderProgram = glCreateProgram();
	glAttachShader(ShaderProgram, VertexShader);
	glAttachShader(ShaderProgram, PixelShader);

	glBindAttribLocation(ShaderProgram, 0, "vertex");
	glBindAttribLocation(ShaderProgram, 1, "textureCoordinate");

	glLinkProgram(ShaderProgram);
}
Shader::~Shader()
{
	// TODO: my god do the damn deleters for these classes
}