#pragma once
#include "Core.h"
#include <enet/enet.h>

const static uint32 DEFAULT_PORT = 5513; // SS13

std::string GetAddressString(ENetAddress* address)
{
	char* addressString = new char[256];
	enet_address_get_host(address, addressString, 256);

	std::string resultAddress(addressString);
	delete[] addressString;

	return resultAddress;
}
