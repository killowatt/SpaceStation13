#pragma once
#include "Core.h"

enum PacketType
{
	PacketTypeGetVersion = 1, // S2C
	PacketTypeTileChange = 100, // example
};
class Packet
{
	// ToStream (later)
};