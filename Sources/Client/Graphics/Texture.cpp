#include "Texture.h"
#include <GL/glew.h>

using namespace Graphics;

void Texture::SetTexture(unsigned char* data, int size, int width, int height, bool alphaEnabled)
{
	delete Pixels;
	Pixels = new unsigned char[size];
	TextureSize = size;
	Width = width;
	Height = height;
	AlphaEnabled = alphaEnabled;

	for (int i = 0; i < size; i++)
	{
		Pixels[i] = data[i];
	}

	int format = alphaEnabled ? GL_RGBA : GL_RGB;

	glBindTexture(GL_TEXTURE_2D, TextureID);
	glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, Pixels);
	glBindTexture(GL_TEXTURE_2D, TextureID);
}
unsigned char* Texture::GetTexture()
{	
	unsigned char* pixels = new unsigned char[TextureSize];
	for (int i = 0; i < TextureSize; i++)
	{
		pixels[i] = Pixels[i];
	}
	return pixels;
}
int Texture::GetTextureSize()
{
	return TextureSize;
}
int Texture::GetWidth()
{
	return Width;
}
int Texture::GetHeight()
{
	return Height;
}
bool Texture::GetAlphaEnabled()
{
	return AlphaEnabled;
}

Texture::Texture()
{
	glGenTextures(1, &TextureID);
}
Texture::~Texture()
{
	glDeleteTextures(1, &TextureID);
	delete Pixels;
}