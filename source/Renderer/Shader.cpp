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
	glUseProgram(ShaderProgram);

	int32 modelLocation = glGetUniformLocation(ShaderProgram, "Model");
	int32 viewLocation = glGetUniformLocation(ShaderProgram, "View");
	int32 projectionLocation = glGetUniformLocation(ShaderProgram, "Projection");

	glm::mat4 view = Renderer->GetCamera().GetView();
	glm::mat4 projection = Renderer->GetCamera().GetProjection();

	if (modelLocation > -1)
		glUniformMatrix4fv(modelLocation, 1, false, &transform[0][0]);
	if (viewLocation > -1)
		glUniformMatrix4fv(viewLocation, 1, false, &view[0][0]);
	if (projectionLocation > -1)
		glUniformMatrix4fv(projectionLocation, 1, false, &projection[0][0]);
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