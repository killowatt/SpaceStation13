#ifndef VERTEXARRAY_HEADER
#define VERTEXARRAY_HEADER

#include "VertexBuffer.h"

namespace Graphics
{
	class VertexArray
	{
	private:
		bool IndexBufferEnabled;
		unsigned int* IndexBuffer;
		int IndexBufferSize;
	public:
		unsigned int VertexArrayObject;
		unsigned int IndexBufferObject;

		void AttachBuffer(VertexBuffer* vertexBuffer, int index);
		void RemoveBuffer(int index);

		void SetIndexBuffer(unsigned int* indexBuffer, int size); // TODO: should we have a seperate class?
		unsigned int* GetIndexBuffer();
		int GetIndexBufferSize();
		void RemoveIndexBuffer();

		VertexArray();
		~VertexArray();
	};
}

#endif