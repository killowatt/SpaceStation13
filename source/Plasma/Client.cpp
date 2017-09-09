#include "Client.h"

bool Client::Connect(const char* address, uint16 port)
{
	Log::Print(LogCategory::Info, "Attempting to connect to %s:%d...", address, port);
	
	ENetAddress netAddress;
	enet_address_set_host(&netAddress, address);
	netAddress.port = port;

	Server = enet_host_connect(ClientHost, &netAddress, 2, 0);
	if (!Server)
	{
		Log::Print(LogCategory::Error, "Server peer could not be created.");
		return false;
	}

	ENetEvent event;
	if (enet_host_service(ClientHost, &event, 10000) > 0 &&
		event.type == ENET_EVENT_TYPE_CONNECT)
	{
		enet_host_flush(ClientHost); // This will allow the server-side to immediately react.

		Log::Print(LogCategory::Info, "Connected.");
		return true;
	}

	Log::Print(LogCategory::Error, "Could not connect to %s:%d", address, port);
	enet_peer_reset(Server);

	return false;
}
void Client::Disconnect()
{
	// !
}

void Client::SendPacket(ByteStream& stream)
{
	ENetPacket* packet = enet_packet_create(stream.GetData(), stream.GetSize(),
		ENET_PACKET_FLAG_RELIABLE);

	enet_peer_send(Server, 0, packet);
}

void Client::Update()
{
	ENetEvent event;
	while (enet_host_service(ClientHost, &event, 0) > 0)
	{

	}
}
void Client::Initialize()
{
	int result = enet_initialize();
	AssertRT(!result, "Networking system failed to initialize. Code %d", result);

	ClientHost = enet_host_create(nullptr, 1, 2, 0, 0);
	AssertRT(ClientHost, "Client host creation failed.");
}

Client::Client()
{

}
Client::~Client()
{
	if (ClientHost) enet_host_destroy(ClientHost);
}