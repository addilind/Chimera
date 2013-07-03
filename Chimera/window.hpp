#pragma once

#define WIN32_LEAN_AND_MEAN

#include "subsystem.hpp"
#include <Windows.h>
#include <memory>
#include "runManager.hpp"

namespace chimera
{
	namespace ui
	{
		class Window : public chimera::base::Subsystem
		{
		public:
			Window(std::shared_ptr<chimera::base::RunManager> manager);
			~Window();

			virtual bool Initialize();
			virtual void Shutdown();
			virtual void Frame(double deltaT);
			
			LRESULT CALLBACK MessageHandler(HWND, UINT, WPARAM, LPARAM);
		private:
			LPCWSTR _applicationName;
			HINSTANCE _hinstance;
			HWND _hwnd;
			MSG _msg;
		};
		
		static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

		static Window* InstanceHandle = 0;
	}
}
