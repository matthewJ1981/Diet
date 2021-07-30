#include "Util.h"

namespace Util
{

	char Input(std::string msg)
	{
		char selection = '\0';

		do
		{
			selection = ::toupper(InputHelper(msg, selection));
		} while (selection != 'Y' && selection != 'N');

		return selection;
	}

	bool Eq(const float lhs, const float rhs)
	{
		std::cerr << lhs - rhs << ": " << relative_difference(lhs, rhs) << "\n";
		return abs(lhs - rhs) <= relative_difference(lhs, rhs);
	}
}
