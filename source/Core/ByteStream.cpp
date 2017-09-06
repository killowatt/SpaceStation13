#include "ByteStream.h"

void ByteStream::Read(void* destination, uint32 bytes)
{
	if (Position >= Size)
		return; // Error: end of stream
	if ((uint64)bytes > Size - Position)
		return; // Error: overread!

	memcpy(destination, Stream + (uint64)Position, bytes);
	Position += (uint64)bytes;
}
void ByteStream::Write(const void* data, uint32 bytes)
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

ByteStream::ByteStream(uint8* buffer, uint64 size)
{
	Stream = buffer;
	Size = size;

	Position = 0;
}