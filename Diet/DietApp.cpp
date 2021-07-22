#include "DietApp.h"
#include "Util.h"

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
		char option = Util::Input("Is this something you have eaten before? (Y/N)", Util::Type::YesNo);
		std::cout << option << "\n";
		//consumed.push_back(f);
		//total += f.NutInfo();
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
		out << rhs.calorieMax << "\n";
		out << rhs.totFatMax << "\n";
		out << rhs.totSatFatMax << "\n";
		out << rhs.totCholMax << "\n";
		out << rhs.totSodMax << "\n";
		out << rhs.totCarbMax << "\n";
		out << rhs.totFibreMax << "\n";
		out << rhs.totProteinMax << "\n";

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
