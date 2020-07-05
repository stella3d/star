#pragma once
#include <memory>
#include "DeviceResources.h"
#include "Renderer.h"
#include <Mesh.h>
#include <d3d11.h>
#include <d3d11_4.h>

using namespace DirectX;
using namespace DX;

namespace StarEngine
{
	class DX11Renderer : public Renderer, public DX::IDeviceNotify
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

			// TODO: Change the timer settings if you want something other than the default variable timestep mode.
			// e.g. for 60 FPS fixed timestep update logic, call:
			/*
			m_timer.SetFixedTimeStep(true);
			m_timer.SetTargetElapsedSeconds(1.0 / 60);
			*/
		}

		bool CreateMeshVertexAndIndexBuffers(const StandardMesh& mesh);

	private:
		std::unique_ptr<DX::DeviceResources> m_deviceResources;

		/// <summary>
		/// 
		/// </summary>
		std::unique_ptr<ID3D11Device> g_D11Device;

		D3D11_BUFFER_DESC indexBufferDescription = *new D3D11_BUFFER_DESC();
		D3D11_BUFFER_DESC vertexBufferDescription = *new D3D11_BUFFER_DESC();

		template<typename TVertex>
		ID3D11Buffer* CreateVertexBuffer<TVertex>(const TVertex* dataPtr, const size_t length);

		ID3D11Buffer* CreateIndexBuffer(const uint32_t* dataPtr, const size_t length) override;

		void InitBufferDescriptions();
		D3D11_BUFFER_DESC GetIndexBufferDescription(unsigned int elementCount);


		template<typename TVertex>
		D3D11_BUFFER_DESC GetVertexBufferDescription(unsigned int elementCount);

		D3D11_SUBRESOURCE_DATA GetSubResourceDataForBuffer(const void* dataPtr);
	};

}


