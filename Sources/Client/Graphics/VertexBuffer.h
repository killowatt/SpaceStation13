#ifndef VERTEXBUFFER_HEADER
#define VERTEXBUFFER_HEADER

namespace Graphics
{
	class VertexBuffer
	{
	private:
		float* BufferData; // TODO: Are other types essential enough to be represented? NAH FLOATS 4 LYFE
		int BufferSize;
		int VertexSize;
	public:
		unsigned int VertexBufferObject; // TODO: rename this and similar class' to xID?

		void SetBufferData(float* data, int dataSize, int vertexSize);
		float* GetBufferData();
		int GetBufferSize();
		int GetVertexSize();

	private:
		void operator =(VertexBuffer& other) = delete;
		VertexBuffer(const VertexBuffer&) = delete;

	public:
		VertexBuffer();
		~VertexBuffer();
	};
}

#endif