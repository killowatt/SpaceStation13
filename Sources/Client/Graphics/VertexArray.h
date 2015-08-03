#ifndef VERTEXARRAY_HEADER
#define VERTEXARRAY_HEADER

#include "VertexBuffer.h"

namespace Graphics
{
	class VertexArray
	{
	public:
		unsigned int VertexArrayObject;

		void AttachBuffer(VertexBuffer* vertexBuffer, int index);
		void SetIndexBuffer(unsigned int* indexBuffer, int size);
		void RemoveBuffer(int index);

		VertexArray();
		~VertexArray();
	};
}

#endif