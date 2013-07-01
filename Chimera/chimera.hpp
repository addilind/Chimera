#pragma once

#include <SDKDDKVer.h>
#include <tchar.h>
#include <memory>
#include "runManager.hpp"

namespace chimera
{
	namespace base 
	{
		extern std::shared_ptr<RunManager> Manager;
	}
}

//Console-Entrypoint
int _tmain(int argc, _TCHAR* argv[]);
