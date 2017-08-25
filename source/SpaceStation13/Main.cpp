//SDL2 flashing random color example
//Should work on iOS/Android/Mac/Windows/Linux

#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"

#include <stdlib.h> //rand()
#include <string>
#include <iostream>


#include <stdio.h>
#include <string.h>



#include <iostream>
#include <fstream> 
#include <string>
#include <sstream>

#include "RendererGL.h"
#include "Texture.h"
#include "TestShader.h"

static bool quitting = false;

float rt = 0.0f;

RendererGL* renderer;
Texture* textur;
Sprite* spri;

TestShader* shad;

void render() {

		//First clear the renderer

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);




		renderer->Render(spri);


		renderer->SwapBuffers();
} //render


int SDLCALL watch(void *userdata, SDL_Event* event) {

	if (event->type == SDL_APP_WILLENTERBACKGROUND) {
		quitting = true;
	}

	return 1;
}

int main()
{



	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
		SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
		return 1;
	}

	SDL_AddEventWatch(watch, NULL);


	renderer = new RendererGL();
	renderer->Initialize();

	textur = renderer->CreateTexture();

	spri = new Sprite(renderer, textur);

	shad = new TestShader(renderer);


	shad->Initialize();


	if (!shad->GetCompileResult(ShaderType::Pixel) ||
		!shad->GetCompileResult(ShaderType::Vertex))
		return 1; // TODO:


	renderer->SetShader(shad);


	while (!quitting) {

		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quitting = true;
			}
		}

		render();

	}

	SDL_DelEventWatch(watch, NULL);
	SDL_Quit();

} //main