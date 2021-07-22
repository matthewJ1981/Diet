#include "Util.h"
#include <iostream>
#include <sstream>

namespace Util
{
	template <typename T>
	T InputHelper(std::string msg, T selection)
	{
		std::cout << msg;
		std::string in = "";
		std::getline(std::cin, in);
		std::stringstream ss(in);
		ss >> selection;

		return selection;
	}

	int Input(std::string msg, Type type)
	{
		if (type == Type::IntegerRange)
		{
			int selection = 0;

			do
			{
				selection = InputHelper(msg, selection);
			} while (selection < 1 || selection > 2);

			return selection;
		}
		else if (type == Type::YesNo)
		{
			char selection = '\0';

			do
			{
				selection = InputHelper(msg, selection);
			} while (::toupper(selection) != 'Y' && ::toupper(selection) != 'N');

			return selection;
		}
		else
			throw std::runtime_error("Unknown input type");
	}
}
