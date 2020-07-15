#include "DX11Renderer.h"

namespace StarEngine { namespace Rendering { namespace DX11
{
	inline XMFLOAT4X4 Convert(StarEngine::Matrix4x4 m)
	{
		return *(XMFLOAT4X4*)&m;
	}

	inline D3D11_BUFFER_DESC GetTransformConstantBufferDescription()
	{
		D3D11_BUFFER_DESC bufferDesc = { 0 };
		bufferDesc.ByteWidth = sizeof(TransformConstantBuffer);
		bufferDesc.Usage = D3D11_USAGE_DEFAULT;
		bufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		bufferDesc.CPUAccessFlags = 0;
		bufferDesc.MiscFlags = 0;
		bufferDesc.StructureByteStride = 0;
		return bufferDesc;
	}

	inline D3D11_SUBRESOURCE_DATA GetSubResourceDataForBuffer(const void* dataPtr)
	{
		D3D11_SUBRESOURCE_DATA srData;
		srData.pSysMem = dataPtr;
		srData.SysMemPitch = 0;
		srData.SysMemSlicePitch = 0;
		return srData;
	}
	
	bool DX11Renderer::CreateMeshGpuResources(StandardMesh& mesh)
	{
		auto tris = mesh.triangles;
		size_t triSize = tris.size();
		ID3D11Buffer* indexBufferGPtr = CreateIndexBuffer<uint16_t>(tris.data(), triSize);
		
		auto verts = mesh.vertices;
		size_t vertSize = verts.size();
		ID3D11Buffer* vertexBufferGPtr = CreateVertexBuffer<float3>(verts.data(), vertSize);

		MeshGpuBuffers buffers = MeshGpuBuffers(indexBufferGPtr, vertexBufferGPtr);
		LinkMeshResources(mesh, buffers);
		return true;
	}

	inline void DX11Renderer::LinkMeshResources(StandardMesh& mesh, const MeshGpuBuffers& buffers)
	{
		// TODO - be able to free indices in this list and use them for other meshes
		mesh.SetGpuResourceIndex(m_meshGpuResources.size());
		m_meshGpuResources.push_back(buffers);
	}

	template<typename TIndex>
	ID3D11Buffer* DX11Renderer::CreateIndexBuffer(const TIndex* dataPtr, const size_t elementCount)
	{
		D3D11_BUFFER_DESC bufferDesc = GetIndexBufferDescription<TIndex>(elementCount);
		D3D11_SUBRESOURCE_DATA resourceData = GetSubResourceDataForBuffer(dataPtr);

		ID3D11Buffer* newIndexBufferPtr = NULL;
		g_D11Device->CreateBuffer(&bufferDesc, &resourceData, &newIndexBufferPtr);
		return newIndexBufferPtr;
	}

	template<typename TVertex>
	ID3D11Buffer* DX11Renderer::CreateVertexBuffer(const TVertex* dataPtr, const size_t vertexCount)
	{
		D3D11_BUFFER_DESC bufferDesc = GetVertexBufferDescription<TVertex>(vertexCount);
		D3D11_SUBRESOURCE_DATA resourceData = GetSubResourceDataForBuffer(dataPtr);

		ID3D11Buffer* newVertexBufferPtr = NULL;
		g_D11Device->CreateBuffer(&bufferDesc, &resourceData, &newVertexBufferPtr);
		return newVertexBufferPtr;
	}

	ID3D11Buffer* DX11Renderer::CreateTransformConstantBuffer(const TransformConstantBuffer* dataPtr)
	{
		D3D11_BUFFER_DESC bufferDesc = GetTransformConstantBufferDescription();
		D3D11_SUBRESOURCE_DATA resourceData = GetSubResourceDataForBuffer(dataPtr);

		ID3D11Buffer* newBufferPtr = NULL;
		g_D11Device->CreateBuffer(&bufferDesc, &resourceData, &newBufferPtr);
		return newBufferPtr;
	}
	
	void DX11Renderer::InitBufferDescriptions()
	{
		vertexBufferDescription.Usage = D3D11_USAGE_DEFAULT;
		vertexBufferDescription.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		vertexBufferDescription.CPUAccessFlags = 0;
		vertexBufferDescription.MiscFlags = 0;

		indexBufferDescription.Usage = D3D11_USAGE_DEFAULT;
		indexBufferDescription.BindFlags = D3D11_BIND_INDEX_BUFFER;
		indexBufferDescription.CPUAccessFlags = 0;
		indexBufferDescription.MiscFlags = 0;
	}

	template<typename TVertex>
	inline D3D11_BUFFER_DESC DX11Renderer::GetVertexBufferDescription(const unsigned int elementCount)
	{
		D3D11_BUFFER_DESC bufferDesc = *&vertexBufferDescription; // copy a desc with most things setup
		bufferDesc.ByteWidth = sizeof(TVertex) * elementCount;
		return bufferDesc;
	}

	template<typename TIndex>
	inline D3D11_BUFFER_DESC DX11Renderer::GetIndexBufferDescription(const unsigned int elementCount)
	{
		D3D11_BUFFER_DESC bufferDesc = *&indexBufferDescription; // copy a desc with most things setup
		bufferDesc.ByteWidth = sizeof(TIndex) * elementCount;
		return bufferDesc;
	}

	inline TransformConstantBuffer* DX11Renderer::GetTransformMatrices(const XMFLOAT4X4& objectToWorldSpace)
	{
		return new TransformConstantBuffer(objectToWorldSpace, m_viewMatrix, m_projectionMatrix);
	}
}}}