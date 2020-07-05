#pragma once
#include <FloatVectors.h>

namespace StarEngine
{
	struct Matrix4x4
	{
	public:
		float4 GetColumn()
		{
		}
		float4 GetRow()
		{
		}

		float4 SetColumn()
		{
		}

		float4 SetRow()
		{
		}

		float3 GetTranslation()
		{
			return *(float3*) &matrix[12];
		}

	private:
		float matrix[16];
	};
}


