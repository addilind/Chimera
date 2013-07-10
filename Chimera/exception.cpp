#include "exception.hpp"

using chimera::helper::Exception;

Exception::Exception() : _issue(L"")
{
}

Exception::Exception( const std::wstring& issue )
{
	_issue = issue;
}

Exception::~Exception()
{

}

const std::wstring Exception::what()
{
	return _issue;
}