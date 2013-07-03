// chimera.cpp : Defines the entry point for the console application.
//

#include "chimera.hpp"

using chimera::base::RunManager;
using std::shared_ptr;

int _tmain(int argc, _TCHAR* argv[])
{
	shared_ptr<RunManager> manager = std::shared_ptr<RunManager>(new RunManager());
		
	if(!manager)
	{
		return 1;
	}

	bool result = manager->Initialize(manager);
	if(result)
	{
		manager->Run();
	}

	manager->Shutdown();
	return 0;
}
