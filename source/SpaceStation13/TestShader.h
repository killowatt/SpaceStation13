#pragma once
#include "Shader.h"

class TestShader : public Shader
{
public:
	Texture* Texture;

	void Initialize();
	void Update();

	TestShader(RendererGL* renderer) : Shader(renderer,
		LoadFile("test.v").c_str(), LoadFile("test.f").c_str(),
		ShaderState::Static)
	{
	}
};
