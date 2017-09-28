#pragma once
#include "Engine.h"
static class Utilities
{
public:
	static int Decompress(TArray<uint8> CompressedData, TArray<uint8> &DecompressedData);
};