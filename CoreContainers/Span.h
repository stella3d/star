#pragma once

namespace StarEngine
{
	// i know std::span exists in c++20 but it's not done yet
	template <typename TValue>
	struct Span
	{
		const TValue* ptr;
		const size_t count;

		Span(TValue* ptr, size_t count) : ptr(ptr), count(count) {}

		TValue operator [](size_t i) { return ptr[i]; }

		size_t size() const { return sizeof(TValue) * count; }
	};
}
