#include "Log.h"
#include <cstdarg>
#include <iostream>

// Example for future..
//#ifdef PLATFORM_WINDOWS && PLATFORM_CONSOLEWINDOW
// ..std::cout for cmd prompt..

// Important
// TODO: This subsystem needs to be worked on; its temporary impl so we can debug in-dev
// Important


char* Log::GetCategoryName(LogCategory category)
{
	char* categoryName;
	switch (category)
	{
	case LogCategory::Info:
		categoryName = "Info";
		break;
	case LogCategory::Warning:
		categoryName = "Warning";
		break;
	case LogCategory::Error:
		categoryName = "Error";
		break;
	default:
		categoryName = "Undefined";
		break;
	}
	return categoryName;
}

//void Log::Print(LogCategory category, const char* message)
//{
//	printf("[%s] %s", GetCategoryName(category), message);
//}
void Log::Print(LogCategory category, const char* format, ...)
{
	printf("[%s] ", GetCategoryName(category));

	va_list list;
	va_start(list, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'd': // Decimal (Integer)
				std::cout << (int64)va_arg(list, int64);
				break;
			case 'f':
				std::cout << (double)va_arg(list, double);
				break;
			case 's': // String
				std::cout << va_arg(list, char*);
				break;
			default:
				std::cout << *format;
				break;
			}
		}
		else
			std::cout << *format; // urgh

		format++;
	}
	std::cout << "\n";

	if (category == LogCategory::Fatal) // TODO: VVV
		Debug::RuntimeError("Todo: Stringstream error message into both log output and err");
}
//void Log::Print(LogCategory category, const char* system, const char* message)
//{
//	printf("[%s][%s] %s", GetCategoryName(category), system, message);
//}