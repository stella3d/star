#pragma once
#include <string>
#include <ctime>
#include "AssetUtils.h"
#include "AssetID.h"

namespace StarEditor
{
	class __declspec(dllexport) Asset
	{
		AssetID m_id;

	public:
		Asset();

		Asset(std::string sourcePath)
			: m_sourcePath(sourcePath), m_creationTime(std::time(NULL)) { }

		AssetID GetID();

		// TODO - replace bool states for I/O operations with an IOResult class or similar
		bool Save(const void* dataPtr, size_t dataLength, const std::string& assetPath);

	private:
		std::time_t m_creationTime;

		std::string m_sourcePath;
		std::string m_assetPath;
	};
}


