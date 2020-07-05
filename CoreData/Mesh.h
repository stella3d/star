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

		std::vector<TIndex> triangles;
		std::vector<TColor> colors;

		Mesh(std::vector<float3> verts, std::vector<float3> norms, std::vector<TIndex> tris)
		{
			vertices = verts;
			normals = norms;
			triangles = tris;
			uv = NULL;
			colors = NULL;
		}

		Mesh(std::vector<float3> verts, std::vector<float3> norms, std::vector<TIndex> tris, 
			 std::vector<float2> uvs, std::vector<TColor> colorsValue)
		{
			vertices = verts;
			normals = norms;
			triangles = tris;
			uv = uvs;
			colors = colorsValue;
		}
	};

	/// <summary>
	/// Mesh using 32-bit indices and RGBA32 vertex colors
	/// </summary>
	using StandardMesh = Mesh<uint32_t, Color32>;
}
