//runManager.hpp
#pragma once

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <list>
#include <memory>
#include "subsystem.hpp"
#include <SDKDDKVer.h>
#include <tchar.h>

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

			bool Initialize(std::shared_ptr<RunManager> selfref);
			void Shutdown();
			void Run();

			void Quit();
			
		private:
			std::list<std::shared_ptr<Subsystem>> _activeSystems;
			bool _run;
		};
	}
}