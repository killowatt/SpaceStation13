#include "VertexArray.h"
#include <GL/glew.h>

using namespace Graphics;

void VertexArray::AttachBuffer(VertexBuffer* vertexBuffer, int index)
{
	glBindVertexArray(VertexArrayObject);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer->VertexBufferObject);
	glVertexAttribPointer(index, sizeof(float) * vertexBuffer->GetBufferSize(), GL_FLOAT, false, 0, 0);
	glEnableVertexAttribArray(index);
	glBindVertexArray(0);
}
void VertexArray::RemoveBuffer(int index)
{
	glBindVertexArray(VertexArrayObject);
	glDisableVertexAttribArray(index);
	glBindVertexArray(0);
}

void VertexArray::SetIndexBuffer(unsigned int* indexBuffer, int size)
{

}
unsigned int* GetIndexBuffer()
{
}
void VertexArray::RemoveIndexBuffer()
{
}

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &VertexArrayObject);
	glGenBuffers(1, &IndexBufferObject);
}
VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &VertexArrayObject);
	glDeleteBuffers(1, &IndexBufferObject);
}