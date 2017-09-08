#pragma once
#include "Core.h"

enum class LogCategory
{
	Info,
	Warning,
	Error,
	Fatal
};
char* GetCategoryName(LogCategory category);

void LogPrint(LogCategory category, const char* message);
void LogPrint(LogCategory category, const char* system, const char* message);