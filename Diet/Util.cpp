#include "Util.h"

namespace Util
{
	char Input(std::string msg)
	{
		char selection = '\0';

		do
		{
			selection = InputHelper(msg, selection);
		} while (::toupper(selection) != 'Y' && ::toupper(selection) != 'N');

		return selection;
	}
}
