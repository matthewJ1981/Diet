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
		static DietApp d;
		bool running = true;
		while (running)
		{
			d.CheckTime();
			std::cout << d;
			int selection = Util::Input("Consume food (1)\nAdjust Calorie Goal(2)\nQuit(3)\n", 1, 3);

			switch (selection)
			{
			case 1:
				d.ConsumeFood();
				break;
			case 2:
				d.SetCalorieMax(Util::Input("Enter new calorie goal: ", 1, 10000));
				break;
			case 3:
				running = false;
				break;
			default:
				throw std::runtime_error("Invalid input");
			}
		}
	}

	DietApp::DietApp()
	{
		Read(consumedFile);
		Read(favoritesFile);
		Read(configFile);
		
		startHour = CurrentHour();
		currRunDate = CurrentDate();

		if (prevRunDate != currRunDate)
			Reset();
	}

	DietApp::~DietApp()
	{
		Write(consumedFile);
		Write(favoritesFile);
		Write(configFile);
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
	
	void DietApp::CheckTime()
	{
		auto currHour = CurrentHour();
		if (currHour == 0 && startHour != 0)
			Reset();
	}

	void DietApp::ClearConsumedFile()
	{
		auto outFile = GetOfstream(consumedFile);
	}

	void DietApp::SetCalorieMax(int calories)
	{
		calorieMax = calories;
	}

	int DietApp::GetCalorieMax()
	{
		return calorieMax;
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

	Diet::NutritionInfo DietApp::Total()
	{
		return total;
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
			//TODO
			;
		}
		else
			throw std::runtime_error("Invalid filename");

		inFile.close();
	}

	_int64 DietApp::CurrentHour()
	{
		return second_clock::local_time().time_of_day().hours();
	}

	boost::gregorian::date DietApp::CurrentDate()
	{
		return boost::posix_time::second_clock::local_time().date();
	}

	std::ostream& operator << (std::ostream& out, const DietApp& rhs)
	{
		if (!rhs.consumed.empty())
		{
			out << "\nTotal consumed: \n\n";
			DietApp::FormatHelper(out, "Calories:", DietApp::Percentage(int(rhs.total.Calories()), rhs.calorieMax));
			DietApp::FormatHelper(out, "Total Fat:", DietApp::Percentage(rhs.total.Fat().total, rhs.totFatMax));
			DietApp::FormatHelper(out, "  Saturated Fat:", DietApp::Percentage(rhs.total.Fat().saturated, rhs.totSatFatMax));
			DietApp::FormatHelper(out, "  Trans Fat:", 0);
			DietApp::FormatHelper(out, "  Polyunsaturated:", 0);
			DietApp::FormatHelper(out, "  Monounsaturated:", 0);
			DietApp::FormatHelper(out, "Cholesterol:", DietApp::Percentage(rhs.total.Cholesterol(), rhs.totCholMax));
			DietApp::FormatHelper(out, "Sodium", DietApp::Percentage(rhs.total.Sodium(), rhs.totSodMax));
			DietApp::FormatHelper(out, "Total Carbohydrate:", DietApp::Percentage(rhs.total.Carbohydrates().total, rhs.totCarbMax));
			DietApp::FormatHelper(out, "  Dietary Fibre:", DietApp::Percentage(rhs.total.Carbohydrates().dietryFiber, rhs.totFibreMax));
			DietApp::FormatHelper(out, "  Total Sugars:", 0);
			DietApp::FormatHelper(out, "    Added Sugars:", 0);
			if (rhs.total.Carbohydrates().erythitol)
				DietApp::FormatHelper(out, "    Erythitol:", 0);
			DietApp::FormatHelper(out, "Protein:", DietApp::Percentage(rhs.total.Protein(), rhs.totProteinMax));
			out << "\n";
		}

		return out;
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

}
