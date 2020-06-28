#include "reference.h"

namespace review
{
	int& Reference::makeItFive(int& var)
	{
		var = 5;
		return var;
	}

	int Reference::returnValue()
	{
		return 5;
	}

	int& Reference::returnLocalVar()
	{
		int var = 5;
		return var;
	}
	
	const int& Reference::returnLocalRefferenceVar()
	{
		const int& var = 5;
		return var;
	}
}
