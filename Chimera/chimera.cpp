// chimera.cpp : Defines the entry point for the console application.
//

#include "chimera.hpp"

using chimera::base::RunManager;
using std::shared_ptr;

int _tmain(int argc, _TCHAR* argv[])
{
	shared_ptr<RunManager> Manager = std::shared_ptr<RunManager>(new RunManager());
		
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
