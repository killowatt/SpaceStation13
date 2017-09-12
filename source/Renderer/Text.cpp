#include "Text.h"
#include "ft2build.h"
#include FT_FREETYPE_H

#include "GL/glew.h"

//void Blit(uint8* destination, uint32 destWidth, uint32 destHeight, uint32 destX, uint32 destY,
//	uint8* source, uint32 sourceWidth, uint32 sourceHeight)
//{
//	if (destWidth < sourceWidth + destX || destHeight < sourceHeight + destY)
//	{
//		Log::Print(LogCategory::Warning, "Failed to blit character because it was 2big :((");
//		return;
//	}
//
//	for (int x = 0; x < destWidth; x++)
//	{
//		for (int y = 0; y < destHeight; y++)
//		{
//			destination[destWidth * (destY + y) + (destX + x)] = source[sourceWidth * y + x];
//		}
//	}
//}

void Text::GetText() const
{
}
void Text::SetText(const std::string& text)
{
}
Text::Text(RendererGL* renderer)
{
	FT_Library ft;
	if (FT_Init_FreeType(&ft))
		Log::Print(LogCategory::Fatal, "Failed to initialize FreeType library.");

	FT_Face face;
	if (FT_New_Face(ft, "impact.ttf", 0, &face))
		Log::Print(LogCategory::Error, "Font of name %s could not be found.", "NotYetImpl");

	FT_Set_Pixel_Sizes(face, 0, 32);

	//FT_Select_Charmap(face, FT_Encoding::FT_ENCODING_UT

	uint32 width = 0;
	uint32 height = 0;
	uint32 originDist = 0;
	uint32 negOriginDist = 0;

	const char* string = "Griffing Greyshirt";
	for (int i = 0; i < strlen(string); i++)
	{
		char c = string[i];
		if (FT_Load_Char(face, c, FT_LOAD_RENDER))
		{
			Log::Print(LogCategory::Warning, "Glyph %s could not be loaded, skipping.", c);
		}

		width += face->glyph->advance.x >> 6; // bitshift for 1/64th pixel size


		uint32 positiveOriginHeight = face->glyph->bitmap.rows +
			(face->glyph->bitmap.rows - face->glyph->bitmap_top);

		uint32 negativeOriginHeight = face->glyph->bitmap.rows - face->glyph->bitmap_top;

		if (face->glyph->bitmap.rows > face->glyph->bitmap_top &&
			negOriginDist < negativeOriginHeight)
			negOriginDist = face->glyph->bitmap.rows - face->glyph->bitmap_top;
		else if (originDist < positiveOriginHeight)
			originDist = positiveOriginHeight;

	}
	height = originDist + negOriginDist;

	uint8* wowza = new uint8[width * height];
	for (uint32 i = 0; i < width * height; i++)
	{
		wowza[i] = 0;
	}

	Texture* tex = renderer->CreateTexture();
	tex->SetImage(wowza, width, height, PixelType::Grayscale);
	

	uint32 x = 0;
	uint32 y = 0;
	for (int i = 0; i < strlen(string); i++)
	{
		char c = string[i];
		if (FT_Load_Char(face, c, FT_LOAD_RENDER))
		{
			Log::Print(LogCategory::Warning, "Glyph %s could not be loaded, skipping.", c);
		}

		uint32 _x = x + face->glyph->bitmap_left;
		uint32 _y = y + (face->glyph->bitmap.rows - face->glyph->bitmap_top);

		_y = originDist - face->glyph->bitmap.rows +
			(face->glyph->bitmap.rows - face->glyph->bitmap_top);

		uint32 _w = face->glyph->bitmap.width;
		uint32 _h = face->glyph->bitmap.rows;

		//Blit(wowza, width, height, _x, _y, face->glyph->bitmap.buffer, _w, _h);
		glTexSubImage2D(GL_TEXTURE_2D, 0, _x, _y, _w, _h, GL_RED, GL_UNSIGNED_BYTE,
			face->glyph->bitmap.buffer);

		

		x += face->glyph->advance.x >> 6;
	}

	Sprite* sprite = renderer->CreateSprite(tex);
	sprite->SetPosition(glm::ivec2(5, 15));
	sprite->Transform * glm::scale(glm::mat4(1.0), glm::vec3(0.25, 0.25, 0));

	renderer->Render(sprite);
}