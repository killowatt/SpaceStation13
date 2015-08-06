#ifndef VERTEXARRAY_HEADER
#define VERTEXARRAY_HEADER

#include "VertexBuffer.h"

namespace Graphics
{
	class VertexArray
	{
	private:
		unsigned int* IndexBuffer;
		int IndexBufferSize;
		bool IndexBufferEnabled; // TODO: implement
	public:
		unsigned int VertexArrayObject;
		unsigned int IndexBufferObject;

		void AttachBuffer(VertexBuffer* vertexBuffer, int index);
		void RemoveBuffer(int index);

		void SetIndexBuffer(unsigned int* indexBuffer, int size); // TODO: should we have a seperate class?
		unsigned int* GetIndexBuffer();
		int GetIndexBufferSize();
		void RemoveIndexBuffer();

	private:
		void operator =(VertexArray& other) = delete;
		VertexArray(const VertexArray&) = delete;

	public:
		VertexArray();
		~VertexArray();
	};
}

#endif