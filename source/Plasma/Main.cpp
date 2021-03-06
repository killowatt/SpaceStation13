// we lcome to the end zone
// c49x14

#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"

#include <stdlib.h> //rand()
#include <string>
#include <iostream>


#include <stdio.h>
#include <string.h>

#include "Engine.h"

#include <iostream>
#include <fstream> 
#include <string>
#include <sstream>

#include "RendererGL.h"
#include "Texture.h"
#include "TestShader.h"

#include "Server.h"

#include "MapRenderer.h"

#include <vector>

#include "Text.h"

#include "Script/Script.h"
#include "ChakraCore.h"

#include "Entity.h"

#include <set>

#include "Components/SpriteComponent.h"
#include <algorithm> // NEEDED FOR STD::FIND

using namespace std;

static bool quitting = false;

float rt = 0.0f;

RendererGL* renderer;
Texture* textur;
Sprite* spri;

TestShader* shad;

Camera cam(768, 768);

MapRenderer* mrenda;
//GameMap xyhz(8, 8);

//std::vector<Sprite> mapz;
bool initrm;

TextRenderer* txt;

float x;
float y;
float time;

void render() {
	if (!initrm)
	{
		//mapz = std::vector<Sprite>(4 * 4, Sprite(renderer, textur));


		//mrenda = new MapRenderer(&xyhz, renderer);

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

		cam.SetPosition((int)(x * 32), (int)(y * 16));
		cam.SetPosition(64, 64);

		spri->SetPosition(glm::vec2(x * 15 + 100, y * 15 + 100));

		//renderer->Render(spri);

		renderer->Render(txt->GetSprite());

		mrenda->TestRender();

		std::cout << "ERROR --> " << glGetError() << "\n";


		renderer->SwapBuffers();

		std::cout << "";
} //render


int SDLCALL watch(void *userdata, SDL_Event* event) {

	if (event->type == SDL_APP_WILLENTERBACKGROUND) {
		quitting = true;
	}

	return 1;
}


// copied from shader LUL
std::string xLoadFile(const char* fileName) // TODO:  redo this garbage
{
	std::string file;
	std::ifstream fileStream(fileName, std::ios::in);
	if (fileStream.is_open())
	{
		std::string line = "";
		while (getline(fileStream, line))
			file += "\n" + line;
		fileStream.close();
		return file;
	}
	throw std::exception("stop");
}

int main()
{
	//Engine zma;
	//zma.Initialize();



	GameMap testMap(16 * 4 + 3, 16 * 3 + 2);

//	GameMap testMap(16, 9);
//
	testMap.GetTile(16 * 4, 16 * 3).SetScriptName("wall");

	for (int x = 0; x < 16; x++)
	{
		for (int y = 0; y < 9; y++)
		{
			if ((y == 0 || y == 8) && (x == 0 || x == 15))
			{
				testMap.GetTile(x, y).SetScriptName("wall");
			}
			else
			{
				testMap.GetTile(x, y).SetScriptName("floor");
			}
		}
	}

	testMap.Serialize();
	printf("");
//
//	JsRuntimeHandle Runtime;
//	JsErrorCode error = JsCreateRuntime(JsRuntimeAttributeNone, nullptr, &Runtime);
//
//	//Entity e;
//	//e.AddComponent<TestComponentA>(new TestComponentA());
//	//e.AddComponent<TestComponentB>(new TestComponentB());
//
//	//TestComponentA* a = e.GetComponent<TestComponentA>();
//	//TestComponentB* b = e.GetComponent<TestComponentB>();
//
//	//Script scripte(Runtime,
//	//	"test = { ez: 14, pz: 20, cheezy: 'hello' } \n plasmaLog('hello'); \n function butt() { plasmaLog('Butt Called'); }");
//
//	Script scripte(Runtime, FileLoadLines("wall.js"), "wall");
//
//
//	//std::cout << scripte.GetProperty<int32>("xyz.abe") << std::endl;
//	//std::cout << scripte.GetProperty<double>("xyz.nest.pie") << std::endl;
//	//std::cout << scripte.GetProperty<std::string>("xyz.nest.bubble") << std::endl;
//	//scripte.CallFunction("butt");
//	
//	std::string nmz = scripte.GetPropertyNames(scripte.GetName());
//
//
//	std::set<std::string> members = SplitStringUnique(nmz, ',');
//	members.insert("ass");
//
//	std::vector<std::string> mem = SplitString(nmz, ',');
//
//// component bleow
//
//
//	//std::getchar(); // SCRIPTEND
//
//	//Server server;
//	//TestClient testClient;
//
//	//std::cout << "input 1 for serv, input 2 for client \n";
//	//int input = std::getchar();
//
//	//if (input == '1')
//	//{
//	//	std::cout << "Serv select\n";
//	//	server.Test();
//	//}
//	//else if (input == '2')
//	//{
//	//	std::cout << "Client select\n";
//	//	testClient.Connect();
//	//}
//	//else
//	//{
//	//	std::cout << "Neither select !!";
//	//	return 0;
//	//}
//
//	printf("Press enter to start client.");
//	std::getchar();
//
//	Engine engine;
//	engine.Initialize();
//
//	//return 0;
//	//JsRuntimeHandle runtime;
//	//JsContextRef context;
//	//JsValueRef result;
//	//unsigned currentSourceContext = 0;
//
//	//std::string scrx = xLoadFile("test.js");
//	////const char* script = xLoadFile
//	//size_t length = strlen(scrx.c_str()); // ha
//
//	//// Create a runtime.
//	//JsCreateRuntime(JsRuntimeAttributeNone, nullptr, &runtime);
//
//	//// Create an execution context.
//	//JsCreateContext(runtime, &context);
//
//	//// Now set the current execution context.
//	//JsSetCurrentContext(context);
//
//	//JsValueRef fname;
//	//FAIL_CHECK(JsCreateString("sample", strlen("sample"), &fname));
//
//	//JsValueRef scriptSource;
//	//FAIL_CHECK(JsCreateString(scrx.c_str(), length, &scriptSource));
//
//	//// Run the script.
//	//FAIL_CHECK(JsRun(scriptSource, currentSourceContext++, fname,
//	//	JsParseScriptAttributeNone, &result));
//
//	//// Convert your script result to String in JavaScript; redundant if your script returns a String
//	//JsValueRef resultJSString;
//	//FAIL_CHECK(JsConvertValueToString(result, &resultJSString));
//
//	//// Project script result back to C++.
//	//// we deleted it 
//
//	//// AAAAAAAAAAAAAA
//	//JsValueRef tile;
//	//JsCreateObject(&tile);
//	//
//
//	//JsValueRef output;
//	//JsPropertyIdRef propertyID;
//	//JsGetPropertyIdFromName(L"Name", &propertyID);
//	//JsGetProperty(fname, propertyID, &output);
//
//	////JsValueRef testxxxx = output;
//	////JsConvertValueToString(output, &testxxxx);//conv 2 string
//	//JsValueRef glob;
//	//JsGetGlobalObject(&glob);
//	//
//	//JsCallFun
//	//
//
//	//char *resultSTRx = nullptr;
//	//size_t stringLengthx;
//	//FAIL_CHECK(JsCopyString(glob, nullptr, 0, 0, &stringLengthx));
//	//resultSTRx = (char*)malloc(stringLengthx + 1);
//	//FAIL_CHECK(JsCopyString(glob, resultSTRx, stringLengthx + 1, 0, nullptr));
//	//resultSTRx[stringLengthx] = 0;
//
//	//std::cout << "value of test string was " << resultSTRx << "\n";
//
//	//// AAAAAAAAAA
//
//
//
//	//// Dispose runtime
//	//JsSetCurrentContext(JS_INVALID_REFERENCE);
//	//JsDisposeRuntime(runtime);
//
//	////return 0;
//
//	//return 1;
//
//	std::getchar();
//
//	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
//		SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
//		return 1;
//	}
//
//	SDL_AddEventWatch(watch, NULL);
//
//
//	renderer = new RendererGL();
//	renderer->Initialize();
//
//	cam = Camera(768, 768);
//	renderer->SetCamera(&cam);
//
//	textur = renderer->CreateTexture();
//	textur->LoadFromFile("test.png");
//
//	spri = new Sprite(renderer, textur);
//
//
//	txt = new TextRenderer(renderer, "DINRg.ttf", 36);
//	txt->SetText("test");
//
//	shad = new TestShader(renderer);
//	shad->Texture = textur;
//	shad->Initialize();
//
//
//	if (!shad->GetCompileResult(ShaderType::Pixel))
//		int iiiii = 0;
//
//	std::cout << "PIXEL --> " << shad->GetCompileLog(ShaderType::Pixel) << "\n";
//
//	if (!shad->GetCompileResult(ShaderType::Vertex))
//		int iiiiii = 1;
//
//	std::cout << "VERTEX --> " << shad->GetCompileLog(ShaderType::Vertex) << "\n";
//
//	renderer->SetShader(shad);
//
//	std::cout << "ERROR --> " << glGetError() << "\n";
//
//
//	// ENT CREATION
//
//	std::string xyyyy = "FartNUGGET";
//
//	Entity e;
//
//	SpriteComponent* sprcmp = new SpriteComponent();
//
//	printf("AAAAA%sAAAAA", mem[0].c_str());
//
//	for (uint64 i = 0; i < mem.size(); i++)
//	{
//		if (mem[i] == "spriteComponent")
//		{
//			std::string icon =
//				scripte.GetProperty<std::string>(scripte.GetName() + ".spriteComponent.icon");
//
//			sprcmp->SetIcon(icon);
//		}
//	}
//	//if (members.find("spriteComponent") != members.end())
//	//{
//	//	std::string icon = 
//	//		scripte.GetProperty<std::string>(scripte.GetName() + ".spriteComponent.icon");
//
//	//	sprcmp->SetIcon(icon);
//	//}
//
//	e.AddComponent<SpriteComponent>(sprcmp);
//
//	//
//	SpriteComponent* sx = e.GetComponent<SpriteComponent>();
//
//
//	while (!quitting) {
//
//		SDL_Event event;
//		while (SDL_PollEvent(&event)) {
//			if (event.type == SDL_QUIT) {
//				quitting = true;
//			}
//		}
//
//		render();
//
//	}
//
//	SDL_DelEventWatch(watch, NULL);
//	SDL_Quit();
//
} //main