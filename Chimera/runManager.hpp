#pragma once

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <list>
#include "subsystem.hpp"

namespace chimera
{
	namespace base
	{
		class RunManager
		{
		public:
			RunManager();
			RunManager(const RunManager&);
			~RunManager();

			bool Initialize();
			void Shutdown();
			void Run();

			LRESULT CALLBACK MessageHandler(HWND, UINT, WPARAM, LPARAM);
			
		private:
			std::list<Subsystem> _activeSystems;
		};
		
		static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
	}
}