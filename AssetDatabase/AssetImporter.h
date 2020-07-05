#pragma once
#include <string>
#include "AssetImportTask.h"

namespace StarEditor
{
	template <typename...> class AssetImporter;

	template <typename TAsset>

	class AssetImporter<TAsset>
	{
	public:
		AssetImporter() {}
		__declspec(dllexport) virtual AssetImportTask ImportFile(const std::string& path);
	};
}

