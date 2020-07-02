#pragma once
#include <string>
#include <combaseapi.h>
#include <string>
#include <fstream>

namespace StarEditor
{
	class AssetUtils
	{
	public:
		static GUID NewGUID();

		bool WriteFile(const char* dataPtr, const size_t dataLength, const std::string& assetPath);

	private:
		static GUID* s_NewGuidPtr;
	};
}