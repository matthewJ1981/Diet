#pragma once
#include <gtest/gtest.h>
#include "..\DietApp.h"
#include <boost/date_time/posix_time/posix_time.hpp>
#include "..\DietAppImplementation.h"
#include <fstream>
#include <iostream>

using namespace boost::gregorian;
using namespace boost::posix_time;
using namespace Diet::Internal;

class DietAppTest : public ::testing::Test
{
protected:
	void SetUp() override
	{
		DietAppImplementation::consumed = consumedDef;
		DietAppImplementation::favorites = favoritesDef;
		DietAppImplementation::total = totalDef;

		DietAppImplementation::calorieMax = calorieMaxDef;
		DietAppImplementation::prevRunDate = prevRunDateDef;
		DietAppImplementation::currRunDate = currRunDateDef;
		DietAppImplementation::startHour = startHourDef;;
	}

	void TearDown() override
	{
		;
	}

	static const std::vector<std::pair<Diet::FoodItem, float>> consumedDef;
	static const std::vector<Diet::FoodItem> favoritesDef;
	static const Diet::FoodItem totalDef;
	static constexpr float totFatMaxDef = 75.0f;
	static constexpr float totSatFatMaxDef = 20.0f;
	static constexpr float totCholMaxDef = 300.0f;
	static constexpr float totSodMaxDef = 2400.0f;
	static constexpr float totCarbMaxDef = 250.0f;
	static constexpr float totFibreMaxDef = 28.0f;
	static constexpr float totProteinMaxDef = 50.0f;

	static constexpr float calorieMaxDef = 2000.0f;
	static const std::string consumedFileDef;
	static const std::string favoritesFileDef;
	static const std::string configFileDef;
	static const std::string totalsFileDef;
	static const boost::gregorian::date prevRunDateDef;
	static const boost::gregorian::date currRunDateDef;
	static constexpr _int64 startHourDef = 0;
};

