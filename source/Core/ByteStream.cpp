#include "ByteStream.h"

void ByteStream::Read(void* destination, uint64 bytes)
{
	if (Position >= Stream.size())
		return; // Error: end of stream
	if (bytes > Stream.size() - Position)
		return; // Error: overread!

	memcpy(destination, Stream.data() + Position, bytes); // monkaS
	Position += bytes;
}
void ByteStream::Write(const void* data, uint64 bytes)
{
	Stream.resize(Stream.size() + bytes);
	memcpy(Stream.data() + Position, data, bytes); // monkaS
	Position += (uint64)bytes;
}

std::string ByteStream::ReadString()
{
	uint64 length = Read<uint64>();
	if (length > Stream.size() - Position)
		return "InvalidString"; // TODO: error
	std::string String((char*)Stream.data() + Position, length);
	Position += length;
	return String;
}
void ByteStream::WriteString(const std::string& string)
{
	Write<uint64>(string.size());
	Write(string.c_str(), string.size());
}

ByteStream::ByteStream()
{
	Position = 0;
}
ByteStream::ByteStream(uint8* data, uint64 size)
{
	Position = 0;

	this->Stream.resize(size);
	memcpy(Stream.data(), data, size);
}