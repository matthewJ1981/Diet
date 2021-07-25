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
		DietApp();
		~DietApp();
		static void SetCalorieMax(int calories);
		static int GetCalorieMax();
		void ConsumeFood();
		void CheckTime();

		Diet::NutritionInfo Total() const;
		friend std::ostream& operator << (std::ostream& out, const DietApp& rhs);
		void Write(std::string);
		void Read(std::string);

	private:
		void GetNewFood();
		void GetFromFav();
		static void FormatHelper(std::ostream& out, std::string col1, int col2);
		static int Percentage(int amount, int max);
		std::ofstream GetOfstream(std::string file);
		std::ifstream GetIfstream(std::string file);
		static _int64 CurrentHour();
		static boost::gregorian::date CurrentDate();
		void Reset();
		void ClearConsumedFile();
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

		static const std::string consumedFile;
		static const std::string favoritesFile;
		static const std::string configFile;
		static const std::string totalsFile;

		static boost::gregorian::date prevRunDate;
		//static std::string currRunDate;
		static boost::gregorian::date currRunDate;
		static _int64 startHour;
		//_int64 currHour;

	};
}
