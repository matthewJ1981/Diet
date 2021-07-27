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
		static void Init();
		static void Reset();

		static void ConsumeFood();
		static void GetNewFood();
		static void GetFromFav();

		static void Print(std::ostream& out, const NutritionInfo& ni);
		static void FormatHelper(std::ostream& out, std::string col1, int col2);
		static int Percentage(int amount, int max);
	
		static std::ofstream GetOfstream(std::string file, bool append = false);
		static std::ifstream GetIfstream(std::string file);
		static void Write();
		static void Read();
		static void Write(std::string, bool append = false);
		static void Read(std::string);
		static void ClearConsumedFile();

		static void History();

		static void SetCalorieMax(int calories);
		static void CheckTime();
		static _int64 CurrentHour();
		static boost::gregorian::date CurrentDate();

		static std::vector<FoodItem> consumed;
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
