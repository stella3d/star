#include "pch.h"
#include <fstream>
#include "Asset.h"
#include "AssetUtils.h"

namespace StarEditor
{
	Asset::Asset() : m_guid(AssetUtils::NewGUID()) { }

	GUID Asset::GetGuid()
	{
		return m_guid;
	}

	bool Asset::Save(const void* dataPtr, size_t dataLength, const std::string& assetPath)
	{
		const char* charPtr = (char*)dataPtr;

		return false;
	}
}
