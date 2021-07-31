#include "DietApp.h"
#include "Util.h"
#include <iomanip>
#include <cstdio>

using namespace boost::posix_time;
using namespace boost::gregorian;

namespace Diet
{
	void DietApp::Go()
	{
		using Util::CheckTime;
		if (started)
			return;

		started = true;

		Init();
		bool running = true;
		while (running)
		{
			if (CheckTime(startHour))
				Reset();

			Print(std::cout, total);
			int selection = Util::Input("Consume food (1)\nAdjust Calorie Goal (2)\nShow history (3)\nOptions (4)\nQuit (5)\n", 1, 5);

			switch (selection)
			{
			case 1:
				ConsumeFood();
				break;
			case 2:
				SetCalorieMax(Util::Input("Enter new calorie goal: ", 1.0f, 10000.0f));
				break;	
			case 3:
				History();
				break;
			case 4:
				//Options();
				break;
			case 5:
				running = false;
				break;
			default:
				throw std::runtime_error("Invalid input");
			}
		}
		Serialize();
	}

	void DietApp::Init()
	{
		Deserialize();
		
		startHour = Util::CurrentHour();
		currRunDate = Util::CurrentDate();

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
				WriteTotal();
				total.Clear();
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
		FoodItem f;
		float servings = 0.0f;
		bool entering = true;
		do
		{
			f.New(std::cout, std::cin);
			servings = Util::Input("How many servings?: ", 0.0f, 100.0f);

			std::cout << "\nYou entered...\n\n" << f << "\nServings: " << servings << "\n";

		}
		while (Util::Input("Is this correct ? ") != 'Y' && Util::Input("Try again?") == 'Y');

		std::cout << "\n";
		
		total += f;
		consumed.push_back({f, servings });
		favorites.push_back(f);
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
			total += favorites[selection] * servings;
			consumed.push_back({ favorites[selection] , servings });
		}
	}

	void DietApp::Print(std::ostream& out, const FoodItem& fi)
	{
		using Util::Percentage;
		std::cout << "You are aiming at consuming " << calorieMax << " calories per day.\n";

		if (!consumed.empty())
		{
			out << "\n****Total consumed so far today: ****\n\n";
			FormatHelper(out, "Calories:", Percentage(fi.Calories(), calorieMax));
			FormatHelper(out, "Total Fat:", Percentage(fi.TotalFat(), totFatMax));
			FormatHelper(out, "  Saturated Fat:",Percentage(fi.SaturatedFat(), totSatFatMax));
			FormatHelper(out, "  Trans Fat:", 0);
			FormatHelper(out, "  Polyunsaturated:", 0);
			FormatHelper(out, "  Monounsaturated:", 0);
			FormatHelper(out, "Cholesterol:",Percentage(fi.Cholesterol(), totCholMax));
			FormatHelper(out, "Sodium",Percentage(fi.Sodium(), totSodMax));
			FormatHelper(out, "Total Carbohydrate:", Percentage(fi.TotalCarbohydrates(), totCarbMax));
			FormatHelper(out, "  Dietary Fibre:", Percentage(fi.DietryFiber(), totFibreMax));
			FormatHelper(out, "  Total Sugars:", 0);
			FormatHelper(out, "    Added Sugars:", 0);
			if (fi.Erythritol())
				FormatHelper(out, "    Erythitol:", 0);
			FormatHelper(out, "Protein:", Percentage(fi.Protein(), totProteinMax));
			out << "\n";
		}
	}

	void DietApp::FormatHelper(std::ostream& out, std::string col1, float col2)
	{
		out << std::setprecision(1) << std::fixed;
		out << std::setw(25) << std::left << col1
			<< std::setw(10) << std::right << col2 << "%\n";
	}

	void DietApp::Serialize()
	{
		{
			auto outFile = Util::GetOfstream(consumedFile);
			for (const auto& f : consumed)
			{
				f.first.Serialize(outFile);
				outFile << " " << f.second << "\n";
			}
		}
		{
			auto outFile = Util::GetOfstream(favoritesFile);
			for (const auto& f : favorites)
			{
				f.Serialize(outFile);
				outFile << "\n";

			}
		}
		{
			auto outFile = Util::GetOfstream(configFile);
			outFile << calorieMax << "\n";
			outFile << prevRunDate << "\n";
		}
	}

	void DietApp::Deserialize()
	{
		{
			auto inFile = Util::GetIfstream(consumedFile);
			while (true)
			{
				FoodItem f;
				float servings = 0;
				f.Deserialize(inFile);
				inFile >> servings;
				if (inFile.eof())
					break;

				consumed.push_back({ f, servings });
				total += f * servings;
			}
		}
		{
			auto inFile = Util::GetIfstream(favoritesFile);
			while (true)
			{
				FoodItem f;
				f.Deserialize(inFile);
				if (inFile.eof())
					break;
				favorites.push_back(f);
			}
		}
		{
			auto inFile = Util::GetIfstream(configFile);
			inFile >> DietApp::calorieMax;
			inFile >> DietApp::prevRunDate;
		}
	}

	void DietApp::WriteTotal()
	{
		auto outFile = Util::GetOfstream(totalsFile, true);
		outFile << prevRunDate << " ";
		total.Serialize(outFile);
		outFile << "\n";
	}

	void DietApp::ReadTotal()
	{
		auto inFile = Util::GetIfstream(totalsFile);
		while (true)
		{
			boost::gregorian::date d;
			FoodItem f;
			inFile >> d;
			f.Deserialize(inFile);
			if (inFile.eof())
				break;

			std::cout << d << "\n";
			std::cout << f << "\n";
		}
	}

	void DietApp::ClearConsumedFile()
	{
		auto outFile = Util::GetOfstream(consumedFile);
	}

	void DietApp::History()
	{
		ReadTotal();
	}

	//void DietApp::Options()
	//{
	//	std::vector<uint> amts( favorites.size() );
	//	std::vector<std::vector<uint>> combos;
	//	Options(total, 0, amts, combos);

	//	PrintOptions(combos);
	//}

	//void DietApp::Options(NutritionInfo ni, uint i, std::vector<uint> amts, std::vector<std::vector<uint>>& combos)
	//{
	//	if (i == favorites.size() - 1)
	//	{
	//		while (NoOver100(ni + favorites[i].NutInfo()))
	//		{
	//			ni += favorites[i].NutInfo();
	//			++amts[i];
	//		}

	//		//combos.push_back(amts);
	//	}
	//	else
	//	{
	//		while (NoOver100(ni))
	//		{
	//			Options(ni, i + 1, amts, combos);
	//			ni += favorites[i].NutInfo();
	//			++amts[i];
	//		}
	//		combos.push_back(amts);
	//	}
	//}

	//void DietApp::PrintOptions(const std::vector<std::vector<uint>>& combos)
	//{
	//	std::ofstream out = GetOfstream("options.txt");
	//	std::cout << "\n **** Options for the rest of the day **** \n\n";
	//	for (const auto& amts : combos)
	//	{
	//		for (size_t i = 0; i < amts.size(); ++i)
	//		{
	//			//std::cout << favorites[i].Name() << ": ";
	//			//std::cout << amts[i] << "\n";
	//			out << favorites[i].Name() << ": ";
	//			out << amts[i] << "\n";
	//		}
	//		//std::cout << "\n";
	//		out << "\n";
	//	}
	//}
	//bool DietApp::NoOver100(const NutritionInfo& ni)
	//{
	//	return (Percentage(ni.Calories(), calorieMax) <= 100.0f) &&
	//		   (Percentage(ni.Fat().total, totFatMax) <= 100.0f) &&
	//		   (Percentage(ni.Fat().saturated, totSatFatMax) <= 100.0f) &&
	//		   (Percentage(ni.Cholesterol(), totCholMax) <= 100.0f) &&
	//		   (Percentage(ni.Sodium(), totSodMax) <= 100.0f) &&
	//		   (Percentage(ni.Carbohydrates().total, totCarbMax) <= 100.0f) &&
	//		   (Percentage(ni.Carbohydrates().dietryFiber, totFibreMax) <= 100.0f) &&
	//		   (Percentage(ni.Protein(), totProteinMax) <= 100.0f);
	//}

	void DietApp::SetCalorieMax(float calories)
	{
		calorieMax = calories;
	}

	std::vector<std::pair<FoodItem, float>> DietApp::consumed = { };
	std::vector<FoodItem> DietApp::favorites = {};
	FoodItem DietApp::total = {"Total"};

	float DietApp::calorieMax = 2000.0f;
	const std::string DietApp::consumedFile = "Data/consumed.txt";
	const std::string DietApp::favoritesFile = "Data/favorites.txt";
	const std::string DietApp::configFile = "Data/config.txt";
	const std::string DietApp::totalsFile = "Data/totals.txt";
	boost::gregorian::date DietApp::prevRunDate(not_a_date_time);
	boost::gregorian::date DietApp::currRunDate(not_a_date_time);
	_int64 DietApp::startHour = 0;

	bool DietApp::started = false;
}
