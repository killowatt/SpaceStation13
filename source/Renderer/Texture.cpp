#include "Texture.h"
#include "GL/glew.h"
#include "lodepng.h"

void Texture::LoadFromFile(const char* fileName)
{
	std::vector<uint8> image;
	uint32 width = 0, height = 0;

	lodepng::decode(image, width, height, fileName);

	glBindTexture(GL_TEXTURE_2D, TextureID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE,
		image.data());
}

Texture::Texture(RendererGL* renderer, uint32 textureID)
{
	Renderer = renderer;
	TextureID = textureID;

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}