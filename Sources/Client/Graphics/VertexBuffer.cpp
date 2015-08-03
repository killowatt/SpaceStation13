#include "VertexBuffer.h"
#include "GL/glew.h"


#include <iostream>

using namespace Graphics;

void VertexBuffer::SetBufferData(float* data, int size)
{
	delete bufferData;
	bufferData = new float[size];
	bufferSize = size;

	for (int i = 0; i < size; i++)
	{
		bufferData[i] = data[i];
	}

	glBindBuffer(GL_ARRAY_BUFFER, VertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * size, bufferData, GL_STATIC_DRAW); // TODO: add dyn/stat draw options :>
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
float* VertexBuffer::GetBufferData()
{
	float* buffer = new float[bufferSize];
	for (int i = 0; i < bufferSize; i++)
	{
		buffer[i] = bufferData[i];
	}
	return buffer;
}
int VertexBuffer::GetBufferSize()
{
	return bufferSize;
}

VertexBuffer::VertexBuffer()
{
	glGenBuffers(1, &VertexBufferObject);
}
VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &VertexBufferObject);
	delete bufferData;
}