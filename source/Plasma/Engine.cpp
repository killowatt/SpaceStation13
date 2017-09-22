#include "Engine.h"
#include "Client.h"
#include "GameMap.h"


#include "Network/NetPlayer.h"

void Engine::ChangeLevel(GameMap* map)
{
	if (!map)
	{
		Log::Print(LogCategory::Error, "Tried to change level, but the map provided was null.");
		return;
	}

	Log::Print(LogCategory::Info, "Changing level to %s", map->Name.c_str());
	if (CurrentMap)
	{
		delete CurrentMap;
	}
	//	delete CurrentMap;
	
	//CurrentMap = map;
}

void Engine::Update()
{
	Client.Update();
}
void Engine::Render()
{
}

void Engine::Initialize()
{
	CurrentMap = nullptr;

	Client.Initialize(this);


	// Temp
	Client.Connect("127.0.0.1", 5513);

	PlayerData pd;
	Client.SendPacket(pd.ToStream());

	while (true)
	{
		Update();
		Render();
	}
}

Engine::Engine()
{
	CurrentMap = nullptr;
}


//// Old test code, ignore
//Client xyzzy;
//
//std::cout << "Press enter to start\n";
//std::getchar();
//
//xyzzy.Initialize();
//xyzzy.Connect("localhost", 5513);
//
//PlayerData playerdata;
//xyzzy.SendPacket(playerdata.ToStream());
//
//while (true)
//{
//	xyzzy.Update();
//}

//uint8* data = new uint8[555];
//ByteStream b(data, 555);

//b.Write<uint8>(16);
//b.Write<uint8>(32);
//b.Write<uint8>(64);
//b.Write<uint32>(500000);

//b.WriteString("WelcomeToSS13");

//b.SetPosition(0);

//uint8 f = b.Read<uint8>();
//uint8 y = b.Read<uint8>();
//uint8 z = b.Read<uint8>();
//uint32 a = b.Read<uint32>();

//std::string xyyy = b.ReadString();

//std::cout << xyyy;

//Script x("script.lua");
//
//std::cout << x.GetVariable<std::string>("tile.icon");


//std::getchar();
// init all systems
// begin game loop