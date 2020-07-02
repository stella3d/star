#pragma once
#include <string>
#include "AssetImportTask.h"

namespace StarEditor
{
	class AssetImporter
	{
	public:
		virtual AssetImportTask ImportFile(const std::string& path);
	};
}

