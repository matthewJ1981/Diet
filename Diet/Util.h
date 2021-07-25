#pragma once
#include <string>
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

	char Input(std::string msg);

	template <typename T>
	T Input(std::string msg, T low, T high, bool convertEmptyInputToLow = true)
	{
		T selection(0);

		do
		{
			selection = InputHelper(msg, selection);
		} while (selection < low || selection > high);

		return selection;
	}

};

