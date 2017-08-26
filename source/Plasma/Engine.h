#pragma once

typedef signed int int32;
typedef unsigned int uint32;

typedef unsigned char uint8;

struct NonCopyable
{
	NonCopyable & operator=(const NonCopyable&) = delete;
	NonCopyable(const NonCopyable&) = delete;
	NonCopyable() = default;
};