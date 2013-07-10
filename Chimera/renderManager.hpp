#pragma once

#include <dxgi.h>
#include <d3dcommon.h>
#include <d3d11_1.h>
#include <DirectXMath.h>
#include <memory>
#include <string>
#include <boost/lexical_cast.hpp>
#include "exception.hpp"
#include "comDeleter.hpp"

using std::shared_ptr;

namespace chimera
{
	namespace ui
	{
		class RenderManager
		{
		public:
			void Initialize(HWND hwnd);
			void Shutdown();

			void Render();

		private:
			int _videoCardMemory;
			char _videoCardDescription[128];
			shared_ptr<IDXGISwapChain> _swapChain;
			shared_ptr<ID3D11Device> _device;
			shared_ptr<ID3D11DeviceContext> _deviceContext;
			shared_ptr<ID3D11RenderTargetView> _renderTargetView;
			shared_ptr<ID3D11Texture2D> _depthStencilBuffer;
			shared_ptr<ID3D11DepthStencilState> _depthStencilState;
			shared_ptr<ID3D11DepthStencilView> _depthStencilView;
			shared_ptr<ID3D11RasterizerState> _rasterState;
			DirectX::XMFLOAT4X4 _projectionMatrix;
			DirectX::XMFLOAT4X4 _worldMatrix;
		};
	}
}