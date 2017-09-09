#include "Engine.h"

#include "Script.h"

#include "ByteStream.h"

#include <iostream>

#include "Client.h"

#include "Network/NetPlayer.h"

void Engine::Initialize()
{
	Client xyzzy;

	std::cout << "Press enter to start\n";
	std::getchar();

	xyzzy.Initialize();
	xyzzy.Connect("localhost", 5513);

	PlayerData playerdata;
	xyzzy.SendPacket(playerdata.ToStream());

	while (true)
	{
		xyzzy.Update();
	}

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


	std::getchar();
	// init all systems
	// begin game loop
}