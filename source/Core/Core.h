#pragma once
#include <memory>

typedef signed int int32;
typedef unsigned int uint32;
typedef unsigned long long uint64;

typedef unsigned char uint8;

//typedef std::unique_ptr<int> Resource;

struct NonCopyable
{
	NonCopyable & operator=(const NonCopyable&) = delete;
	NonCopyable(const NonCopyable&) = delete;
	NonCopyable() = default;
};