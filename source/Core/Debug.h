#pragma once

#define AssertRT(expr, message) if (!expr) Debug::RuntimeError(message); // Runtime Assert

namespace Debug
{
	void RuntimeError(const char* message);
}