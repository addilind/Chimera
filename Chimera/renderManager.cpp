#include "renderManager.hpp"

#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3d11.lib")

using chimera::ui::RenderManager;
using chimera::helper::Exception;
using chimera::helper::ComDeleter;

void RenderManager::Initialize(HWND hwnd)
{
	HRESULT result;

	IUnknown* output;
	shared_ptr<IDXGIFactory> factory;	//shared_ptr instead of unique_ptr because deleter-implementation is simpler
	shared_ptr<IDXGIAdapter> adapter;
	shared_ptr<IDXGIOutput> adapterOutput;
	unsigned int numModes, i, numerator, denominator, stringLength;
	DXGI_MODE_DESC* displayModeList;
	DXGI_ADAPTER_DESC adapterDesc;
	int error;
	DXGI_SWAP_CHAIN_DESC swapChainDesc;
	D3D_FEATURE_LEVEL featureLevel;
	ID3D11Texture2D* backBufferPtr;
	D3D11_TEXTURE2D_DESC depthBufferDesc;
	D3D11_DEPTH_STENCIL_DESC depthStencilDesc;
	D3D11_DEPTH_STENCIL_VIEW_DESC depthStencilViewDesc;
	D3D11_RASTERIZER_DESC rasterDesc;
	D3D11_VIEWPORT viewport;
	float fieldOfView, screenAspect;

	// Create a DirectX graphics interface factory.
	result = CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)&output);
	if(FAILED(result))
	{
		throw Exception(L"Unable to create DXGIFactory, result "+ boost::lexical_cast<std::wstring>(result));
	}
	output->AddRef();
	factory.reset(reinterpret_cast<IDXGIFactory*>(output), ComDeleter());

	// Use the factory to create an adapter for the primary graphics interface (video card).
	result = factory->EnumAdapters(0, (IDXGIAdapter**)&output);
	if(FAILED(result))
	{
		throw Exception(L"Unable to get primary adapter, result "+ boost::lexical_cast<std::wstring>(result));
	}
	output->AddRef();
	adapter.reset(reinterpret_cast<IDXGIAdapter*>(output), ComDeleter());

	// Enumerate the primary adapter output (monitor).
	result = adapter->EnumOutputs(0, (IDXGIOutput**)&output);
	if(FAILED(result))
	{
		throw Exception(L"Unable to get primary display, result "+ boost::lexical_cast<std::wstring>(result));
	}
	output->AddRef();
	adapterOutput.reset(reinterpret_cast<IDXGIOutput*>(output), ComDeleter());

	// Get the number of modes that fit the DXGI_FORMAT_R8G8B8A8_UNORM display format for the adapter output (monitor).
	result = adapterOutput->GetDisplayModeList(DXGI_FORMAT_R8G8B8A8_UNORM, DXGI_ENUM_MODES_INTERLACED, &numModes, NULL);
	if(FAILED(result))
	{
		throw Exception(L"Unable to get primary display mode count, result "+ boost::lexical_cast<std::wstring>(result));
	}

	// Create a list to hold all the possible display modes for this monitor/video card combination.
	displayModeList = new DXGI_MODE_DESC[numModes];
	assert(displayModeList);

	// Now fill the display mode list structures.
	result = adapterOutput->GetDisplayModeList(DXGI_FORMAT_R8G8B8A8_UNORM, DXGI_ENUM_MODES_INTERLACED, &numModes, displayModeList);
	if(FAILED(result))
	{
		throw Exception(L"Unable to get primary display modes, result "+ boost::lexical_cast<std::wstring>(result));
	}

	// Now go through all the display modes and find the one that matches the screen width and height.
	// When a match is found store the numerator and denominator of the refresh rate for that monitor.
	for(i=0; i<numModes; i++)
	{
		/*if(displayModeList[i].Width == (unsigned int)screenWidth)
		{
			if(displayModeList[i].Height == (unsigned int)screenHeight)
			{
				numerator = displayModeList[i].RefreshRate.Numerator;
				denominator = displayModeList[i].RefreshRate.Denominator;
			}
		}*/
	}
}

void RenderManager::Shutdown()
{

}