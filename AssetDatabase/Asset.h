#pragma once
#include <string>
#include "AssetUtils.h"
#include <ctime>

namespace StarEditor
{
	class Asset
	{
	public:
		Asset();

		Asset(std::string sourcePath)
			: m_sourcePath(sourcePath), m_guid(AssetUtils::NewGUID()), m_creationTime(std::time(NULL)) { }

		GUID GetGuid();

		// TODO - replace bool states for I/O operations with an IOResult class or similar
		bool Save(const void* dataPtr, size_t dataLength, const std::string& assetPath);

	private:
		GUID m_guid;
		std::time_t m_creationTime;

		std::string m_sourcePath;
		std::string m_assetPath;
	};
}


