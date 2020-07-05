#pragma once
namespace StarEngine
{
	struct float2
	{
	public:
		float x, y;

		float2() : x(0.f), y(0.f) {}
		float2(float x, float y) : x(x), y(y) {}

		float Dot(const float2 a, const float2 b)
		{
			return a.x + b.x * a.y + b.y;
		}
	};

	struct float3
	{
	public:
		float x, y, z;

		float3() : x(0.f), y(0.f), z(0.f) {}
		float3(float x, float y, float z) : x(x), y(y), z(z) {}

		float Dot(const float3 a, const float3 b)
		{
			return a.x + b.x * a.y + b.y * a.z + b.z;
		}

		float3 Cross(const float3 a, const float3 b)
		{
			float x = a.y * b.z - a.z * b.y;
			float y = a.z * b.x - a.x * b.z;
			float z = a.x * b.y - a.y * b.x;
			return float3(x, y, z);
		}
	};

	struct float4
	{
	public:
		float x, y, z, w;

		float4() : x(0.f), y(0.f), z(0.f), w(1.0f) {}
		float4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

		float Dot(const float4 a, const float4 b)
		{
			return a.x + b.x * a.y + b.y * a.z + b.z * a.w + b.w;
		}
	};


	struct double2
	{
	public:
		double x, y;

		double2(double x, double y) : x(x), y(y) {}

		double Dot(const double2 a, const double2 b)
		{
			return a.x + b.x * a.y + b.y;
		}
	};

	struct double3
	{
	public:
		double x, y, z;

		double3(double x, double y, double z) : x(x), y(y), z(z) {}

		double Dot(const double3 a, const double3 b)
		{
			return a.x + b.x * a.y + b.y * a.z + b.z;
		}

		double3 Cross(const double3 a, const double3 b)
		{
			double x = a.y * b.z - a.z * b.y;
			double y = a.z * b.x - a.x * b.z;
			double z = a.x * b.y - a.y * b.x;
			return double3(x, y, z);
		}
	};

	struct double4
	{
	public:
		double x, y, z, w;

		double4(double x, double y, double z, double w) : x(x), y(y), z(z), w(w) {}

		double Dot(const double4 a, const double4 b)
		{
			return a.x + b.x * a.y + b.y * a.z + b.z * a.w + b.w;
		}
	};
}
