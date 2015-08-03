#include "VertexBuffer.h"
#include "GL/glew.h"


#include <iostream>

using namespace Graphics;

void VertexBuffer::SetBufferData(float* data, int size)
{
	delete BufferData;
	BufferData = new float[size];
	BufferSize = size;

	for (int i = 0; i < size; i++)
	{
		BufferData[i] = data[i];
	}

	glBindBuffer(GL_ARRAY_BUFFER, VertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * size, BufferData, GL_STATIC_DRAW); // TODO: add dyn/stat draw options :>
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
float* VertexBuffer::GetBufferData()
{
	float* buffer = new float[BufferSize];
	for (int i = 0; i < BufferSize; i++)
	{
		buffer[i] = BufferData[i];
	}
	return buffer;
}
int VertexBuffer::GetBufferSize()
{
	return BufferSize;
}

VertexBuffer::VertexBuffer()
{
	glGenBuffers(1, &VertexBufferObject);
}
VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &VertexBufferObject);
	delete BufferData;
}