//runManager.hpp
#pragma once

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <list>
#include <memory>
#include "subsystem.hpp"
#include "window.hpp"

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

			
		private:
			std::list<std::shared_ptr<Subsystem>> _activeSystems;
		};
	}
}