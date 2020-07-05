// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the COREUTILS_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// COREUTILS_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef COREUTILS_EXPORTS
#define COREUTILS_API __declspec(dllexport)
#else
#define COREUTILS_API __declspec(dllimport)
#endif

#include "MemoryHandle.h"

namespace StarEngine
{
	// This class is exported from the dll
	class COREUTILS_API MemoryHandle
	{
	public:
		MemoryHandle(void* ptr, const size_t length) : m_ptr(ptr), m_length(length) {}
		// TODO: add your methods here.

		void* GetPtr() { return m_ptr; }
		size_t GetLength() { return m_length; }


	private:
		void* m_ptr;
		size_t m_length;
	};

	// This class is exported from the dll
	class COREUTILS_API CoreUtils {
	public:
		CoreUtils(void);
		// TODO: add your methods here.
	};
}