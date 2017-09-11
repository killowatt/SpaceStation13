#pragma once
#include "Core.h"
#include "ByteStream.h"

// The type of the packet header
#define PACKET_DT uint8

enum PacketType : PACKET_DT
{
	PacketTypeGetVersion = 1, // S2C
	PacketTypeReturnVersion = 2, // C2S

	PacketTypePlayerData = 3, // C2S
	PacketTypeMapData = 4, // S2C

	PacketTypeTileChange = 100, // example
};