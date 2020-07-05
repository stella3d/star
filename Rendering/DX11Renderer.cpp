#include "DX11Renderer.h"

namespace StarEngine
{
	struct MeshGpuBuffers
	{
	public:
		ID3D11Buffer* vertex;
		ID3D11Buffer* index;
	};

	
	bool DX11Renderer::CreateMeshVertexAndIndexBuffers(const StandardMesh& mesh)
	{
		auto tris = mesh.triangles;
		ID3D11Buffer* indexBufferGPtr = CreateIndexBuffer(tris.data(), tris.size());
		
		auto verts = mesh.vertices;
		ID3D11Buffer* vertexBufferGPtr = CreateVertexBuffer(verts.data(), verts.size());
		return true;
	}

	ID3D11Buffer* DX11Renderer::CreateIndexBuffer(const uint32_t* dataPtr, const size_t elementCount)
	{
		D3D11_BUFFER_DESC bufferDesc = GetIndexBufferDescription(elementCount);
		D3D11_SUBRESOURCE_DATA resourceData = DX11Renderer::GetSubResourceDataForBuffer((void*) dataPtr);

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

	inline D3D11_SUBRESOURCE_DATA GetSubResourceDataForBuffer(const void* dataPtr)
	{
		D3D11_SUBRESOURCE_DATA srData;
		srData.pSysMem = dataPtr;
		srData.SysMemPitch = 0;
		srData.SysMemSlicePitch = 0;
		return srData;
	}

	template<typename TVertex>
	inline D3D11_BUFFER_DESC DX11Renderer::GetVertexBufferDescription<TVertex>(unsigned int elementCount)
	{
		D3D11_BUFFER_DESC bufferDesc = *&vertexBufferDescription; // copy a desc with most things setup
		bufferDesc.ByteWidth = sizeof(TVertex) * elementCount;
		return bufferDesc;
	}

	inline D3D11_BUFFER_DESC DX11Renderer::GetIndexBufferDescription(unsigned int elementCount)
	{
		D3D11_BUFFER_DESC bufferDesc = *&indexBufferDescription; // copy a desc with most things  setup
		bufferDesc.ByteWidth = sizeof(unsigned int) * elementCount;
		return bufferDesc;
	}
}