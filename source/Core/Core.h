#pragma once
#include "Debug.h"
#include "Log.h"
#include <memory>
#include <string>

typedef signed int int32;
typedef unsigned int uint32;

typedef signed long long int64;
typedef unsigned long long uint64;

typedef unsigned short uint16;

typedef unsigned char uint8;

//typedef std::unique_ptr<int> Resource;

struct NonCopyable
{
	NonCopyable & operator=(const NonCopyable&) = delete;
	NonCopyable(const NonCopyable&) = delete;
	NonCopyable() = default;
};

std::string FileLoadLines(const std::string& filename);