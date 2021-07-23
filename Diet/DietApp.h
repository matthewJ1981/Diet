#pragma once
#include <iostream>
#include <vector>
#include "FoodItem.h"
#include <fstream>

namespace Diet
{
	class DietApp
	{
	public:
		~DietApp();
		static void SetCalorieMax(int calories);
		static int GetCalorieMax();
		void ConsumeFood();

		Diet::NutritionInfo Total() const;
		friend std::ostream& operator << (std::ostream& out, const DietApp& rhs);
		void WriteToFile();

	private:
		static void CalcMaximums(int calories);
		void GetNewFood();
		void GetFromFav();
		static void FormatHelper(std::ostream& out, std::string col1, int col2);
		static int Percentage(int amount, int max);

		std::vector<FoodItem> consumed;
		std::vector<FoodItem> favorites;

		Diet::NutritionInfo total;

		static int calorieMax;
		static int totFatMax;
		static int totSatFatMax;
		static int totCholMax;
		static int totSodMax;
		static int totCarbMax;
		static int totFibreMax;
		static int totProteinMax;

		static constexpr int defaultCalories = 2000;
		static constexpr int defFat = 75;
		static constexpr int defSatFat = 20;
		static constexpr int defChol = 30;
		static constexpr int defSod = 240;
		static constexpr int defCarb = 250;
		static constexpr int defFibre = 28;
		static constexpr int defProtein = 50;
	};
}
