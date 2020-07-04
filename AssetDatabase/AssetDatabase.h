#pragma once
#include <string>
#include <unordered_map>
#include "Asset.h"
#include "AssetID.h"
#include "AssetUtils.h"

#define DllExport __declspec( dllexport )

namespace StarEditor
{
	enum SaveCommandAction { None, Created, Moved };

	class DllExport AssetDatabase
	{
	public:

		const std::string headerFileExtension = ".asset";

		std::string GetRootPath();
		enum SaveCommandAction SaveAsset(Asset asset, std::string relativePath);

	private:
		std::string m_rootPath;

		/// <summary>
		/// Maps from asset GUID to the relative (to the project root) path where its binary data is stored
		/// </summary>
		std::unordered_map<AssetID, std::string> idToRelativePath = {};
	};

}
