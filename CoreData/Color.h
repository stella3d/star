#pragma once
#include <stdint.h>

namespace StarEngine
{
	enum ColorFormat { RGBA32, RGBA128 };

	struct Color
	{
	public:
		float r, g, b, a;
	};

	struct Color32
	{
	public: 
		uint8_t r, g, b, a;
	};
}
