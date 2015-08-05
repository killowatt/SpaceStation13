#include "VertexBuffer.h"
#include <GL/glew.h>

using namespace Graphics;

void VertexBuffer::SetBufferData(float* data, int dataSize, int vertexSize)
{
	delete BufferData;
	BufferData = new float[dataSize];
	BufferSize = dataSize;
	VertexSize = vertexSize;

	for (int i = 0; i < dataSize; i++)
	{
		BufferData[i] = data[i];
	}

	glBindBuffer(GL_ARRAY_BUFFER, VertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * dataSize, BufferData, GL_STATIC_DRAW); // TODO: add dyn/stat draw options :>
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
int VertexBuffer::GetVertexSize()
{
	return VertexSize;
}

VertexBuffer& VertexBuffer::operator =(VertexBuffer& other)
{
	glDeleteBuffers(1, &VertexBufferObject); // TODO: privatise = operator to prevent copies? (all sim. class)
	delete BufferData;

	VertexBufferObject = other.VertexBufferObject;
	BufferData = other.BufferData;
	BufferSize = other.BufferSize;
	VertexSize = other.VertexSize;

	other.VertexBufferObject = 0;
	other.BufferData = nullptr;

	return *this;
}

VertexBuffer::VertexBuffer()
{
	glGenBuffers(1, &VertexBufferObject);
	BufferData = nullptr;
}
VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &VertexBufferObject);
	delete BufferData;
}