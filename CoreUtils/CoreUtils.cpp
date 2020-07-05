// CoreUtils.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "CoreUtils.h"

namespace StarEngine
{
    // This is an example of an exported variable
    COREUTILS_API int nCoreUtils = 0;

    // This is an example of an exported function.
    COREUTILS_API int fnCoreUtils(void)
    {
        return 0;
    }

    // This is the constructor of a class that has been exported.
    CoreUtils::CoreUtils()
    {
        return;
    }
}

