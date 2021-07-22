#include "DietApp.h"
#include "Util.h"
#include "FoodItem.h"

namespace Diet
{
	void DietApp::SetCalorieMax(float calories)
	{
		CalcMaximums(calories);
	}
	float DietApp::GetCalorieMax()
	{
		return calorieMax;
	}

	void DietApp::ConsumeFood()
	{
		char option = Util::Input("Is this something you have eaten before? (Y/N)");
		if (option == 'Y')
			;
		else
			NewFoodInfo();

		//consumed.push_back(f);
		//total += f.NutInfo();
	}

	void DietApp::NewFoodInfo()
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

		total += ni;
		consumed.emplace_back(name, ni);
	}


	Diet::NutritionInfo DietApp::Total() const
	{
		return total;
	}

	void DietApp::CalcMaximums(float calories)
	{
		calorieMax = calories;
		totFatMax = int(calories / defaultCalories * 75.0f);
		totSatFatMax = int(calories / defaultCalories * 20.0f);
		totCholMax = int(calories / defaultCalories * 300.0f);
		totSodMax = int(calories / defaultCalories * 240.0f);
		totCarbMax = int(calories / defaultCalories * 250.0f);
		totFibreMax = int(calories / defaultCalories * 28.0f);
		totProteinMax = int(calories / defaultCalories * 50.0f);
	}

	std::ostream& operator << (std::ostream& out, const DietApp& rhs)
	{
		//out << rhs.calorieMax << "\n";
		//out << rhs.totFatMax << "\n";
		//out << rhs.totSatFatMax << "\n";
		//out << rhs.totCholMax << "\n";
		//out << rhs.totSodMax << "\n";
		//out << rhs.totCarbMax << "\n";
		//out << rhs.totFibreMax << "\n";
		//out << rhs.totProteinMax << "\n";

		//for (const auto& f : rhs.consumed)
		//	out << f << "\n";

		out << "Total consumed: \n\n";
		if (!rhs.consumed.empty())
			out << rhs.total << "\n";

		return out;
	}

	float DietApp::calorieMax = 0.0f;
	int DietApp::totFatMax = 0;
	int DietApp::totSatFatMax = 0;
	int DietApp::totCholMax = 0;
	int DietApp::totSodMax = 0;
	int DietApp::totCarbMax = 0;
	int DietApp::totFibreMax = 0;
	int DietApp:: totProteinMax = 0;
}
