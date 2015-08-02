#include "VertexArray.h"
#include <GL/glew.h>

using namespace Graphics;

void VertexArray::AttachBuffer(VertexBuffer vertexBuffer, int index)
{
	glBindVertexArray(VertexArrayObject);
	
}
void VertexArray::RemoveBuffer(int index)
{
}

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &VertexArrayObject);
}
VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &VertexArrayObject);
}