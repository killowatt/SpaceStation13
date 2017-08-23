#include "Shader.h"
#include "GL/glew.h"

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

Shader::Shader(RendererGL* renderer, const char* vertexSource, const char* pixelSource,
	ShaderState state)
{
	Renderer = renderer;

	if (!Renderer)
		return; // TODO: error

	VertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(GL_VERTEX_SHADER, 1, &vertexSource, nullptr);
	glCompileShader(VertexShader);

	PixelShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(GL_FRAGMENT_SHADER, 1, &pixelSource, nullptr);
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