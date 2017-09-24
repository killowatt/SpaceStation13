#pragma once
#include "Core.h"

// Class used to pack up content dependencies and unpack them on the client.
class ContentArchive
{
	uint8* data;

	void UnpackContent();
};