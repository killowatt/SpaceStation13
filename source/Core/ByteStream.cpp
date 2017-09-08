#include "ByteStream.h"

void ByteStream::Read(void* destination, uint64 bytes)
{
	if (Position >= Size)
		return; // Error: end of stream
	if (bytes > Size - Position)
		return; // Error: overread!

	memcpy(destination, Stream + Position, bytes);
	Position += bytes;
}
void ByteStream::Write(const void* data, uint64 bytes)
{
	if (Position + (uint64)bytes > Size ||
		Position + (uint64)bytes < Position) // Integer overflow check, thanks openspades!
		memcpy(nullptr, nullptr, 0); //ERR ! < this is just so we can breakpoint, not functional
	else
	{
		memcpy(Stream + Position, data, bytes);
		Position += (uint64)bytes;
	}
}

std::string ByteStream::ReadString()
{
	uint64 length = Read<uint64>();
	if (length > Size - Position)
		return "InvalidNetworkString"; // TODO: error
	std::string String((char*)Stream + Position, length);
	Position += length;
	return String;
}
void ByteStream::WriteString(const std::string& string)
{
	Write<uint64>(string.size());
	Write(string.c_str(), string.size());
}

ByteStream::ByteStream(uint8* buffer, uint64 size)
{
	Stream = buffer;
	Size = size;

	Position = 0;
}