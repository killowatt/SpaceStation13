#include "Engine.h"

#include "Script.h"

#include "ByteStream.h"

#include <iostream>

void Engine::Initialize()
{

	uint8* data = new uint8[555];
	ByteStream b(data, 555);

	b.Write<uint8>(16);
	b.Write<uint8>(32);
	b.Write<uint8>(64);
	b.Write<uint32>(500000);


	std::string teststr = "Hello How are you!\0";
	uint64 sz = teststr.size();
	b.Write(&sz, sizeof(size_t));
	b.Write(teststr.c_str(), teststr.size());

	b.SetPosition(0);

	uint8 f = b.Read<uint8>();
	uint8 y = b.Read<uint8>();
	uint8 z = b.Read<uint8>();
	uint32 a = b.Read<uint32>();

	uint64 xyz = b.Read<uint64>();
	char* strz = new char[xyz];       // HEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEY
	b.Read(strz, xyz);                // fix the trailing characters for strings,
	                                // implement it into bytestream :)
	std::cout << strz;

	Script x("script.lua");
	
	std::cout << x.GetVariable<std::string>("tile.icon");


	std::getchar();
	// init all systems
	// begin game loop
}