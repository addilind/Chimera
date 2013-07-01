#include "runManager.hpp"

using namespace chimera::base;

RunManager::RunManager()
{

}

RunManager::RunManager(const RunManager& instance)
{

}

RunManager::~RunManager()
{

}

bool RunManager::Initialize()
{
	_activeSystems.push_back(std::shared_ptr<Subsystem>(new chimera::ui::Window()));

	_run = true;

	std::list<std::shared_ptr<Subsystem>>::const_iterator subsystem;
	for(subsystem = _activeSystems.begin(); subsystem != _activeSystems.end(); subsystem++)
	{
		if(!(*subsystem)->Initialize())
		{
			//ToDo: abort
		}
	}

	return true;
}

void RunManager::Shutdown()
{
	std::list<std::shared_ptr<Subsystem>>::const_iterator subsystem;
	for(subsystem = _activeSystems.begin(); subsystem != _activeSystems.end(); subsystem++)
	{
		(*subsystem)->Shutdown();
	}

}

void RunManager::Run()
{
	std::list<std::shared_ptr<Subsystem>>::const_iterator subsystem;
	while(_run)
	{
		for(subsystem = _activeSystems.begin(); subsystem != _activeSystems.end(); subsystem++)
		{
			(*subsystem)->Frame(0.0);
		}
	}
}
