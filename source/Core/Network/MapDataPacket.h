#pragma once
#include "Packet.h"

struct MapData
{
	std::string Name;
	uint32 Width;
	uint32 Height;

	ByteStream ToStream()
	{
		ByteStream stream;
		stream.Write<PACKET_DT>(PacketTypeMapData);

		stream.WriteString(Name);
		stream.Write<uint32>(Width);
		stream.Write<uint32>(Height);

		return stream;
	}
	static MapData FromStream(ByteStream& stream)
	{
		MapData mapData;
		mapData.Name = stream.ReadString();
		mapData.Width = stream.Read<uint32>();
		mapData.Height = stream.Read<uint32>();

		return mapData;
	}
};