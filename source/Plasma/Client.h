#pragma once
#include "Core.h"
#include <enet/enet.h>

class Client
{
	ENetAddress Address;
	ENetHost* ClientHost;
	ENetPeer* Server;

public:
	bool Connect(const char* address, uint16 port);
	void Disconnect();

	void Update();
	void Initialize();

	Client();
	~Client();
};