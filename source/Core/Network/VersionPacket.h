#pragma once
#include "Packet.h"

class VersionPacket
{
public:
	uint32 PacketType;
	uint32 ClientRuntimeVersion;
};