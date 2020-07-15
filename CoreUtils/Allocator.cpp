#include "Allocator.h"
#include <mimalloc.h>
// IMPORTANT: (supposedly) including this causes the global 'new' and 'delete' operators to use mimalloc
#include <mimalloc-new-delete.h>

namespace StarEngine { namespace Memory
{
    inline void* GeneralAllocator::Alloc(size_t size)
    {
        return mi_malloc(size);
    }

    inline void* GeneralAllocator::Realloc(void* ptr, size_t size)
    {
        return mi_realloc(ptr, size);
    }

    inline void GeneralAllocator::Free(void* ptr)
    {
        mi_free(ptr);
    }

    // static wrappers for the general allocator
    static void gAlloc(const size_t size) { mi_malloc(size); }
    static void gRealloc(void* ptr, const size_t size) { mi_realloc(ptr, size); }
    static void gFree(void* ptr) { mi_free(ptr); }
}}