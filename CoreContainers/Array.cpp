#include "Array.h"

namespace StarEngine
{
	template <typename T, typename TAllocator> 
	Array<T, TAllocator>::Array(const T* ptr, size_t elementCount)
	{
		m_span = Span<T>(ptr, elementCount);
	}

	template <typename T, typename TAllocator>
	Array<T, TAllocator>::Array(size_t elementCount, TAllocator allocator)
	{
		m_span = Span<T>(allocator.Alloc(sizeof(T) * elementCount), elementCount);
	}

	template <typename T, typename TAllocator>
	Array<T, TAllocator>::Array(std::vector<T> vec, bool copy, TAllocator allocator)
	{
		size_t elementCount = vec.size();
		if (copy)
		{
			size_t memSize = sizeof(T) * elementCount;
			T* copyTo = allocator.Alloc(memSize);
			memcpy(copyTo, vec.data(), memSize);
			m_span = Span<T>(copyTo, elementCount);
		}
		else
		{
			m_span = Span<T>(vec.data(), elementCount);
		}
	}
}