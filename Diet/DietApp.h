#pragma once
#include <iostream>
#include <vector>
#include "FoodItem.h"

namespace Diet
{
	class DietApp
	{
	public:
		static void SetCalorieMax(float calories);
		static float GetCalorieMax();
		void ConsumeFood();
		
		Diet::NutritionInfo Total() const;

		friend std::ostream& operator << (std::ostream& out, const DietApp& rhs);
	private:
		static void CalcMaximums(float calories);
		void NewFoodInfo();

		std::vector<FoodItem> consumed;
		std::vector<FoodItem> favorites;

		Diet::NutritionInfo total;

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
