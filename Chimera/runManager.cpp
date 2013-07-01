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

	return true;
}

void RunManager::Shutdown()
{

}

void RunManager::Run()
{

}
