// chimera.cpp : Defines the entry point for the console application.
//

#include "chimera.hpp"
#include <boost\date_time\posix_time\posix_time.hpp>

int _tmain(int argc, _TCHAR* argv[])
{
	for(int i = 1; i < argc; i++)
	{
		std::wstring s = argv[i];
		std::wcout << s << std::endl;
	}

	std::shared_ptr

	#ifndef _DEBUG
	FreeConsole();
	#endif
	for(int i = 0; i < 10; i++)
	{
		std::cout << i;
		boost::this_thread::sleep(boost::posix_time::milliseconds(1000));
	}
	return 0;
}

