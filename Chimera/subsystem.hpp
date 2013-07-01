#pragma once

namespace chimera
{
	namespace base
	{
		class Subsystem
		{
		public:
			virtual ~Subsystem() {};

			virtual bool Initialize() = 0;
			virtual void Shutdown() = 0;
			virtual void Frame(double deltaT) = 0;
		};
	}
}