#pragma once
#include <combaseapi.h>
#include <string>
#include <fstream>

namespace StarEditor
{
	class AssetUtils
	{
	public:
		static bool WriteFile(const char* dataPtr, const size_t dataLength, const std::string& assetPath);
	};
}