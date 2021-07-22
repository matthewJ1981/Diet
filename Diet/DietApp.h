#pragma once
#include <iostream>
#include <vector>
#include "FoodItem.h"
#include "Consumed.h"

namespace Diet
{
	class DietApp
	{
	public:
		static void calcMaximums(float calories);
		friend std::ostream& operator << (std::ostream& out, const DietApp& rhs);
	private:

		std::vector<Consumed> consumed;
		std::vector<FoodItem> favorites;

		static float calorieMax;
		static int totFatMax;
		static int totSatFatMax;
		static int totCholMax;
		static int totSodMax;
		static int totCarbMax;
		static int totFibreMax;
		static int totProteinMax;
	};
}
