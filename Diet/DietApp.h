#pragma once
#include <iostream>
#include <vector>
#include "FoodItem.h"
#include <fstream>
#include <chrono>
#include <string>
#include <boost/date_time/posix_time/posix_time.hpp>

typedef unsigned int uint;

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
		static void Print(std::ostream& out, const FoodItem& ni);
		static void FormatHelper(std::ostream& out, std::string col1, float col2);
	
		/**
		 *	File IO
		 */

		static void Serialize();
		static void Deserialize();
		static void WriteTotal();
		static void ReadTotal();
		static void ClearConsumedFile();

		/**
		  *	Read and display previous days totals
		 */
		static void History();
		/**
		* Calculate and display all food options for the rest of the day that don't take any daily value over 100%
        */
		//static void Options();
		//static void Options(NutritionInfo ni, uint i, std::vector<uint> amts, std::vector<std::vector<uint>>& combos);
		//static void PrintOptions(const std::vector<std::vector<uint>>& combos);
		//static bool NoOver100(const NutritionInfo& ni);

		static void SetCalorieMax(float calories);

		static std::vector<std::pair<FoodItem, float>> consumed;
		static std::vector<FoodItem> favorites;
		static FoodItem total;

		static float calorieMax;
		static constexpr float totFatMax = 75.0f;
		static constexpr float totSatFatMax = 20.0f;
		static constexpr float totCholMax = 300.0f;
		static constexpr float totSodMax = 2400.0f;
		static constexpr float totCarbMax = 250.0f;
		static constexpr float totFibreMax = 28.0f;
		static constexpr float totProteinMax = 50.0f;

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
