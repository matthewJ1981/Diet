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
		static void setCalorieMax(float calories);
		static float getCalorieMax();
		
		friend std::ostream& operator << (std::ostream& out, const DietApp& rhs);
	private:
		static void calcMaximums(float calories);

		std::vector<Consumed> consumed;
		std::vector<FoodItem> favorites;

		static constexpr float defaultCalories = 2000.0f;
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
