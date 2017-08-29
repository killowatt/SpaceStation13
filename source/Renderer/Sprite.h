#pragma once
#include "Core.h"
#include "RendererGL.h"
#include "Texture.h"

#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/vec2.hpp"

class RendererGL;
class Texture;
class Sprite : NonCopyable
{
private:
	RendererGL* Renderer;
	Texture* Image;

	uint32 VertexArray;
	uint32 VertexBuffer;
	uint32 TexCoordBuffer;

public:
	glm::mat4 Transform;

	Texture* GetTexture() { return Image; }

	uint32 GetVertexArrayObject() { return VertexArray; }
	uint32 GetBufferSize();

	void SetPosition(glm::ivec2 position);

	Sprite(RendererGL* renderer, Texture* texture);
	~Sprite();
};