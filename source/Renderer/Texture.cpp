#include "Texture.h"
#include "GL/glew.h"
#include "lodepng.h"

void Texture::LoadFromFile(const char* fileName)
{
	std::vector<uint8> image;

	lodepng::decode(image, Width, Height, fileName);

	glBindTexture(GL_TEXTURE_2D, TextureID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, Width, Height, 0, GL_RGBA, GL_UNSIGNED_BYTE,
		image.data());
}

Texture::Texture(RendererGL* renderer)
{
	Renderer = renderer; // TODO: set default widht and height for emptytexture

	if (!Renderer)
		return; // TODO: error

	// TODO: we need to check if the renderer above is the current context. if otherwise,
	// we need to either error or do it ourself. consider code repetition (for erry rendaclass)

	glGenTextures(1, &TextureID);
	glBindTexture(GL_TEXTURE_2D, TextureID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
}