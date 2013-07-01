//chimera.hpp

#pragma once

#include <SDKDDKVer.h>
#include <tchar.h>
#include "runManager.hpp"
#include <memory>

using std::shared_ptr;

namespace chimera
{
	namespace base 
	{
		extern shared_ptr<RunManager> Manager;
	}
}

//Console-Entrypoint
int _tmain(int argc, _TCHAR* argv[]);
