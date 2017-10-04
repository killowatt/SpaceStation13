#pragma once
#include "Core.h"
#include "ChakraCore.h"

JsValueRef CALLBACK LogBinding(JsValueRef callee, bool isConstructCall, JsValueRef* arguments,
	unsigned short argumentCount, void* callbackState)
{
	if (argumentCount <= 0)
	{
		Log::Print(LogCategory::Error, "Script attempted to call plasmaLog, but failed.");
		return JS_INVALID_REFERENCE;
	}

	JsValueRef messageValue;
	JsConvertValueToString(arguments[1], &messageValue);

	int32 messageLength;
	JsGetStringLength(messageValue, &messageLength);

	char* buffer = new char[messageLength + 1];
	JsCopyString(messageValue, buffer, messageLength, nullptr);
	buffer[messageLength] = '\0'; // not sure if needed

	Log::Print(LogCategory::Script, buffer);

	delete[] buffer;
	return JS_INVALID_REFERENCE;
}

class ScriptNativeEngineInterface // this is just a meme name dont worry
{
public:
	JsValueRef CALLBACK KeyPressed(JsValueRef callee, bool isConstructCall, JsValueRef* arguments,
		unsigned short argumentCount, void* callbackState)
	{

	}
};