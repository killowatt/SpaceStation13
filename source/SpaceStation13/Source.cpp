//SDL2 flashing random color example
//Should work on iOS/Android/Mac/Windows/Linux

#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"

#include <stdlib.h> //rand()
#include <string>

static bool quitting = false;
static float r = 0.0f;
static SDL_Window *window = NULL;
static SDL_GLContext gl_context;

SDL_Renderer* ren;
SDL_Texture* tex;
float rt = 0.0f;

void render() {


		//First clear the renderer
		SDL_GL_MakeCurrent(window, gl_context);

		glClear(GL_COLOR_BUFFER_BIT);

		glLoadIdentity();


		glRotatef(rt, 0, 0, 1);
		glRotatef(rt, 1, 0, 0);
		glScalef(0.5f, 0.5f, 0.5f);
		rt += 0.5f;

		float* x = new float(64);
		SDL_GL_BindTexture(tex, x, x);

		glBegin(GL_TRIANGLE_STRIP);

		float rp = 4;

		glTexCoord2f(0.0, 0.0);
		glVertex2f(-1.0, -1.0);

		glTexCoord2f(rp, 0.0);
		glVertex2f(1.0, -1.0);

		glTexCoord2f(0.0, rp);
		glVertex2f(-1.0, 1.0);

		glTexCoord2f(rp, rp);
		glVertex2f(1.0, 1.0);

		glEnd();

		SDL_GL_SwapWindow(window);
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

	window = SDL_CreateWindow("title", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 512, 512, SDL_WINDOW_OPENGL);

	gl_context = SDL_GL_CreateContext(window);

	SDL_AddEventWatch(watch, NULL);


	ren = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
	SDL_Surface *bmp = SDL_LoadBMP("test.png");
	tex = SDL_CreateTextureFromSurface(ren, bmp);
	//SDL_FreeSurface(bmp);




	while (!quitting) {

		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quitting = true;
			}
		}

		render();
		SDL_Delay(2);

	}

	SDL_DelEventWatch(watch, NULL);
	SDL_GL_DeleteContext(gl_context);
	SDL_DestroyWindow(window);
	SDL_Quit();

	exit(0);

} //main