#pragma once


namespace chimera
{
	namespace helper
	{
		struct ComDeleter
		{
			template<class T> void operator()(T* p) const
			{
				p->Release();
			}
		};
	}
}