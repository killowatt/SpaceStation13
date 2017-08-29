#include "Sprite.h"
#include "GL/glew.h"

static const float VertexData[] = 
{
	0, 0,
	1, 0,
	1, 1,
	0, 1
};
static const float TexCoordData[] =
{
	0, 1,
	1, 1,
	1, 0,
	0, 0
};
const uint32 BUFFER_SIZE = sizeof(VertexData) / sizeof(VertexData[0]);

void Sprite::SetPosition(glm::ivec2 position)
{
	Transform = glm::translate(glm::mat4(1.0f), glm::vec3(position.x, position.y, 0)) *
		glm::scale(glm::mat4(1.0f), glm::vec3(Image->GetWidth(), Image->GetHeight(), 0));
}

uint32 Sprite::GetBufferSize() { return BUFFER_SIZE; }

Sprite::Sprite(RendererGL* renderer, Texture* texture)
{
	Renderer = renderer;
	Image = texture;

	glGenVertexArrays(1, &VertexArray);
	glGenBuffers(1, &VertexBuffer);
	glGenBuffers(1, &TexCoordBuffer);

	glBindVertexArray(VertexArray);

	const uint32 vertexIndex = 0;
	glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexData), VertexData, GL_STATIC_DRAW);
	glVertexAttribPointer(vertexIndex, 2, GL_FLOAT, false, 0, 0);
	glEnableVertexAttribArray(vertexIndex);

	const uint32 texCoordIndex = 1;
	glBindBuffer(GL_ARRAY_BUFFER, TexCoordBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(TexCoordData), TexCoordData, GL_STATIC_DRAW);
	glVertexAttribPointer(texCoordIndex, 2, GL_FLOAT, false, 0, 0);
	glEnableVertexAttribArray(texCoordIndex);

	// create vbo, (vao too?)
	// scaling/transform (matrices?)
	// texture workz
}
Sprite::~Sprite()
{
}
