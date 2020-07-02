#include "pch.h"
#include "AssetImportTask.h"

namespace StarEditor
{
    bool AssetImportTask::IsComplete()
    {
        return m_IsComplete;
    }

    void AssetImportTask::SetComplete(bool complete)
    {
        this->m_IsComplete = complete;
    }

    bool AssetImportTask::GetSuccess()
    {
        return false;
    }
}