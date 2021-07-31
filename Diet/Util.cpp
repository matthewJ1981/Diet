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
		return abs(lhs - rhs) <= 0.000001f;
	}
	std::ofstream Util::GetOfstream(std::string file, bool append)
	{
		std::ofstream outFile;
		try
		{
			append == true ? outFile.open(file, std::ios_base::app) : outFile.open(file);
		}
		catch (std::exception e)
		{
			std::cerr << e.what();
			abort();
		}

		if (!outFile)
		{
			std::cerr << "Cannot open " + file + "\n";
			abort();
		}

		return outFile;
	}

	std::ifstream Util::GetIfstream(std::string file)
	{
		std::ifstream inFile;
		try
		{
			inFile.open(file);
		}
		catch (std::exception e)
		{
			std::cerr << e.what();
			abort();
		}

		if (!inFile)
		{
			GetOfstream(file);
			inFile.open(file);
		}

		return inFile;
	}
}
