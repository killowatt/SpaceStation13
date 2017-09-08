#include "Debug.h"

#pragma comment(lib,"user32.lib") 
#include <Windows.h>

void RuntimeError(const char* message)
{
	// Windows only
	MessageBoxA(nullptr, message, "Runtime Error", MB_OK);
}