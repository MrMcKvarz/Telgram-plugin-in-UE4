#pragma once
#include "Engine.h"
static class TELETALKER_API Utilities
{
public:
	static int Decompress(TArray<uint8> CompressedData, TArray<uint8> &DecompressedData);
};