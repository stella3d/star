#pragma once
#include "Asset.h"

namespace StarEditor
{
	class AssetImportTask
	{
	public:
		AssetImportTask() {}
		explicit AssetImportTask(bool isComplete) : m_IsComplete(isComplete) {}

		/// <summary>
		/// The asset created by this import task (if successful)
		/// </summary>
		Asset asset;

		/// <summary>
		/// Short error describing what (if anything) went wrong during import
		/// </summary>
		std::string errorMessage;

		bool IsComplete();
		void SetComplete(bool complete);
		bool GetSuccess();

	private:
		bool m_IsComplete = false;
		bool m_Success = false;
	};
}