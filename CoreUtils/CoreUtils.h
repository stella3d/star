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
#include "Allocator.h"

namespace StarEngine
{
	// This class is exported from the dll
	class COREUTILS_API CoreUtils {
	public:
		CoreUtils(void);
		// TODO: add your methods here.
	};
}