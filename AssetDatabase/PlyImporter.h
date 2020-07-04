#pragma once
#include <memory>
#include <vector>
#include <fstream>
#include <iostream>
#include <chrono>
#include "AssetImportTask.h"
#include "MeshAssetImporter.h"
#include "FloatVectors.h";

#include "Dependencies/tinyply/tinyply.h"
using namespace tinyply;

namespace StarEditor
{
    class PlyImporter : MeshAssetImporter
    {
    public:
        AssetImportTask ImportFile(const std::string& path) override;

    private:
        void ReadPlyFile(const std::string& filepath, const bool preload_into_memory = true);
    };
}