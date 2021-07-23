#include "DietApp.h"
#include "Util.h"
#include "FoodItem.h"
#include <iomanip>

namespace Diet
{
	void DietApp::SetCalorieMax(int calories)
	{
		CalcMaximums(calories);
	}
	int DietApp::GetCalorieMax()
	{
		return calorieMax;
	}

	void DietApp::CalcMaximums(int calories)
	{
		calorieMax = calories;
		totFatMax = int(float(calories) / defaultCalories * defFat);
		totSatFatMax = int(float(calories) / defaultCalories * defSatFat);
		totCholMax = int(float(calories) / defaultCalories * defChol);
		totSodMax = int(float(calories) / defaultCalories * defSod);
		totCarbMax = int(float(calories) / defaultCalories * defCarb);
		totFibreMax = int(float(calories) / defaultCalories * defFibre);
		totProteinMax = int(float(calories) / defaultCalories * defProtein);
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


	Diet::NutritionInfo DietApp::Total() const
	{
		return total;
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

	int DietApp::calorieMax = 0;
	int DietApp::totFatMax = 0;
	int DietApp::totSatFatMax = 0;
	int DietApp::totCholMax = 0;
	int DietApp::totSodMax = 0;
	int DietApp::totCarbMax = 0;
	int DietApp::totFibreMax = 0;
	int DietApp:: totProteinMax = 0;
}
