#include "Server.h"
#include "Network/Network.h"

int main()
{
	Log::Print(LogCategory::Info, "Test");
	Server server;
	server.Initialize();
}

void Server::Update()
{
	ENetEvent event;
	while (enet_host_service(ServerHost, &event, 0) > 0)
	{
		std::string clientAddress = GetAddressString(&event.peer->address);
		switch (event.type)
		{
		case ENET_EVENT_TYPE_NONE:
			break;
		case ENET_EVENT_TYPE_CONNECT:
			Log::Print(LogCategory::Info, "Client connected from %s:%d",
				clientAddress.c_str(), event.peer->address.port);
			break;
		case ENET_EVENT_TYPE_DISCONNECT:
			Log::Print(LogCategory::Info, "Client disconnected from %s:%d",
				clientAddress.c_str(), event.peer->address.port);
			break;
		case ENET_EVENT_TYPE_RECEIVE:
			ByteStream reader(event.packet->data, event.packet->dataLength);
			PACKET_DT packetType = reader.Read<PACKET_DT>();

			switch (packetType)
			{
			case PacketTypePlayerData:
				PlayerData data = PlayerData::FromStream(reader);
				Log::Print(LogCategory::Info, "Player Data received, name %s",
					data.Name.c_str());
				break;
			}

			break;
		}
	}
}
void Server::Initialize()
{
	int result = enet_initialize();
	AssertRT(!result, "Networking system failed to initialize.");

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

Server::~Server()
{
	if (ServerHost) enet_host_destroy(ServerHost);
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