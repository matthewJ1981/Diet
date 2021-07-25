#pragma once
#include <iostream>
#include <vector>
#include "FoodItem.h"
#include <fstream>
#include <chrono>

namespace Diet
{
	class DietApp
	{
	public:
		DietApp();
		~DietApp();
		static void SetCalorieMax(int calories);
		static int GetCalorieMax();
		void ConsumeFood();

		Diet::NutritionInfo Total() const;
		friend std::ostream& operator << (std::ostream& out, const DietApp& rhs);
		void WriteConsumed();
		void WriteFavorites();
		void WriteTotal();
		void WriteConfig();
		void ReadConsumed();
		void ReadFavorites();
		void ReadConfig();
		void ReadTotal();

	private:
		void GetNewFood();
		void GetFromFav();
		static void FormatHelper(std::ostream& out, std::string col1, int col2);
		static int Percentage(int amount, int max);
		std::ofstream OpenWrite(std::string file);
		std::ifstream OpenRead(std::string file);

		std::vector<FoodItem> consumed;
		std::vector<FoodItem> favorites;

		Diet::NutritionInfo total;

		static int calorieMax;
		static constexpr int totFatMax = 75;
		static constexpr int totSatFatMax = 20;
		static constexpr int totCholMax = 300;
		static constexpr int totSodMax = 2400;
		static constexpr int totCarbMax = 250;
		static constexpr int totFibreMax = 28;
		static constexpr int totProteinMax = 50;

		//std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
	};
}
