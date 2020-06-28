#pragma once

namespace review {

	class Reference
	{
	public:
		static int& makeItFive(int& var);
		static int returnValue();
		static int& returnLocalVar();
		static const int& returnLocalRefferenceVar();
		
	};
}