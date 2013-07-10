#pragma once

#include <string>

namespace chimera
{
	namespace helper
	{
		class Exception
		{
			
        private:
                std::wstring _issue;

        public:
                Exception( const std::wstring& issue ) throw ( );

                Exception( ) throw ( );

                virtual ~Exception( void ) throw ( );

                const std::wstring what( void ) throw ( );
		};
	}
}