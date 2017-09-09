#include "Client.h"

bool Client::Connect(const char* address, uint16 port)
{
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
		return true;

	Log::Print(LogCategory::Error, "Could not connect to %s:%d", address, port);
	return false;
}
void Client::Disconnect()
{

}

void Client::Update()
{
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