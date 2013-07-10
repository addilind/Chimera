#pragma once

#include <assert.h>

namespace chimera
{
	namespace ui
	{
		class InputManager
		{
		public:
			void Initialize();
			void KeyDown(unsigned int vkcode);
			void KeyUp(unsigned int vkcode);
			bool IsDown(unsigned int vkcode);
		private:
			bool _keyStates[256];
		};
	}
}