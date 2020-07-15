#pragma once
#include <FloatVectors.h>

namespace StarEngine
{
	/// <summary>
	/// Row-major 4x4 single precision matrix
	/// </summary>
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


