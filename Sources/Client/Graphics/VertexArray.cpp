#include "VertexArray.h"
#include <GL/glew.h>

using namespace Graphics;

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &VertexArrayObject);

}