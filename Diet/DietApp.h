#pragma once
#include <iostream>
#include <vector>
#include "FoodItem.h"
#include <fstream>
#include <chrono>
#include <string>
#include <boost/date_time/posix_time/posix_time.hpp>


namespace Diet
{
	class DietApp
	{
	public:
		static void Go();
	private:
		DietApp() {}
		DietApp(const DietApp&) = delete;
		DietApp& operator = (const DietApp&) = delete;

		/**
		 *	Read data from files and perform daily reset if necessary
		 */
		static void Init();
		/**
		 *	Write the dauly total to a file and reset consumed data
		 */
		static void Reset();

		/**
		 *	Simple driver to consume food
		 */
		static void ConsumeFood();
		/**
		 *	Enter new food information
		 */
		static void GetNewFood();
		/**
		 *	Get food that was been eaten previously
		 */
		static void GetFromFav();

		/**
		 *	Output current calorie goal and total consumed for the day as a percentage of daily value
		 */
		static void Print(std::ostream& out, const NutritionInfo& ni);
		static void FormatHelper(std::ostream& out, std::string col1, int col2);
		static int Percentage(int amount, int max);
	
		/**
		 *	File IO
		 */
		static std::ofstream GetOfstream(std::string file, bool append = false);
		static std::ifstream GetIfstream(std::string file);
		static void Write();
		static void Read();
		static void Write(std::string, bool append = false);
		static void Read(std::string);
		static void ClearConsumedFile();

		/**
		  *	Read and display previous days totals
		 */
		static void History();
		/**
		* Calculate and display all food options for the rest of the day that don't take any daily value over 100%
        */
		static void Options();
		static void Options(NutritionInfo ni, uint i, std::vector<uint> amts, std::vector<std::vector<uint>>& combos);
		static void PrintOptions(const std::vector<std::vector<uint>>& combos);
		static bool NoOver100(const NutritionInfo& ni);
		static std::vector<std::vector<int>> GetCombos();

		static void SetCalorieMax(int calories);
		static void CheckTime();
		static _int64 CurrentHour();
		static boost::gregorian::date CurrentDate();

		static std::vector<std::pair<FoodItem, uint>> consumed;
		static std::vector<FoodItem> favorites;
		static Diet::NutritionInfo total;

		static int calorieMax;
		static constexpr int totFatMax = 75;
		static constexpr int totSatFatMax = 20;
		static constexpr int totCholMax = 300;
		static constexpr int totSodMax = 2400;
		static constexpr int totCarbMax = 250;
		static constexpr int totFibreMax = 28;
		static constexpr int totProteinMax = 50;

		static const std::string consumedFile;
		static const std::string favoritesFile;
		static const std::string configFile;
		static const std::string totalsFile;

		static boost::gregorian::date prevRunDate;
		static boost::gregorian::date currRunDate;
		static _int64 startHour;

		static bool started;
	};
}
