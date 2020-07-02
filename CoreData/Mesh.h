#pragma once
#include <vector>
#include <FloatVectors.h>
#include <Color.h>

namespace StarEngine
{
	enum MeshIndexFormat { UInt16, UInt32 };

	template <typename...> class Mesh;

	template <typename TIndex, typename TColor>

	class Mesh<TIndex, TColor>
	{
	public:
		std::vector<float3> vertices;
		std::vector<float3> normals;
		std::vector<float2> uv;
		std::vector<int> triangles;

		std::vector<TIndex> indices;
		std::vector<TColor> colors;
	};

	/// <summary>
	/// Mesh using 16-bit indices and RGBA32 vertex colors
	/// </summary>
	class StandardMesh : Mesh<uint16_t, Color32> {};
}
