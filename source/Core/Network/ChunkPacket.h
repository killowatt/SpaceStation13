#pragma once
#include "Packet.h"

struct ChunkPacket
{
	uint32 simpleData;

	ByteStream ToStream()
	{
		ByteStream stream;
		stream.Write<PACKET_DT>(PacketTypeChunkUpdate);

		stream.Write<uint32>(simpleData);

		return stream;
	}
	static ChunkPacket FromStream(ByteStream& stream)
	{
		ChunkPacket chunkPacket;
		chunkPacket.simpleData = stream.Read<uint32>();

		return chunkPacket;
	}
};