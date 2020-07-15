#pragma once
#include <memory>
#include <unordered_map>
#include "DeviceResources.h"
#include "RendererData.h"
#include "Mesh.h"
#include <d3d11.h>
#include <Matrices.h>

#pragma comment( lib, "d3d11.lib" )     // direct3D library
#pragma comment( lib, "dxgi.lib" )        // directx graphics interface
#pragma comment( lib, "d3dcompiler.lib" ) // shader compiler

using namespace DirectX;
using namespace DX;

namespace StarEngine { namespace Rendering { namespace DX11
{
	class DX11Renderer : /*public Renderer,*/ public DX::IDeviceNotify
	{
	public:
		DX11Renderer() noexcept(false)
		{
			m_deviceResources = std::make_unique<DX::DeviceResources>();
			m_deviceResources->RegisterDeviceNotify(this);
		}

		void Initialize(HWND window, int width, int height)
		{
			m_deviceResources->SetWindow(window, width, height);

			m_deviceResources->CreateDeviceResources();
			//CreateDeviceDependentResources();

			m_deviceResources->CreateWindowSizeDependentResources();
			//CreateWindowSizeDependentResources();

			// TODO - abstract out the timer code to be independent of DX
			// TODO: Change the timer settings if you want something other than the default variable timestep mode.
			// e.g. for 60 FPS fixed timestep update logic, call:
			//m_timer.SetFixedTimeStep(true);
			// m_timer.SetTargetElapsedSeconds(1.0 / 60);
		}

		bool CreateMeshGpuResources(StandardMesh& mesh);

		/// <summary>
		/// Create a GPU buffer of all the transform matrices required to draw this mesh
		/// </summary>
		/// <param name="mesh">the mesh to associate this transform buffer with</param>
		/// <param name="objectToWorldSpace">pointer to an array of object-to-world transform matrices</param>
		/// <param name="instanceCount">the number of elements in the objectToWorldSpace array.  only > 1 if this mesh will be instanced</param>
		/// <returns></returns>
		bool CreateMeshTransformBuffer(const StandardMesh& mesh, const Matrix4x4* objectToWorldSpace, const uint32_t instanceCount = 1);

	private:
		std::unique_ptr<DX::DeviceResources> m_deviceResources;

		std::unique_ptr<ID3D11Device> g_D11Device;

		std::vector<MeshGpuBuffers> m_meshGpuResources;

		XMFLOAT4X4 m_viewMatrix;
		XMFLOAT4X4 m_projectionMatrix;

		D3D11_BUFFER_DESC indexBufferDescription = *new D3D11_BUFFER_DESC();
		D3D11_BUFFER_DESC vertexBufferDescription = *new D3D11_BUFFER_DESC();

		template<typename TVertex>
		ID3D11Buffer* CreateVertexBuffer(const TVertex* dataPtr, const size_t length);

		template<typename TIndex>
		ID3D11Buffer* CreateIndexBuffer(const TIndex* dataPtr, const size_t length);

		ID3D11Buffer* CreateTransformConstantBuffer(const TransformConstantBuffer* dataPtr);

		void InitBufferDescriptions();

		template<typename TIndex>
		D3D11_BUFFER_DESC GetIndexBufferDescription(unsigned int elementCount);

		template<typename TVertex>
		D3D11_BUFFER_DESC GetVertexBufferDescription(unsigned int elementCount);

		TransformConstantBuffer* GetTransformMatrices(const XMFLOAT4X4& objectToWorldSpace);

		void LinkMeshResources(StandardMesh& mesh, const MeshGpuBuffers& buffers);
	};
}}}


