#pragma once

namespace StarEngine
{
	COREUTILS_API struct MemoryHandle
	{
	public:
		const void* ptr;
		const size_t length;

		MemoryHandle(void* ptr, size_t length) : ptr(ptr), length(length) {}
	};
}
