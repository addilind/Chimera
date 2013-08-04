#pragma once

#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <dxgi.h>
#include <d3dcommon.h>
#include <d3d11_1.h>
#include <DirectXMath.h>
#include <atlbase.h>
#include <string>
#include <boost/lexical_cast.hpp>
#include "exception.hpp"


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
			std::wstring _videoCardDescription;
			CComPtr<IDXGISwapChain> _swapChain;
			CComPtr<ID3D11Device> _device;
			CComPtr<ID3D11DeviceContext> _deviceContext;
			CComPtr<ID3D11RenderTargetView> _renderTargetView;
			CComPtr<ID3D11Texture2D> _depthStencilBuffer;
			CComPtr<ID3D11DepthStencilState> _depthStencilState;
			CComPtr<ID3D11DepthStencilView> _depthStencilView;
			CComPtr<ID3D11RasterizerState> _rasterState;
			DirectX::XMMATRIX _projectionMatrix;
		};
	}
}