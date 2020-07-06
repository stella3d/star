#pragma once
#include <string>
#include "AssetImportTask.h"

namespace StarEditor
{
	class AssetImporter
	{
	public:
		AssetImporter() {}
		__declspec(dllexport) virtual AssetImportTask ImportFile(const std::string& path);
	};
}

