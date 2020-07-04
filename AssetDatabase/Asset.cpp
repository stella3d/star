#include "pch.h"
#include <fstream>
#include "Asset.h"
#include "AssetUtils.h"

namespace StarEditor
{
	Asset::Asset() : m_id(AssetID::Create()), m_creationTime(std::time(NULL)) { }

	AssetID Asset::GetID()
	{
		return m_id;
	}

	bool Asset::Save(const void* dataPtr, size_t dataLength, const std::string& assetBinaryPath)
	{
		const char* charPtr = (char*)dataPtr;
		AssetUtils::WriteFile(charPtr, dataLength, assetBinaryPath);
		return false;
	}
}
