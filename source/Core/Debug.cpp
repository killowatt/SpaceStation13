#include "Debug.h"

#pragma comment(lib,"user32.lib") 
#include <Windows.h>

void Debug::RuntimeError(const char* message)
{
	// should we use a define, and then static_assert to ensure that not even the error is broke

	// Windows only, add platform impl or use lib
	MessageBoxA(nullptr, message, "Runtime Error", MB_OK);

	return; // Breakpoint here for now
	// TODO: now crash the program
}