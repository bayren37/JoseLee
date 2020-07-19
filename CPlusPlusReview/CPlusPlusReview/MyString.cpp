#include "MyString.h"
#include <limits>
#include <cassert>

namespace MyString {

	string::string(char character, const unsigned int duplicateCount)
	{
		unsigned int memSize = duplicateCount + 1;
		if (duplicateCount < UINT_MAX - 1)
			string_ = new char[memSize];
		else
			_ASSERT(false);
		
		for (size_t i = 0; i < duplicateCount; ++i)
		{
			string_[i] = character;
		}

		length_ = duplicateCount;
	}

	string::string(const char* string)
	{
	}

	string::string(const string& other)
	{
	}

	string::~string()
	{
	}

	void string::append(const string& s)
	{
	}

	void string::copy(const string& src)
	{
	}

	unsigned int string::strlen()
	{
		return 0;
	}

}
