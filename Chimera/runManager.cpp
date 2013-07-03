#include "runManager.hpp"

#include "window.hpp"

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

bool RunManager::Initialize(std::shared_ptr<RunManager> selfref)
{
	_activeSystems.push_back(std::shared_ptr<Subsystem>(new chimera::ui::Window(selfref)));

	_run = true;

	std::list<std::shared_ptr<Subsystem>>::const_iterator subsystem;
	for(subsystem = _activeSystems.begin(); subsystem != _activeSystems.end(); subsystem++)
	{
		if(!(*subsystem)->Initialize())
		{
			_run = false;
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

void RunManager::Quit()
{
	_run = false;
}