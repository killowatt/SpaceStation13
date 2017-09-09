#pragma once
#include "Core.h"
#include <vector>
#include <string>

class ByteStream
{
private:
	std::vector<uint8> Stream;
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
	
	std::vector<uint8>& GetStream() { return Stream; }
	const uint8* GetData() { return Stream.data(); }
	uint64 GetSize() { return Stream.size(); }

	void SetPosition(uint64 position) { Position = position; }
	uint64 GetPosition() { return Position; }

	ByteStream();
	ByteStream(uint8* data, uint64 size);

	//ByteStream& operator=(const ByteStream&) = delete; // Explicitness
	//ByteStream(const ByteStream&) = delete;
};