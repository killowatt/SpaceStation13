#pragma once
#include "Core.h"

class ByteStream
{
	void Write(const void* data, uint64 bytes) {}
	void WriteByte(uint8 byte) {}

	uint8 ReadByte() {}
};