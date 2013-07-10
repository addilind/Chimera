#include "chimeraManager.hpp"

#include "window.hpp"

using namespace chimera::base;

ChimeraManager::ChimeraManager()
{

}

ChimeraManager::ChimeraManager(const ChimeraManager& instance)
{

}

ChimeraManager::~ChimeraManager()
{

}

void ChimeraManager::Initialize()
{
	_activeSystems.push_back(std::shared_ptr<Subsystem>(new chimera::ui::Window(shared_from_this())));

	_run = true;

	std::list<std::shared_ptr<Subsystem>>::const_iterator subsystem;
	for(subsystem = _activeSystems.begin(); subsystem != _activeSystems.end(); subsystem++)
	{
		(*subsystem)->Initialize();
	}
}

void ChimeraManager::Shutdown()
{
	std::list<std::shared_ptr<Subsystem>>::const_iterator subsystem;
	for(subsystem = _activeSystems.begin(); subsystem != _activeSystems.end(); subsystem++)
	{
		(*subsystem)->Shutdown();
	}

}

void ChimeraManager::Run()
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

void ChimeraManager::Quit()
{
	_run = false;
}