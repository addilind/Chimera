//runManager.hpp
#pragma once

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
			virtual ~RunManager() {};

			virtual void Quit() = 0;
		};
	}
}