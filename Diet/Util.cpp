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
}
