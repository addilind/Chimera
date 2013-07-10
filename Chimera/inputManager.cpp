#include "inputManager.hpp"

using chimera::ui::InputManager;
void InputManager::Initialize()
{
	for(int i = 0; i < 256; i++)
	{
		_keyStates[i] = false;
	}
}

void InputManager::KeyDown(unsigned int vkcode)
{
	assert(vkcode < 256);
	_keyStates[vkcode] = true;
}

void InputManager::KeyUp(unsigned int vkcode)
{
	assert(vkcode < 256);
	_keyStates[vkcode] = false;
}

bool InputManager::IsDown(unsigned int vkcode)
{
	assert(vkcode < 256);
	return _keyStates[vkcode];
}