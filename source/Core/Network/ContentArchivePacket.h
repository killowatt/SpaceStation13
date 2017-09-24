#pragma once
#include "Packet.h"

struct ContentArchivePacket
{
	ByteStream ToStream()
	{
		ByteStream stream;

		return stream;
	}
	static ContentArchivePacket FromStream(ByteStream& stream)
	{
		ContentArchivePacket archive;

		return archive;
	}
};