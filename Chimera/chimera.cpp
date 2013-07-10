// chimera.cpp : Defines the entry point for the console application.
//

#include "chimera.hpp"

using chimera::base::ChimeraManager;
using std::shared_ptr;

int _tmain(int argc, _TCHAR* argv[])
{
	//ToDo: interpret args
#ifndef DEBUG
	FreeConsole();
#endif

	shared_ptr<ChimeraManager> manager = std::shared_ptr<ChimeraManager>(new ChimeraManager());
		
	if(!manager)
	{
		return 1;
	}

	manager->Initialize();
	manager->Run();
	manager->Shutdown();
	return 0;
}
