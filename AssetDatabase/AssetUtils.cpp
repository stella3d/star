#include "pch.h"
#include "AssetUtils.h"

namespace StarEditor
{
	bool AssetUtils::WriteFile(const char* dataPtr, const size_t dataLength, const std::string& assetPath)
	{
		std::ofstream assetFile(assetPath, std::ios::out | std::ios::binary);
		assetFile.write(dataPtr, dataLength);
		assetFile.close();
		return !assetFile.fail();
	}
}