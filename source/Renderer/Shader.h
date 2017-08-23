#pragma once
#include "Engine.h"
#include "RendererGL.h"
#include "glm/mat4x4.hpp"

enum class ShaderType
{
	Vertex,
	Pixel
};
enum class ShaderState
{
	Static,
	Dynamic,
	Framebuffer // maybe we dont need it
};
class Shader : NonCopyable
{
private:
	RendererGL* Renderer;

	uint32 ShaderProgram;
	uint32 VertexShader;
	uint32 PixelShader;

	ShaderState State;

	glm::mat4 Model;
	glm::mat4 View;
	glm::mat4 Projection;

public:
	virtual void Initialize() = 0;
	virtual void Update() = 0;

	bool GetCompileResult(ShaderType type);
	const char* GetCompileLog(ShaderType type);

	Shader(RendererGL* renderer, const char* vertexSource, const char* pixelSource,
		ShaderState state);
	~Shader();
};