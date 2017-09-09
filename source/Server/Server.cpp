#include "Server.h"

int main()
{
	// insert dedicated server here
}

void Server::Update()
{
	ENetEvent event;
	while (enet_host_service(ServerHost, &event, 1000) > 0)
	{
		switch (event.type)
		{
		case ENET_EVENT_TYPE_CONNECT:
			break;
		case ENET_EVENT_TYPE_DISCONNECT:
			break;
		}
	}
}
void Server::Initialize()
{
	int result = enet_initialize();
	AssertRT(!result, "Networking system failed to initialize. Code %d", result);

	Address.host = ENET_HOST_ANY;
	Address.port = 5513;

	ServerHost = enet_host_create(&Address, 32, 2, 0, 0);
	if (!ServerHost)
		return;

	// Server Loop
	while (true)
	{
		Update();
	}
}
//
//void Server::Test()
//{
//	if (enet_initialize() != 0)
//	{
//		return;
//	}
//
//	Address.host = ENET_HOST_ANY;
//	Address.port = 5513; // SS13 :)
//
//	Host = enet_host_create(&Address, 32, 2, 0, 0);
//	if (!Host)
//		return; // server create failure
//
//	ENetEvent event;
//	while (enet_host_service(Host, &event, 1000) > 0 || true)
//	{
//		switch (event.type)
//		{
//		case ENET_EVENT_TYPE_CONNECT:
//			std::cout << "Client connected: " <<
//				event.peer->address.host << ":" << event.peer->address.port << "\n";
//			break;
//		case ENET_EVENT_TYPE_RECEIVE:
//			ProcessRecvEvent(event);
//
//			std::cout << event.packet->data << std::endl;
//
//			enet_packet_destroy(event.packet);
//			break;
//		case ENET_EVENT_TYPE_DISCONNECT:
//			std::cout << "Client disconnect: " <<
//				event.peer->address.host << "\n";
//			break;
//		}
//	}
//
//	enet_host_destroy(Host);
//	enet_deinitialize();
//}
//
//void Server::ProcessRecvEvent(ENetEvent& event)
//{
//}