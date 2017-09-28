#include "Utilities.h"
#include <zlib.h>

int Utilities::Decompress(TArray<uint8> CompressedData, TArray<uint8> &DecompressedData)
{
	/*
	returning res code means following:
	0 data decompressed fine
	1 buffer reached end(should not be returned but its means fine)
	-3 Data Corruption error
	-5 Decompressed data bad size
	*/
	const uint32 ChunkSize = 16948;
	uint32 packedLen = CompressedData.Num(), unpackedChunk = packedLen;
	uint8 Decompressed[ChunkSize];
	z_stream stream;
	stream.zalloc = 0;
	stream.zfree = 0;
	stream.opaque = 0;
	stream.avail_in = 0;
	stream.next_in = 0;
	int res = inflateInit2(&stream, 16 + MAX_WBITS);
	if (res != Z_OK) 
	{
		return res;
	}
	stream.avail_in = packedLen;
	stream.next_in = reinterpret_cast<Bytef*>(CompressedData.GetData());
	stream.avail_out = 0;
	while (!stream.avail_out)
	{

		stream.avail_out = unpackedChunk * 4;
		stream.next_out = (Bytef*)&Decompressed[0];
		int res = inflate(&stream, Z_NO_FLUSH);
		if (res != Z_OK && res != Z_STREAM_END)
		{
			inflateEnd(&stream);
			return res;
		}
	}
	if (stream.avail_out & 0x03)
	{
		uint32 badSize = DecompressedData.Num() * sizeof(int32) - stream.avail_out;
		res = -5;
		return res;
	}
	//result.AddZeroed(result.Num() - (stream.avail_out >> 2));
	DecompressedData.Reserve(stream.total_out);
	for (uLong i = 0; i < stream.total_out; i++)
		DecompressedData.Add(Decompressed[i]);
	//result.resize();
	inflateEnd(&stream);

	return res;

}
