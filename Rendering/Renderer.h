#pragma once
#include <FloatVectors.h>
#include <cstdint>

namespace StarEngine
{
	class Renderer
	{

	public:
		template<typename TVertex>
		ID3D11Buffer* CreateVertexBuffer(const TVertex* dataPtr, const size_t length);

		virtual ID3D11Buffer* CreateIndexBuffer(const uint32_t* dataPtr, const size_t length);
	};
}