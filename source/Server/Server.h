#pragma once
#include <enet/enet.h>

#include <iostream>
#include "Network/Packet.h"

class Server
{
	ENetAddress Address;
	ENetHost* Host;

public:
	void ProcessRecvEvent(ENetEvent& event);

	void Test();
};

class TestClient
{
	ENetHost* Client;
	ENetPeer* Serv;

public:
	void Connect()
	{
		if (enet_initialize() != 0)
		{
			return;
		}

		Client = enet_host_create(nullptr, 1, 2, 0, 0);

		if (!Client)
			return;

		ENetAddress address;
		enet_address_set_host(&address, "localhost");
		address.port = 5513;

		Serv = enet_host_connect(Client, &address, 2, 0);

		if (!Serv)
			return;

		ENetEvent event;
		if (enet_host_service(Client, &event, 5000) > 0 &&
			event.type == ENET_EVENT_TYPE_CONNECT)
		{
			std::cout << "[CLIENT] Success connect";

			ENetPacket* packet = enet_packet_create("Hello", strlen("Hello") + 1,
				ENET_PACKET_FLAG_RELIABLE);

			enet_peer_send(Serv, 0, packet);
			enet_host_flush(Client);
		}
		else
		{
			enet_peer_reset(Serv);
			std::cout << "[CLIENT] connect disconnect";
		}


		enet_host_destroy(Client);
	}
};