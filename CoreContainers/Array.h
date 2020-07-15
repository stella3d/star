#pragma once
#include <iterator>
#include <vector>
#include "Span.h"
#include "../CoreUtils/Allocator.h"

namespace StarEngine
{
	/// <summary>
	/// Abstraction of fixed-length array functionality - use this everywhere so swapping out implementations is easy.
	/// </summary>
	/// <typeparam name="T">Array element type</typeparam>
	template <typename T, class TAllocator = Memory::Allocator>
	//template <typename T>
	class __declspec(dllexport) Array
	{
	public:
		using value_type = T;
		using size_type = size_t;
		using difference_type = ptrdiff_t;
		using reference = value_type&;
		using const_reference = const value_type&;
		using pointer = value_type*;
		using const_pointer = const value_type*;

		typedef T* iterator;
		typedef const T* const_iterator;
		using reverse_iterator = std::reverse_iterator<iterator>;
		using const_reverse_iterator = std::reverse_iterator<const_iterator>;

		Array(const T* ptr, size_t elementCount);

		explicit Array(size_t elementCount, TAllocator allocator = TAllocator::Get());

		explicit Array(std::vector<T> vec, bool copy = true, TAllocator allocator = TAllocator::Get());

		iterator begin() { return (m_span.ptr, 0); }

		iterator end() { return (m_span.ptr, m_span.count); }

		inline T& operator [](size_t i) { return m_span[i]; }
		Array& operator =(Array<T> other) { this = other; return this; }

		inline size_t size() const { return m_span.count; }

		inline size_t max_size() const { return m_span.count; }
		
		inline T front() { return *m_span.ptr; }
		
		inline T back() { return *(m_span.ptr + (m_span.count - 1)); }

		inline T* data() { return m_span.ptr; }

		inline void fill(T value)
		{
			for (size_t i = 0; i < m_span.count; i++)
				m_span.ptr[i] = value;
		}

	private:
		const Span<T> m_span;
	};
}
