#include "Server.h"
#include "Network/Network.h"

// TODO: factor out these so we dont have such a f'd up header dependency tree
#include "Network/MapDataPacket.h"
#include "Network/ChunkPacket.h"

int main()
{
	Server server;
	server.Initialize();
}

void Server::SendPacket(const NetPlayer& player, ByteStream& stream)
{
	ENetPacket* packet = enet_packet_create(stream.GetData(), stream.GetSize(),
		ENET_PACKET_FLAG_RELIABLE);

	enet_peer_send(player.Peer, 0, packet);
}

void Server::ChangeMap()
{
}

void Server::Update()
{
	if (Players.size() > 0)
	{
		printf("Sending test update");

		ChunkPacket x, y, z, a;
		x.simpleData = 5;
		y.simpleData = 15;
		z.simpleData = 9;
		a.simpleData = 994;

		ByteStream xx = x.ToStream();
		ByteStream yy = y.ToStream();
		ByteStream zz = z.ToStream();
		ByteStream aa = a.ToStream();

		SendPacket(Players[0], xx);
		SendPacket(Players[0], yy);
		SendPacket(Players[0], zz);
		SendPacket(Players[0], aa);
	}

	ENetEvent event;
	while (enet_host_service(ServerHost, &event, 0) > 0)
	{
		std::string clientAddress = GetAddressString(&event.peer->address);
		switch (event.type)
		{
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
			{
				PlayerData data = PlayerData::FromStream(reader);
				Log::Print(LogCategory::Info, "Player Data received, name %s",
					data.Name.c_str());

				NetPlayer player;
				player.Peer = event.peer;
				player.Name = data.Name;

				Players.push_back(player);

				MapData mapData;
				mapData.Name = "Goonstation";
				mapData.Width = 32;
				mapData.Height = 192;

				ByteStream mapDataStream = mapData.ToStream();
				SendPacket(player, mapDataStream);

				break;
			}
			default:
				Log::Print(LogCategory::Warning, "Packet of type %d received by server, "
					"but is not handled by implementation.", packetType);
				break;
			}
			enet_packet_destroy(event.packet);
			break;
		}
	}
}
void Server::Initialize()
{
	Log::Print(LogCategory::Info, "Initializing server...");

	int result = enet_initialize();
	AssertRT(!result, "Networking system failed to initialize.");

	Address.host = ENET_HOST_ANY;
	Address.port = 5513;

	ServerHost = enet_host_create(&Address, 32, 2, 0, 0);
	if (!ServerHost)
		return;

	// Server parameters
	//ServerHost->duplicatePeers = 1; // TODO: implement this ourselves

	CurrentMap = nullptr; // We don't have a map loaded yet

	CurrentMap = new GameMap(64, 256); // Temp load map for testing


	Log::Print(LogCategory::Info, "Server initialization success, proceeding to loop.");

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