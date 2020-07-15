#pragma once
#include <stddef.h>

namespace StarEngine { namespace Memory
{
	class Allocator
	{
    public:

        /** Return a pointer to 's' bytes of memory that are unused by
            the rest of the program.  The contents are undefined */
        virtual void* Alloc(size_t s) { return NULL; }

        /** Free() an existing chunk of memory and allocate a new one of size 'newSize' */
        virtual void* Realloc(void* ptr, size_t newSize) { return NULL; }

        //Declare that this memory will no longer be used by the program.
        virtual void Free(void* ptr) {}

        // Get the instance of this allocator
        inline static Allocator& Get()
        { 
            static Allocator instance;
            return instance; 
        }
    private:
        //typedef std::shared_ptr<class Allocator> Ref;
        //static Ref s_instance;
	};

    // General-purpose allocator, a fast replacement for malloc
    // Currently wraps Microsoft's 'mimalloc' - https://github.com/microsoft/mimalloc
    class GeneralAllocator : Allocator
    {
    public:
        inline void* Alloc(size_t size) override;
        
        inline void* Realloc(void* ptr, size_t size) override;
        
        inline void Free(void* ptr) override;

        inline static GeneralAllocator Get() {
            static GeneralAllocator instance;
            return instance;
        }
    };

    // static wrappers for the general allocator
    static void gAlloc(const size_t size);
    static void gRealloc(void* ptr, const size_t size);
    static void gFree(void* ptr);
}}