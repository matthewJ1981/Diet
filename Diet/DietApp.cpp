#include "DietApp.h"
#include "Util.h"
#include "FoodItem.h"
#include <iomanip>
#include <cstdio>
#include <boost\date_time/posix_time/posix_time.hpp>

using namespace boost::posix_time;
using namespace boost::gregorian;

namespace Diet
{
	void DietApp::Go()
	{
		if (started)
			return;

		started = true;

		Init();
		bool running = true;
		while (running)
		{
			CheckTime();
			Print(std::cout, total);
			int selection = Util::Input("Consume food (1)\nAdjust Calorie Goal (2)\nShow history (3)\nQuit (4)\n", 1, 4);

			switch (selection)
			{
			case 1:
				ConsumeFood();
				break;
			case 2:
				SetCalorieMax(Util::Input("Enter new calorie goal: ", 1, 10000));
				break;	
			case 3:
				History();
				break;
			case 4:
				running = false;
				break;
			default:
				throw std::runtime_error("Invalid input");
			}
		}
		Write();
	}

	void DietApp::Init()
	{
		Read();
		
		startHour = CurrentHour();
		currRunDate = CurrentDate();

		if (prevRunDate != currRunDate)
			Reset();
	}

	void DietApp::Reset()
	{
		if (!prevRunDate.is_not_a_date())
		{
			std::cout << "\n****Writing yesterday's total to a file and resetting what you have consumed.****\n\n";
			Write(totalsFile, true);
			total = NutritionInfo();
			consumed.clear();
			ClearConsumedFile();
		}
		prevRunDate = currRunDate;
		startHour = 0;
	}
	
	void DietApp::ConsumeFood()
	{
		char option = '\0';
		if (favorites.size() == 0)
			option = 'N';
		else
			option = Util::Input("Is this something you have eaten before? (Y/N)");

		if (option == 'Y')
			GetFromFav();
		else
			GetNewFood();
	}

	void DietApp::GetNewFood()
	{
		std::string name;
		NutritionInfo ni;
		do
		{
			std::cout << "Name of Food? ";
			std::getline(std::cin, name);
			ni = NutritionInfo::NewInfo();

			std::cout << "\nYou entered...\n\n" << name << "\n" << ni << "\n";
		}
		while (Util::Input("Is this correct ? ") != 'Y');
		std::cout << "\n";

		total += ni;
		consumed.emplace_back(name, ni);
		favorites.emplace_back(name, ni);
	}

	void DietApp::GetFromFav()
	{
		std::cout << "Select from a list of known foods...\n\n";
		for (uint i = 0; i < favorites.size(); ++i)
			std::cout << favorites[i].Name() << " (" << i << ")\n";

		int selection = Util::Input("Select food item: ", 0, int(favorites.size() - 1));
		total += favorites[selection].NutInfo();
		consumed.emplace_back(favorites[selection].Name(), favorites[selection].NutInfo());
	}

	void DietApp::Print(std::ostream& out, const NutritionInfo& ni)
	{
		if (!consumed.empty())
		{
			out << "Total consumed: \n\n";
			DietApp::FormatHelper(out, "Calories:", DietApp::Percentage(int(ni.Calories()), calorieMax));
			DietApp::FormatHelper(out, "Total Fat:", DietApp::Percentage(ni.Fat().total, totFatMax));
			DietApp::FormatHelper(out, "  Saturated Fat:", DietApp::Percentage(ni.Fat().saturated, totSatFatMax));
			DietApp::FormatHelper(out, "  Trans Fat:", 0);
			DietApp::FormatHelper(out, "  Polyunsaturated:", 0);
			DietApp::FormatHelper(out, "  Monounsaturated:", 0);
			DietApp::FormatHelper(out, "Cholesterol:", DietApp::Percentage(ni.Cholesterol(), totCholMax));
			DietApp::FormatHelper(out, "Sodium", DietApp::Percentage(ni.Sodium(), totSodMax));
			DietApp::FormatHelper(out, "Total Carbohydrate:", DietApp::Percentage(ni.Carbohydrates().total, totCarbMax));
			DietApp::FormatHelper(out, "  Dietary Fibre:", DietApp::Percentage(ni.Carbohydrates().dietryFiber, totFibreMax));
			DietApp::FormatHelper(out, "  Total Sugars:", 0);
			DietApp::FormatHelper(out, "    Added Sugars:", 0);
			if (ni.Carbohydrates().erythitol)
				DietApp::FormatHelper(out, "    Erythitol:", 0);
			DietApp::FormatHelper(out, "Protein:", DietApp::Percentage(ni.Protein(), totProteinMax));
			out << "\n";
		}
	}

	void DietApp::FormatHelper(std::ostream& out, std::string col1, int col2)
	{
		out << std::setw(25) << std::left << col1
			<< std::setw(10) << std::right << col2 << "%\n";

	}

	int DietApp::Percentage(int amount, int max)
	{
		return int(float(amount) / max * 100);
	}

	std::ofstream DietApp::GetOfstream(std::string file, bool append)
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

	std::ifstream DietApp::GetIfstream(std::string file)
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
			std::cerr << "Cannot open " + file + "\n";
			abort();
		}

		return inFile;
	}

	void DietApp::Write()
	{
		Write(consumedFile);
		Write(favoritesFile);
		Write(configFile);
	}

	void DietApp::Read()
	{
		Read(consumedFile);
		Read(favoritesFile);
		Read(configFile);
	}

	void DietApp::Write(std::string file, bool append)
	{
		auto outFile = GetOfstream(file, append);

		if (file == consumedFile)
		{
			for (const auto& f : consumed)
				outFile << f << "\n";
		}
		else if (file == favoritesFile)
		{
			for (const auto& f : favorites)
				outFile << f << "\n";
		}
		else if (file == configFile)
		{
			outFile << calorieMax << "\n";
			outFile << prevRunDate << "\n";
		}
		else if (file == totalsFile)
		{
			outFile << prevRunDate << " ";
			outFile << total << "\n";
		}
		else
			throw std::runtime_error("Invalid filename");

		outFile.close();
	}

	void DietApp::Read(std::string file)
	{
		auto inFile = GetIfstream(file);

		if (file == consumedFile)
		{
			while (true)
			{
				FoodItem f;
				inFile >> f;
				if (inFile.eof())
					break;

				consumed.push_back(f);
				total += f.NutInfo();
			}
		}
		else if (file == favoritesFile)
		{
			while (true)
			{
				FoodItem f;
				inFile >> f;
				if (inFile.eof())
					break;
				favorites.push_back(f);
			}
		}
		else if (file == configFile)
		{
			inFile >> DietApp::calorieMax;
			inFile >> DietApp::prevRunDate;
		}
		else if (file == totalsFile)
		{
			while (true)
			{
				boost::gregorian::date d;
				NutritionInfo ni;
				inFile >> d >> ni;
				if (inFile.eof())
					break;

				std::cout << d << "\n";
				Print(std::cout, ni);
			}
		}
		else
			throw std::runtime_error("Invalid filename");

		inFile.close();
	}

	void DietApp::ClearConsumedFile()
	{
		auto outFile = GetOfstream(consumedFile);
	}

	void DietApp::History()
	{
		Read(totalsFile);
	}

	void DietApp::SetCalorieMax(int calories)
	{
		calorieMax = calories;
	}

	void DietApp::CheckTime()
	{
		auto currHour = CurrentHour();
		if (currHour == 0 && startHour != 0)
			Reset();
	}

	_int64 DietApp::CurrentHour()
	{
		return second_clock::local_time().time_of_day().hours();
	}

	boost::gregorian::date DietApp::CurrentDate()
	{
		return boost::posix_time::second_clock::local_time().date();
	}

	std::vector<FoodItem> DietApp::consumed = {};
	std::vector<FoodItem> DietApp::favorites = {};
	Diet::NutritionInfo DietApp::total = {};

	int DietApp::calorieMax = 2000;
	const std::string DietApp::consumedFile = "consumed.txt";
	const std::string DietApp::favoritesFile = "favorites.txt";
	const std::string DietApp::configFile = "config.txt";
	const std::string DietApp::totalsFile = "totals.txt";
	boost::gregorian::date DietApp::prevRunDate(not_a_date_time);
	boost::gregorian::date DietApp::currRunDate(not_a_date_time);
	_int64 DietApp::startHour = 0;

	bool DietApp::started = false;
}
