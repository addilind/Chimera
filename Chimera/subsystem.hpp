#pragma once

#include <memory>

namespace chimera
{
	namespace base
	{
		class RunManager;
		class Subsystem
		{
		protected:
			std::shared_ptr<RunManager> _manager;
		public:
			Subsystem(std::shared_ptr<RunManager> manager) { _manager = manager; }
			virtual ~Subsystem() {};

			virtual void Initialize() = 0;
			virtual void Shutdown() = 0;
			virtual void Frame(double deltaT) = 0;
		};
	}
}