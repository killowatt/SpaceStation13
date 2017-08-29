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


#include "JSRT/ChakraCore.h"
#include <vector>


#define FAIL_CHECK(cmd)                     \
    do                                      \
    {                                       \
        JsErrorCode errCode = cmd;          \
        if (errCode != JsNoError)           \
        {                                   \
            printf("Error %d at '%s'\n",    \
                errCode, #cmd);             \
            return 1;                       \
        }                                   \
    } while(0)

using namespace std;

static bool quitting = false;

float rt = 0.0f;

RendererGL* renderer;
Texture* textur;
Sprite* spri;

TestShader* shad;

//std::vector<Sprite> mapz;
bool initrm;


float x;
float y;
float time;

void render() {
	if (!initrm)
	{
		//mapz = std::vector<Sprite>(4 * 4, Sprite(renderer, textur));



		initrm = true;
	}
		//First clear the renderer

	//std::cout << "ERROR --> " << glGetError() << "\n";

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		time += 0.05f;
		x = glm::cos(time);
		y = glm::sin(time);
		//spri->Transform = glm::translate(glm::mat4(1.0f), glm::vec3(100, 100, 0))
		//	* glm::scale(glm::mat4(1.0f), glm::vec3(50, 50, 0));

		spri->SetPosition(glm::vec2(x * 15 + 100, y * 15 + 100));

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

	JsRuntimeHandle runtime;
	JsContextRef context;
	JsValueRef result;
	unsigned currentSourceContext = 0;

	const char* script = "(()=>{return \'SPACE STATION 13 INTERFACE\';})()";
	size_t length = strlen(script);

	// Create a runtime.
	JsCreateRuntime(JsRuntimeAttributeNone, nullptr, &runtime);

	// Create an execution context.
	JsCreateContext(runtime, &context);

	// Now set the current execution context.
	JsSetCurrentContext(context);

	JsValueRef fname;
	FAIL_CHECK(JsCreateString("sample", strlen("sample"), &fname));

	JsValueRef scriptSource;
	FAIL_CHECK(JsCreateString(script, length, &scriptSource));

	// Run the script.
	FAIL_CHECK(JsRun(scriptSource, currentSourceContext++, fname,
		JsParseScriptAttributeNone, &result));

	// Convert your script result to String in JavaScript; redundant if your script returns a String
	JsValueRef resultJSString;
	FAIL_CHECK(JsConvertValueToString(result, &resultJSString));

	// Project script result back to C++.
	char *resultSTR = nullptr;
	size_t stringLength;
	FAIL_CHECK(JsCopyString(resultJSString, nullptr, 0, 0, &stringLength));
	resultSTR = (char*)malloc(stringLength + 1);
	FAIL_CHECK(JsCopyString(resultJSString, resultSTR, stringLength + 1, 0, nullptr));
	resultSTR[stringLength] = 0;

	printf("Result -> %s \n", resultSTR);
	free(resultSTR);
 
	// Dispose runtime
	JsSetCurrentContext(JS_INVALID_REFERENCE);
	JsDisposeRuntime(runtime);

	//return 0;

	//return 1;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
		SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
		return 1;
	}

	SDL_AddEventWatch(watch, NULL);


	renderer = new RendererGL();
	renderer->Initialize();

	textur = renderer->CreateTexture();
	textur->LoadFromFile("test.png");

	spri = new Sprite(renderer, textur);

	shad = new TestShader(renderer);
	shad->Texture = textur;
	shad->Initialize();


	if (!shad->GetCompileResult(ShaderType::Pixel))
		int iiiii = 0;

	std::cout << "PIXEL --> " << shad->GetCompileLog(ShaderType::Pixel) << "\n";

	if (!shad->GetCompileResult(ShaderType::Vertex))
		int iiiiii = 1;

	std::cout << "VERTEX --> " << shad->GetCompileLog(ShaderType::Vertex) << "\n";

	renderer->SetShader(shad);

	std::cout << "ERROR --> " << glGetError() << "\n";

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