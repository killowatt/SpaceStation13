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
	private:
		unsigned char* Pixels;
		int TextureSize;
		int Width;
		int Height;
		bool AlphaEnabled;
	public:
		unsigned int TextureID;

		void SetTexture(unsigned char* pixels, int size, int width, int height, bool alphaEnabled);
		unsigned char* GetTexture();
		int GetTextureSize();
		int GetWidth();
		int GetHeight();
		bool GetAlphaEnabled();

		Texture();
		~Texture();
	};
}

#endif