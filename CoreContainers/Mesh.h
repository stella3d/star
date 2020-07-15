#pragma once
#include <vector>
#include <climits>
#include <FloatVectors.h>
#include <Color.h>
#include "Array.h"

namespace StarEngine
{
	enum MeshIndexFormat { UInt16, UInt32 };

	template <typename...> class Mesh;

	template <typename TIndex, typename TColor>

	class __declspec(dllexport) Mesh<TIndex, TColor>
	{
	public:
		Array<float3> vertices;
		Array<float3> normals;
		Array<float2> uv;

		Array<TIndex> triangles;
		Array<TColor> colors;

		Mesh(std::vector<float3> verts, std::vector<float3> norms, std::vector<TIndex> tris)
		{
			vertices = Array<float3>(verts.data(), verts.size());
			normals = Array<float3>(norms.data(), norms.size());
			triangles = Array<TIndex>(tris.data(), tris.size());
			uv = NULL;
			colors = NULL;
		}

		Mesh(std::vector<float3> verts, std::vector<float3> norms, std::vector<TIndex> tris, 
			 std::vector<float2> uvs, std::vector<TColor> colorsValue)
		{
			vertices = Array<float3>(verts.data(), verts.size());
			normals = Array<float3>(norms.data(), norms.size());
			triangles = Array<TIndex>(tris.data(), tris.size());
			uv = Array<float2>(uvs.data(), uvs.size());
			colors = Array<TColor>(colorsValue.data(), colorsValue.size());
		}

		inline size_t GetGpuResourceIndex() { return m_gpuResourceIndex; }

		/// <summary>This should only be called by a Renderer</summary>
		inline void SetGpuResourceIndex(size_t index)
		{
			// don't allow setting this more than once
			if(m_gpuResourceIndex == 0)
				m_gpuResourceIndex = index;
		}


	private:

		/// <summary>
		/// This should only ever be set when the mesh gpu resources are created 
		/// </summary>
		size_t m_gpuResourceIndex = 0;
	};

	/// <summary>
	/// Mesh using 16-bit indices and RGBA32 vertex colors
	/// </summary>
	using StandardMesh = Mesh<uint16_t, Color32>;
}
