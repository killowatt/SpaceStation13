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

VertexBuffer::VertexBuffer()
{
	glGenBuffers(1, &VertexBufferObject);
	BufferData = nullptr;
}
VertexBuffer::~VertexBuffer()
{
	//glDeleteBuffers(1, &VertexBufferObject);
	//delete BufferData;
}