#pragma once
#include "Core.h"

enum PacketType
{
	PacketTypeGetVersion = 1, // S2C
	PacketTypeReturnVersion = 2, // C2S
	PacketTypeTileChange = 100, // example
};
class Packet
{
	// ToStream (later)
};