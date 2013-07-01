// chimera.cpp : Defines the entry point for the console application.
//

#include "chimera.hpp"

using namespace chimera::base;

std::shared_ptr<RunManager> chimera::base::Manager;

int _tmain(int argc, _TCHAR* argv[])
{
	Manager = std::shared_ptr<RunManager>(new RunManager());
		
	if(!Manager)
	{
		return 1;
	}

	bool result = Manager->Initialize();
	if(result)
	{
		Manager->Run();
	}

	Manager->Shutdown();
	return 0;
}
