#pragma once
#include "Engine.h"
static class TELETALKER_API Utilities
{
public:
	static int32 Decompress(TArray<uint8> CompressedData, TArray<uint8> &DecompressedData);
};