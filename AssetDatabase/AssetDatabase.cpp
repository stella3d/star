#include "AssetDatabase.h"

namespace StarEditor
{
	std::string AssetDatabase::GetRootPath()
	{
		return m_rootPath;
	}

	enum SaveCommandAction AssetDatabase::SaveAsset(Asset asset, std::string relativePath)
	{
		AssetID assetId = asset.GetID();

		auto search = idToRelativePath.find(assetId);
		if (search != idToRelativePath.end())
		//if (guidToRelativePath.contains(assetId))
		{
			printf("found existing asset for GUID");
			printf(relativePath.c_str());
			return SaveCommandAction::None;
		}
		else
		{
			idToRelativePath.insert(std::pair<AssetID, std::string>(assetId, relativePath));
			// TODO - actually save asset to disk here
			return SaveCommandAction::Created;
		}

		return SaveCommandAction::None;
	}
}

