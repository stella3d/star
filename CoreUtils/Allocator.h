#pragma once
#include <memory>
#include <mimalloc.h>
#include <mimalloc-new-delete.h>

namespace StarEngine
{
	class COREUTILS_API Allocator
	{
    public:
        typedef std::shared_ptr<class Allocator> Ref;

        /** Return a pointer to 's' bytes of memory that are unused by
            the rest of the program.  The contents are undefined */
        virtual void* Alloc(size_t s) { return NULL; }

        /** Free() an existing chunk of memory and allocate a new one of size 'newSize' */
        virtual void* Realloc(void* ptr, size_t newSize) { return NULL; }

        /** Declare that this memory will no longer be used by
            the program.  The allocator is not required to actually
            reuse or release this memory. */
        virtual void Free(void* ptr) {}
	};

    // General-purpose allocator, a fast replacement for malloc
    // Currently wraps Microsoft's 'mimalloc' - https://github.com/microsoft/mimalloc
    class COREUTILS_API GeneralAllocator : Allocator
    {
    public:
        inline void* Alloc(size_t size) override
        {
            return mi_malloc(size);
        }

        inline void* Realloc(void* ptr, size_t size) override
        {
            return mi_realloc(ptr, size);
        }

        inline void Free(void* ptr) override
        {
            mi_free(ptr);
        }
    };

    // should only be used as a fallback
    class COREUTILS_API Mallocator : Allocator
    {
    public:
        inline void* Alloc(size_t size) override
        {
            return malloc(size);
        }

        inline void* Realloc(void* ptr, size_t size) override
        {
            return realloc(ptr, size);
        }

        inline void Free(void* ptr) override
        {
            free(ptr);
        }
    };
}