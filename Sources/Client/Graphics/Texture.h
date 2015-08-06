#ifndef TEXTURE_HEADER
#define TEXTURE_HEADER

namespace Graphics
{
	//class enum Filter
	//{
			// Is this needed?
	//}
	class Texture
	{
	public:
		unsigned int TextureID;

	private:
		unsigned char* Pixels;
		int TextureSize;
		unsigned int Width;
		unsigned int Height;
		bool AlphaEnabled;

	public:
		void SetTexture(unsigned char* pixels, int size, unsigned int width, unsigned int height, bool alphaEnabled);
		unsigned char* GetTexture();
		int GetTextureSize();
		int GetWidth();
		int GetHeight();
		bool GetAlphaEnabled();

	private:
		Texture& operator =(Texture texture);

	public:
		Texture();
		~Texture();
	};
}

#endif