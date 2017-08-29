#pragma once
#include "Core.h"
#include "RendererGL.h"
#include "glm/mat4x4.hpp"
#include <string>

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
class RendererGL;
class Shader : NonCopyable
{
private:
	RendererGL* Renderer;

	friend class RendererGL;
	virtual void Update() = 0;
protected:
	uint32 ShaderProgram;
	uint32 VertexShader;
	uint32 PixelShader;

	ShaderState State;

	//void SetUniform(const char* name, uint32 texture);

	std::string LoadFile(const char* fileName);

public:
	virtual void Initialize();
	void UploadTransform(const glm::mat4& transform);

	ShaderState GetShaderState() { return State; }
	bool GetCompileResult(ShaderType type);
	const char* GetCompileLog(ShaderType type);

	uint32 GetProgram() { return ShaderProgram; }

protected:
	Shader(RendererGL* renderer, const char* vertexSource, const char* pixelSource,
		ShaderState state);
	~Shader(); // TODO: what do we do with this under protected?
};