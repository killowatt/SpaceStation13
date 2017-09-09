#pragma once
#include "Packet.h"
#include <enet/enet.h>
#include <string>

struct NetPlayer
{
	ENetPeer* Peer;
	std::string Name;

	void Disconnect() {}
	void Disconnect(std::string message) {}

	NetPlayer() : Name("George Melons") {}
};
struct PlayerData
{
	std::string Name;

	ByteStream ToStream()
	{
		ByteStream stream;
		stream.Write<PACKET_DT>(PacketTypePlayerData);

		stream.WriteString(Name);

		return stream;
	}
	static PlayerData FromStream(ByteStream& stream)
	{
		PlayerData playerData;
		playerData.Name = stream.ReadString();

		return playerData;
	}

	PlayerData() : Name("George Melons") {}
};