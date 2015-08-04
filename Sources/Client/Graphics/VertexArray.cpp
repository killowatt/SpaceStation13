#include "VertexArray.h"
#include <GL/glew.h>

using namespace Graphics;

void VertexArray::AttachBuffer(VertexBuffer* vertexBuffer, int index)
{
	glBindVertexArray(VertexArrayObject);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer->VertexBufferObject);
	glVertexAttribPointer(index, vertexBuffer->GetVertexSize(), GL_FLOAT, false, 0, 0);
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
	delete IndexBuffer;
	IndexBuffer = new unsigned int[size];
	IndexBufferSize = size;
	for (int i = 0; i < size; i++)
	{
		IndexBuffer[i] = indexBuffer[i];
	}

	glBindVertexArray(VertexArrayObject);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexBufferObject);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * IndexBufferSize, IndexBuffer, GL_STATIC_DRAW);
	glBindVertexArray(0);
}
unsigned int* VertexArray::GetIndexBuffer()
{
	unsigned int* buffer = new unsigned int[IndexBufferSize];
	for (int i = 0; i < IndexBufferSize; i++)
	{
		buffer[i] = IndexBuffer[i];
	}
	return buffer;
}
int VertexArray::GetIndexBufferSize()
{
	return IndexBufferSize;
}
void VertexArray::RemoveIndexBuffer()
{
	delete IndexBuffer;
	IndexBufferSize = 0;

	glBindVertexArray(VertexArrayObject);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &VertexArrayObject);
	glGenBuffers(1, &IndexBufferObject);
	IndexBuffer = nullptr;
}
VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &VertexArrayObject);
	glDeleteBuffers(1, &IndexBufferObject);
}