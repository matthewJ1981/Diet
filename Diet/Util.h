#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <boost/date_time/posix_time/posix_time.hpp>

namespace Util
{
	/**
	* Common functionality of Input functions
	 */
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

	/**
	 *	Perform some input validation for yes/no input
	 */
	char Input(std::string msg);

	/**
	 *	Perform some input validation for integer selections
	 */
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

	bool Eq(const float lhs, const float rhs);
	std::ofstream GetOfstream(std::string file, bool append = false);
	std::ifstream GetIfstream(std::string file);
	float Percentage(float amount, float max);
	bool CheckTime(_int64 startHour);
	_int64 CurrentHour();
	boost::gregorian::date CurrentDate();
};

