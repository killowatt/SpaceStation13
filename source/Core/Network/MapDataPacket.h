#pragma once
#include "Packet.h"

struct MapData
{
	uint32 Width;
	uint32 Height;
	std::string Name;

	ByteStream ToStream()
	{
		ByteStream stream;
		stream.Write<PACKET_DT>(PacketTypeMapData);

		stream.Write<uint32>(Width);
		stream.Write<uint32>(Height);
		stream.WriteString(Name);

		return stream;
	}
	static MapData FromStream(ByteStream& stream)
	{
		MapData mapData;
		mapData.Width = stream.Read<uint32>();
		mapData.Height = stream.Read<uint32>();
		mapData.Name = stream.ReadString();

		return mapData;
	}
};