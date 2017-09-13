#include "Text.h"
#include "ft2build.h"
#include FT_FREETYPE_H

#include "GL/glew.h"

struct Text::FreeTypeLib
{
	FT_Library Library;
	FT_Face Font;
};

void Text::GetText() const
{
}
void Text::SetText(const std::string& text)
{
	if (!IsValid)
		return;

	uint32 width = 0;
	uint32 height = 0;
	uint32 originDist = 0;
	uint32 negOriginDist = 0;

	const char* string = text.c_str();
	for (int i = 0; i < strlen(string); i++)
	{
		char c = string[i];
		if (FT_Load_Char(FT->Font, c, FT_LOAD_RENDER))
		{
			Log::Print(LogCategory::Warning, "Glyph %s could not be loaded, skipping.", c);
		}

		width += FT->Font->glyph->advance.x >> 6; // bitshift for 1/64th pixel size


		uint32 positiveOriginHeight = FT->Font->glyph->bitmap.rows +
			(FT->Font->glyph->bitmap.rows - FT->Font->glyph->bitmap_top);

		uint32 negativeOriginHeight = FT->Font->glyph->bitmap.rows - FT->Font->glyph->bitmap_top;

		if (FT->Font->glyph->bitmap.rows > FT->Font->glyph->bitmap_top &&
			negOriginDist < negativeOriginHeight)
			negOriginDist = FT->Font->glyph->bitmap.rows - FT->Font->glyph->bitmap_top;
		else if (originDist < positiveOriginHeight)
			originDist = positiveOriginHeight;

	}
	height = originDist + negOriginDist;

	uint8* wowza = new uint8[width * height];
	for (uint32 i = 0; i < width * height; i++)
	{
		wowza[i] = 0;
	}

	TextImage = Renderer->CreateTexture();
	TextImage->SetImage(wowza, width, height, PixelType::Grayscale);

	delete[] wowza;

	uint32 x = 0;
	uint32 y = 0;
	for (int i = 0; i < strlen(string); i++)
	{
		char c = string[i];
		if (FT_Load_Char(FT->Font, c, FT_LOAD_RENDER))
		{
			Log::Print(LogCategory::Warning, "Glyph %s could not be loaded, skipping.", c);
		}

		uint32 _x = x + FT->Font->glyph->bitmap_left;
		uint32 _y = y + (FT->Font->glyph->bitmap.rows - FT->Font->glyph->bitmap_top);

		_y = originDist - FT->Font->glyph->bitmap.rows +
			(FT->Font->glyph->bitmap.rows - FT->Font->glyph->bitmap_top);

		uint32 _w = FT->Font->glyph->bitmap.width;
		uint32 _h = FT->Font->glyph->bitmap.rows;

		//Blit(wowza, width, height, _x, _y, face->glyph->bitmap.buffer, _w, _h);
		glTexSubImage2D(GL_TEXTURE_2D, 0, _x, _y, _w, _h, GL_RED, GL_UNSIGNED_BYTE,
			FT->Font->glyph->bitmap.buffer);



		x += FT->Font->glyph->advance.x >> 6;
	}

	TextSprite = Renderer->CreateSprite(TextImage);
	TextSprite->SetPosition(glm::ivec2(5, 15));
	//sprite->Transform * glm::scale(glm::mat4(1.0), glm::vec3(0.25, 0.25, 0));

	Rendered = true;
}
Text::Text(RendererGL* renderer, const char* fontPath, uint32 fontSize)
{
	Renderer = renderer;
	IsValid = false;

	FT = new FreeTypeLib();
	FT_Error error;

	error = FT_Init_FreeType(&FT->Library);
	if (error)
	{
		Log::Print(LogCategory::Error, "FreeType failed to initialize, code %d", error);
		return;
	}

	error = FT_New_Face(FT->Library, fontPath, 0, &FT->Font);
	if (error)
	{
		Log::Print(LogCategory::Error, "The font %s could not be loaded, code %d",
			fontPath, error);
		return;
	}

	error = FT_Set_Pixel_Sizes(FT->Font, 0, fontSize);
	if (error)
	{
		Log::Print(LogCategory::Error, "Font face failed to size properly, code %d", error);
		return;
	}

	IsValid = true;
}
Text::~Text()
{
	FT_Done_Face(FT->Font);
	FT_Done_FreeType(FT->Library);
	delete FT;
}


//Text::Text(RendererGL* renderer)
//{
//	FT_Library ft;
//	if (FT_Init_FreeType(&ft))
//		Log::Print(LogCategory::Fatal, "Failed to initialize FreeType library.");
//
//	FT_Face face;
//	if (FT_New_Face(ft, "DINRg.ttf", 0, &face))
//		Log::Print(LogCategory::Error, "Font of name %s could not be found.", "NotYetImpl");
//
//	FT_Set_Pixel_Sizes(face, 0, 32);
//
//	//FT_Select_Charmap(face, FT_Encoding::FT_ENCODING_UT
//
//	uint32 width = 0;
//	uint32 height = 0;
//	uint32 originDist = 0;
//	uint32 negOriginDist = 0;
//
//	const char* string = "PLASMA INITIALIZED";
//	for (int i = 0; i < strlen(string); i++)
//	{
//		char c = string[i];
//		if (FT_Load_Char(face, c, FT_LOAD_RENDER))
//		{
//			Log::Print(LogCategory::Warning, "Glyph %s could not be loaded, skipping.", c);
//		}
//
//		width += face->glyph->advance.x >> 6; // bitshift for 1/64th pixel size
//
//
//		uint32 positiveOriginHeight = face->glyph->bitmap.rows +
//			(face->glyph->bitmap.rows - face->glyph->bitmap_top);
//
//		uint32 negativeOriginHeight = face->glyph->bitmap.rows - face->glyph->bitmap_top;
//
//		if (face->glyph->bitmap.rows > face->glyph->bitmap_top &&
//			negOriginDist < negativeOriginHeight)
//			negOriginDist = face->glyph->bitmap.rows - face->glyph->bitmap_top;
//		else if (originDist < positiveOriginHeight)
//			originDist = positiveOriginHeight;
//
//	}
//	height = originDist + negOriginDist;
//
//	uint8* wowza = new uint8[width * height];
//	for (uint32 i = 0; i < width * height; i++)
//	{
//		wowza[i] = 0;
//	}
//
//	Texture* tex = renderer->CreateTexture();
//	tex->SetImage(wowza, width, height, PixelType::Grayscale);
//	
//
//	uint32 x = 0;
//	uint32 y = 0;
//	for (int i = 0; i < strlen(string); i++)
//	{
//		char c = string[i];
//		if (FT_Load_Char(face, c, FT_LOAD_RENDER))
//		{
//			Log::Print(LogCategory::Warning, "Glyph %s could not be loaded, skipping.", c);
//		}
//
//		uint32 _x = x + face->glyph->bitmap_left;
//		uint32 _y = y + (face->glyph->bitmap.rows - face->glyph->bitmap_top);
//
//		_y = originDist - face->glyph->bitmap.rows +
//			(face->glyph->bitmap.rows - face->glyph->bitmap_top);
//
//		uint32 _w = face->glyph->bitmap.width;
//		uint32 _h = face->glyph->bitmap.rows;
//
//		//Blit(wowza, width, height, _x, _y, face->glyph->bitmap.buffer, _w, _h);
//		glTexSubImage2D(GL_TEXTURE_2D, 0, _x, _y, _w, _h, GL_RED, GL_UNSIGNED_BYTE,
//			face->glyph->bitmap.buffer);
//
//		
//
//		x += face->glyph->advance.x >> 6;
//	}
//
//	Sprite* sprite = renderer->CreateSprite(tex);
//	sprite->SetPosition(glm::ivec2(5, 15));
//	//sprite->Transform * glm::scale(glm::mat4(1.0), glm::vec3(0.25, 0.25, 0));
//
//	renderer->Render(sprite);
//}