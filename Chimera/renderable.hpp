#pragma once

#include "entity.hpp"
#include <d3d11_1.h>

namespace chimera
{
	namespace content
	{
		class Renderable : public Entity
		{
		public:
			virtual void Render(ID3D11DeviceContext1 renderContext) = 0;
		};
	}
}