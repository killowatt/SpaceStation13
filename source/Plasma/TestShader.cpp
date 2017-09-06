#include "TestShader.h"
#include "GL/glew.h"

void TestShader::Initialize()
{
	Shader::Initialize(); // required

	if (Texture)
	{
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, Texture->GetTextureID());
		glUniform1i(glGetUniformLocation(ShaderProgram, "Texture"), 0);
	}
}
void TestShader::Update()
{
}

