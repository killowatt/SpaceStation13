#pragma once
#include "Core.h"

enum class LogCategory
{
	Info,
	Script,
	Warning,
	Error,
	Fatal
};
namespace Log
{
	char* GetCategoryName(LogCategory category);

	//void Print(LogCategory category, const char* message);
	void Print(LogCategory category, const char* format, ...);
	//void Print(LogCategory category, const char* system, const char* message);
}