#ifndef VERTEXBUFFER_HEADER
#define VERTEXBUFFER_HEADER

namespace Graphics
{
	class VertexBuffer
	{
	private:
		float* BufferData; // TODO: Are other types essential enough to be represented? NAH FLOATS 4 LYFE
		int BufferSize;
	public:
		unsigned int VertexBufferObject;

		void SetBufferData(float* data, int size);
		float* GetBufferData();
		int GetBufferSize();

		VertexBuffer();
		~VertexBuffer();
	};
}

#endif