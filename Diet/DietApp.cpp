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
			int selection = Util::Input("Consume food (1)\nAdjust Calorie Goal (2)\nShow history (3)\nOptions (4)\nQuit (5)\n", 1, 5);

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
				Options();
				break;
			case 5:
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
			std::cout << "\n****Writing previous day's total's to a file and resetting what you have consumed.****\n\n";

			while (prevRunDate != currRunDate)
			{
				Write(totalsFile, true);
				total = NutritionInfo();
				prevRunDate = prevRunDate + date_duration(1);
			}
			
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
		bool entering = true;
		do
		{
			std::cout << "Name of Food? ";
			std::getline(std::cin, name);
			ni = NutritionInfo::NewInfo();

			std::cout << "\nYou entered...\n\n" << name << "\n" << ni << "\n";
		}
		while (Util::Input("Is this correct ? ") != 'Y' && Util::Input("Try again?") == 'Y');

		std::cout << "\n";
		float servings = Util::Input("How many servings?: ", 0.0f, 100.0f);

		total += ni * servings;
		consumed.push_back({ {name, ni}, servings });
		favorites.emplace_back(name, ni);
	}

	void DietApp::GetFromFav()
	{
		std::cout << "Select from a list of known foods...\n\n";
		for (uint i = 0; i < favorites.size(); ++i)
			std::cout << favorites[i].Name() << " (" << i << ")\n";

		std::cout << "Go back (" << favorites.size() << ")\n";
		uint selection = Util::Input("Select food item: ", uint(0), favorites.size());

		if (size_t(selection) < favorites.size())
		{
			float servings = Util::Input("How many servings?: ", 0.0f, 100.0f);
			total += favorites[selection].NutInfo() * servings;
			consumed.push_back({ { favorites[selection].Name(), favorites[selection].NutInfo() }, servings });
		}
	}

	void DietApp::Print(std::ostream& out, const NutritionInfo& ni)
	{
		std::cout << "You are aiming at consuming " << calorieMax << " calories per day.\n";

		if (!consumed.empty())
		{
			out << "\n****Total consumed so far today: ****\n\n";
			FormatHelper(out, "Calories:", Percentage(ni.Calories(), calorieMax));
			FormatHelper(out, "Total Fat:", Percentage(ni.Fat().total, totFatMax));
			FormatHelper(out, "  Saturated Fat:",Percentage(ni.Fat().saturated, totSatFatMax));
			FormatHelper(out, "  Trans Fat:", 0);
			FormatHelper(out, "  Polyunsaturated:", 0);
			FormatHelper(out, "  Monounsaturated:", 0);
			FormatHelper(out, "Cholesterol:",Percentage(ni.Cholesterol(), totCholMax));
			FormatHelper(out, "Sodium",Percentage(ni.Sodium(), totSodMax));
			FormatHelper(out, "Total Carbohydrate:", Percentage(ni.Carbohydrates().total, totCarbMax));
			FormatHelper(out, "  Dietary Fibre:", Percentage(ni.Carbohydrates().dietryFiber, totFibreMax));
			FormatHelper(out, "  Total Sugars:", 0);
			FormatHelper(out, "    Added Sugars:", 0);
			if (ni.Carbohydrates().erythitol)
				FormatHelper(out, "    Erythitol:", 0);
			FormatHelper(out, "Protein:", Percentage(ni.Protein(), totProteinMax));
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
			GetOfstream(file);
			inFile.open(file);
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
				outFile << f.first << " " << f.second << "\n";
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
				uint servings = 0;
				inFile >> f >> servings;
				if (inFile.eof())
					break;

				consumed.push_back({ f, servings });
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

	void DietApp::Options()
	{
		std::vector<uint> amts( favorites.size() );
		std::vector<std::vector<uint>> combos;
		Options(total, 0, amts, combos);

		PrintOptions(combos);
	}

	void DietApp::Options(NutritionInfo ni, uint i, std::vector<uint> amts, std::vector<std::vector<uint>>& combos)
	{
		if (i == favorites.size() - 1)
		{
			while (NoOver100(ni + favorites[i].NutInfo()))
			{
				ni += favorites[i].NutInfo();
				++amts[i];
			}

			//combos.push_back(amts);
		}
		else
		{
			while (NoOver100(ni))
			{
				Options(ni, i + 1, amts, combos);
				ni += favorites[i].NutInfo();
				++amts[i];
			}
			combos.push_back(amts);
		}
	}

	void DietApp::PrintOptions(const std::vector<std::vector<uint>>& combos)
	{
		std::ofstream out = GetOfstream("options.txt");
		std::cout << "\n **** Options for the rest of the day **** \n\n";
		for (const auto& amts : combos)
		{
			for (size_t i = 0; i < amts.size(); ++i)
			{
				//std::cout << favorites[i].Name() << ": ";
				//std::cout << amts[i] << "\n";
				out << favorites[i].Name() << ": ";
				out << amts[i] << "\n";
			}
			//std::cout << "\n";
			out << "\n";
		}
	}
	bool DietApp::NoOver100(const NutritionInfo& ni)
	{
		return (Percentage(ni.Calories(), calorieMax) <= 100) &&
			   (Percentage(ni.Fat().total, totFatMax) <= 100) &&
			   (Percentage(ni.Fat().saturated, totSatFatMax) <= 100) &&
			   (Percentage(ni.Cholesterol(), totCholMax) <= 100) &&
			   (Percentage(ni.Sodium(), totSodMax) <= 100) &&
			   (Percentage(ni.Carbohydrates().total, totCarbMax) <= 100) &&
			   (Percentage(ni.Carbohydrates().dietryFiber, totFibreMax) <= 100) &&
			   (Percentage(ni.Protein(), totProteinMax) <= 100);
	}

	//std::vector<std::vector<int>> DietApp::GetCombos()
	//{
	//	std::vector<std::vector<int>> combos;
	//	
	//	for (size_t i = 0; i < favorites.size(); ++i)
	//	{
	//		NutritionInfo temp = total;
	//		std::vector<int> amounts(favorites.size());

	//		for (size_t j = i; j < favorites.size(); ++j)
	//		{
	//			while (NoOver100(temp + favorites[j].NutInfo()))
	//			{
	//				temp += favorites[j].NutInfo();
	//				++amounts[j];
	//			}
	//		}

	//		combos.push_back(amounts);
	//	}

	//	return combos;
	//}

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

	std::vector<std::pair<FoodItem, float>> DietApp::consumed = { };
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
