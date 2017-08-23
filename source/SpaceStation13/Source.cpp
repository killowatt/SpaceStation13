//SDL2 flashing random color example
//Should work on iOS/Android/Mac/Windows/Linux

#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"

#include <stdlib.h> //rand()
#include <string>
#include <iostream>


#include <stdio.h>
#include <string.h>

extern "C" {
#include <Lua/lua.h>
#include <Lua/lauxlib.h>
#include <Lua/lualib.h>
}

#include <iostream>
#include <fstream> 
#include <string>
#include <sstream>

#include "RendererGL.h"
#include "Texture.h"

static bool quitting = false;

float rt = 0.0f;

RendererGL* renderer;
Texture* textur;

void render() {


		//First clear the renderer

		glClear(GL_COLOR_BUFFER_BIT);

		glLoadIdentity();


		glRotatef(rt, 0, 0, 1);
		glRotatef(rt, 1, 0, 0);
		glScalef(0.5f, 0.5f, 0.5f);
		rt += 0.5f;

		glBindTexture(GL_TEXTURE_2D, textur->GetTextureID());

		glEnable(GL_TEXTURE_2D); // HEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEY
		// THIS MIGHT BE IMPORTANT

		std::cout << glGetError() << "\n";
		std::cout << "ERROR?";

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


	//int status, result, i;
	//double sum;
	//lua_State *L;

	///*
	//* All Lua contexts are held in this structure. We work with it almost
	//* all the time.
	//*/
	//L = luaL_newstate();

	//luaL_openlibs(L); /* Load Lua libraries */

	//				  /* Load the file containing the script we are going to run */
	//status = luaL_loadfile(L, "script.lua");
	//if (status) {
	//	/* If something went wrong, error message is at the top of */
	//	/* the stack */
	//	fprintf(stderr, "Couldn't load file: %s\n", lua_tostring(L, -1));
	//	std::getchar();
	//	exit(1);
	//}

	///*
	//* Ok, now here we go: We pass data to the lua script on the stack.
	//* That is, we first have to prepare Lua's virtual stack the way we
	//* want the script to receive it, then ask Lua to run it.
	//*/
	//lua_newtable(L);    /* We will pass a table */

	//					/*
	//					* To put values into the table, we first push the index, then the
	//					* value, and then call lua_rawset() with the index of the table in the
	//					* stack. Let's see why it's -3: In Lua, the value -1 always refers to
	//					* the top of the stack. When you create the table with lua_newtable(),
	//					* the table gets pushed into the top of the stack. When you push the
	//					* index and then the cell value, the stack looks like:
	//					*
	//					* <- [stack bottom] -- table, index, value [top]
	//					*
	//					* So the -1 will refer to the cell value, thus -3 is used to refer to
	//					* the table itself. Note that lua_rawset() pops the two last elements
	//					* of the stack, so that after it has been called, the table is at the
	//					* top of the stack.
	//					*/
	//for (i = 1; i <= 5; i++) {
	//	lua_pushnumber(L, i);   /* Push the table index */
	//	lua_pushnumber(L, i * 2); /* Push the cell value */
	//	lua_rawset(L, -3);      /* Stores the pair in the table */
	//}

	///* By what name is the script going to reference our table? */
	//lua_setglobal(L, "foo");

	///* Ask Lua to run our little script */
	//result = lua_pcall(L, 0, LUA_MULTRET, 0);
	//if (result) {
	//	fprintf(stderr, "Failed to run script: %s\n", lua_tostring(L, -1));
	//	exit(1);
	//}

	///* Get the returned value at the top of the stack (index -1) */
	//sum = lua_tonumber(L, -1);

	//printf("Script returned: %.0f\n", sum);

	//lua_pop(L, 1);  /* Take the returned value out of the stack */
	//lua_close(L);   /* Cya, Lua */

	//std::cout << "script test completed\n";
	//std::getchar();


	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
		SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
		return 1;
	}

	SDL_AddEventWatch(watch, NULL);


	renderer = new RendererGL();
	renderer->Initialize();

	textur = renderer->CreateTexture();

	glClearColor(0.05f, 0.05f, 0.05f, 1.0f);

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
	//SDL_GL_DeleteContext(gl_context);
	//SDL_DestroyWindow(window);
	SDL_Quit();

	exit(0);

} //main