#pragma once
#include "Core.h"
#include <string>

class ByteStream
{
private:
	uint8* Stream;
	uint64 Size;
	uint64 Position;

public:
	void Read(void* destination, uint32 bytes);
	void Write(const void* data, uint32 bytes);

	template<typename T>
	T Read() { T result = 0; Read(&result, sizeof(T)); return result; } // VV

	template<typename T>
	void Write(T data) { Write(&data, sizeof(T)); } // WE DONT KNOW IF ANY OF THESE WORK

	std::string ReadString();
	void WriteString(const std::string& string);

	void SetPosition(uint64 position) { Position = position; }
	uint64 GetPosition() { return Position; }

	ByteStream(uint8* buffer, uint64 size);

	ByteStream& operator=(const ByteStream&) = delete; // Explicitness
	ByteStream(const ByteStream&) = delete;
	ByteStream() = delete;
};