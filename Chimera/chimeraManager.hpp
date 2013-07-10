//runManager.hpp
#pragma once

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <list>
#include <memory>
#include "subsystem.hpp"
#include "runManager.hpp"
#include <SDKDDKVer.h>
#include <tchar.h>

namespace chimera
{
	namespace base
	{
		class ChimeraManager : public RunManager, public std::enable_shared_from_this<ChimeraManager>
		{
		public:
			ChimeraManager();
			ChimeraManager(const ChimeraManager&);
			~ChimeraManager();

			void Initialize();
			void Shutdown();
			void Run();

			virtual void Quit();
			
		private:
			std::list<std::shared_ptr<Subsystem>> _activeSystems;
			bool _run;
		};
	}
}