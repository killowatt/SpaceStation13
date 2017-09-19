#pragma once
#include "ChakraCommon.h"
#include <string>

// *competes with jos*
std::string ErrorCodeToString(const JsErrorCode& error)
{
	switch (error)
	{
	case JsErrorCode::JsNoError:
		return "JsNoError";

	case JsErrorCode::JsErrorCategoryUsage:
		return "JsErrorCategoryUsage";

	case JsErrorCode::JsErrorInvalidArgument:
		return "JsErrorInvalidArgument";

	case JsErrorCode::JsErrorNullArgument:
		return "JsErrorNullArgument";

	case JsErrorCode::JsErrorNoCurrentContext:
		return "JsErrorNoCurrentContext";

	case JsErrorCode::JsErrorInExceptionState:
		return "JsErrorInExceptionState";

	case JsErrorCode::JsErrorNotImplemented:
		return "JsErrorNotImplemented";

	case JsErrorCode::JsErrorWrongThread:
		return "JsErrorWrongThread";

	case JsErrorCode::JsErrorRuntimeInUse:
		return "JsErrorRuntimeInUse";

	case JsErrorCode::JsErrorBadSerializedScript:
		return "JsErrorBadSerializedScript";

	case JsErrorCode::JsErrorInDisabledState:
		return "JsErrorInDisabledState";

	case JsErrorCode::JsErrorCannotDisableExecution:
		return "JsErrorCannotDisableExecution";

	case JsErrorCode::JsErrorHeapEnumInProgress:
		return "JsErrorHeapEnumInProgress";

	case JsErrorCode::JsErrorArgumentNotObject:
		return "JsErrorArgumentNotObject";

	case JsErrorCode::JsErrorInProfileCallback:
		return "JsErrorInProfileCallback";

	case JsErrorCode::JsErrorInThreadServiceCallback:
		return "JsErrorInThreadServiceCallback";

	case JsErrorCode::JsErrorCannotSerializeDebugScript:
		return "JsErrorCannotSerializeDebugScript";

	case JsErrorCode::JsErrorAlreadyDebuggingContext:
		return "JsErrorAlreadyDebuggingContext";

	case JsErrorCode::JsErrorAlreadyProfilingContext:
		return "JsErrorAlreadyProfilingContext";

	case JsErrorCode::JsErrorIdleNotEnabled:
		return "JsErrorIdleNotEnabled";

	case JsErrorCode::JsCannotSetProjectionEnqueueCallback:
		return "JsCannotSetProjectionEnqueueCallback";

	case JsErrorCode::JsErrorCannotStartProjection:
		return "JsErrorCannotStartProjection";

	case JsErrorCode::JsErrorInObjectBeforeCollectCallback:
		return "JsErrorInObjectBeforeCollectCallback";

	case JsErrorCode::JsErrorObjectNotInspectable:
		return "JsErrorObjectNotInspectable";

	case JsErrorCode::JsErrorPropertyNotSymbol:
		return "JsErrorPropertyNotSymbol";

	case JsErrorCode::JsErrorPropertyNotString:
		return "JsErrorPropertyNotString";

	case JsErrorCode::JsErrorCategoryEngine:
		return "JsErrorCategoryEngine";

	case JsErrorCode::JsErrorOutOfMemory:
		return "JsErrorOutOfMemory";

	case JsErrorCode::JsErrorCategoryScript:
		return "JsErrorCategoryScript";

	case JsErrorCode::JsErrorScriptException:
		return "JsErrorScriptException";

	case JsErrorCode::JsErrorScriptCompile:
		return "JsErrorScriptCompile";

	case JsErrorCode::JsErrorScriptTerminated:
		return "JsErrorScriptTerminated";

	case JsErrorCode::JsErrorScriptEvalDisabled:
		return "JsErrorScriptEvalDisabled";

	case JsErrorCode::JsErrorCategoryFatal:
		return "JsErrorCategoryFatal";

	case JsErrorCode::JsErrorFatal:
		return "JsErrorFatal";

	case JsErrorCode::JsErrorWrongRuntime:
		return "JsErrorWrongRuntime";

	default:
		return "UnknownError";
	}
}
