#pragma once
#include "Shader.h"

class TestShader : public Shader
{
public:
	void Initialize()
	{
		Shader::Initialize(); // required
	}
	void Update()
	{
	}

	TestShader(RendererGL* renderer) : Shader(renderer,
		LoadFile("test.v").c_str(), LoadFile("test.f").c_str(),
		ShaderState::Static)
	{
	}
};
