#include "Sprite.h"

Sprite::Sprite(RendererGL* renderer, Texture* texture)
{
	Renderer = renderer;
	Image = texture;

	// create vbo, (vao too?)
	// scaling/transform (matrices?)
	// texture workz
}
Sprite::~Sprite()
{
}
