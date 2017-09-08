#include "Log.h"

// Example for future..
//#ifdef PLATFORM_WINDOWS && PLATFORM_CONSOLEWINDOW
// ..std::cout for cmd prompt..

// Important
// This subsystem needs to be worked on; its temporary so we can debug in-dev
// Important


char* GetCategoryName(LogCategory category)
{
	char* categoryName;
	switch (category)
	{
	case LogCategory::Warning:
		categoryName = "Warning";
		break;
	default:
		categoryName = "Undefined";
		break;
	}
	return categoryName;
}

void LogPrint(LogCategory category, const char* message)
{
	printf("[%s] %s", GetCategoryName(category), message);
}
void LogPrint(LogCategory category, const char* system, const char* message)
{
	printf("[%s][%s] %s", GetCategoryName(category), system, message);
}