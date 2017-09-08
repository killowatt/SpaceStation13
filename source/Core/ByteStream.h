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
	void Read(void* destination, uint64 bytes);
	void Write(const void* data, uint64 bytes);

	// TODO: Should we expose templates internally as a method for outward public methods
	// such as readint or readbyte?
	template<typename T>
	T Read() { T result = 0; Read(&result, sizeof(T)); return result; }
	template<typename T>
	void Write(T data) { Write(&data, sizeof(T)); }

	std::string ReadString();
	void WriteString(const std::string& string);

	void SetPosition(uint64 position) { Position = position; }
	uint64 GetPosition() { return Position; }

	ByteStream(uint8* buffer, uint64 size);

	ByteStream& operator=(const ByteStream&) = delete; // Explicitness
	ByteStream(const ByteStream&) = delete;
	ByteStream() = delete;
};