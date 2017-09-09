#pragma once
#include "Core.h"
#include "ByteStream.h"
#include <enet/enet.h>

class Client
{
	ENetAddress Address;
	ENetHost* ClientHost;
	ENetPeer* Server;

public:
	bool Connect(const char* address, uint16 port);
	void Disconnect();

	// Schedules a packet to be sent. Not immediate
	void SendPacket(ByteStream& stream);
	// SendPacketImmediate?

	void Update();
	void Initialize();

	Client();
	~Client();
};