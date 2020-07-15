#pragma once
#include <d3d11.h>
#include <d3d11_4.h>
#include <DirectXMath.h>

using namespace DirectX;

namespace StarEngine { namespace Rendering { namespace DX11
{
	template<typename T>
		struct CpuInstanceDrawingBuffer
	{
	public:
		uint32_t count;
		uint32_t capacity;
		T* data;
	};

	struct MeshGpuBuffers
	{
	public:
		ID3D11Buffer* vertex;
		ID3D11Buffer* index;

		MeshGpuBuffers(ID3D11Buffer* v, ID3D11Buffer* i) : vertex(v), index(i) {}
	};

	struct TransformConstantBuffer
	{
	public:
		XMFLOAT4X4 model;
		XMFLOAT4X4 view;
		XMFLOAT4X4 projection;

		TransformConstantBuffer(XMFLOAT4X4 m, XMFLOAT4X4 v, XMFLOAT4X4 p): model(m), view(v), projection(p) {}
	};
}}}
