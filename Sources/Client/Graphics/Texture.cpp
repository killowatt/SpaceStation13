#include "Texture.h"
#include <GL/glew.h>

using namespace Graphics;

Texture::Texture()
{
	glGenTextures(1, &TextureID);
	
}