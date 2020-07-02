#include "pch.h"
#include "AssetUtils.h"

namespace StarEditor
{
	GUID* AssetUtils::s_NewGuidPtr;

	GUID AssetUtils::NewGUID() 
	{
		CoCreateGuid(s_NewGuidPtr);
		return *s_NewGuidPtr;
	}

	bool AssetUtils::WriteFile(const char* dataPtr, const size_t dataLength, const std::string& assetPath)
	{
		std::ofstream assetFile(assetPath, std::ios::out | std::ios::binary);
		assetFile.write(dataPtr, dataLength);
		assetFile.close();
		return !assetFile.fail();
	}
}