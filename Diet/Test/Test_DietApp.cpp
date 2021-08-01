#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "DietAppTest.h"

using ::testing::Eq;

//using namespace Diet::Internal;

const std::vector<std::pair<Diet::FoodItem, float>> DietAppTest::consumedDef{};
const std::vector<Diet::FoodItem> DietAppTest::favoritesDef{};
const Diet::FoodItem DietAppTest::totalDef{ "Total" };
const std::string DietAppTest::consumedFileDef = "Data/consumed.txt";
const std::string DietAppTest::favoritesFileDef = "Data/favorites.txt";
const std::string DietAppTest::configFileDef = "Data/config.txt";
const std::string DietAppTest::totalsFileDef = "Data/totals.txt";
const date DietAppTest::prevRunDateDef = date(not_a_date_time);
const date DietAppTest::currRunDateDef = date(not_a_date_time);


TEST_F(DietAppTest, Go)
{
	FAIL();
	//EXPECT_THAT(0, Eq(0));
}

TEST_F(DietAppTest, Init)
{
	FAIL();
	//EXPECT_THAT(0, Eq(0));
}
TEST_F(DietAppTest, Reset)
{
	FAIL();
	//EXPECT_THAT(0, Eq(0));
}
TEST_F(DietAppTest, ConsumeFood)
{
	FAIL();
	//EXPECT_THAT(0, Eq(0));
}
TEST_F(DietAppTest, GetNewFood)
{
	FAIL();
	//EXPECT_THAT(0, Eq(0));
}
TEST_F(DietAppTest, GetFromFav)
{
	FAIL();
	//EXPECT_THAT(0, Eq(0));
}

TEST_F(DietAppTest, Print)
{
	FAIL();
	//EXPECT_THAT(0, Eq(0));
}
TEST_F(DietAppTest, FormatHelper)
{
	FAIL();
	//EXPECT_THAT(0, Eq(0));
}

TEST_F(DietAppTest, Serialize)
{
	FAIL();
	//EXPECT_THAT(0, Eq(0));
}
TEST_F(DietAppTest, Deserialize)
{
	DietAppImplementation::consumed.push_back({ {"Test"}, 2 });
	DietAppImplementation::favorites.push_back( {"Test" });
	DietAppImplementation::calorieMax = 500.0f;
	DietAppImplementation::prevRunDate = date(not_a_date_time);

	DietAppImplementation::Serialize();
	std::vector<std::pair<Diet::FoodItem, float>> consumedTest = DietAppImplementation::consumed;
	std::vector<Diet::FoodItem> favoritesTest = DietAppImplementation::favorites;
	float calorieMaxTest = DietAppImplementation::calorieMax;
	DietAppImplementation::consumed.clear();
	DietAppImplementation::favorites.clear();
	DietAppImplementation::calorieMax = 0.0f;
	DietAppImplementation::prevRunDate = date(not_a_date_time);

	DietAppImplementation::Deserialize();
	EXPECT_THAT(DietAppImplementation::calorieMax, Eq(calorieMaxTest));
	EXPECT_THAT(DietAppImplementation::consumed, Eq(consumedTest));
	EXPECT_THAT(DietAppImplementation::favorites, Eq(favoritesTest));
	EXPECT_THAT(DietAppImplementation::total, Eq(totalDef));
	EXPECT_THAT(DietAppImplementation::prevRunDate, Eq(prevRunDateDef));
	EXPECT_THAT(DietAppImplementation::currRunDate, Eq(currRunDateDef));
	EXPECT_THAT(DietAppImplementation::startHour, Eq(startHourDef));
}
TEST_F(DietAppTest, WriteTotal)
{
	std::ofstream out(totalsFileDef);
	out.close();
	DietAppImplementation::WriteTotal();
	std::ifstream in(totalsFileDef);
	date d;
	Diet::FoodItem f;
	in >> d;
	f.Deserialize(in);
	EXPECT_THAT(d, Eq(prevRunDateDef));
	EXPECT_THAT(f, totalDef);
	EXPECT_THAT(DietAppImplementation::calorieMax, Eq(calorieMaxDef));
	EXPECT_THAT(DietAppImplementation::consumed, Eq(consumedDef));
	EXPECT_THAT(DietAppImplementation::favorites, Eq(favoritesDef));
	EXPECT_THAT(DietAppImplementation::currRunDate, Eq(currRunDateDef));
	EXPECT_THAT(DietAppImplementation::startHour, Eq(startHourDef));
}
TEST_F(DietAppTest, ReadTotal)
{
	DietAppImplementation::ReadTotal();
	EXPECT_THAT(DietAppImplementation::calorieMax, Eq(calorieMaxDef));
	EXPECT_THAT(DietAppImplementation::consumed, Eq(consumedDef));
	EXPECT_THAT(DietAppImplementation::favorites, Eq(favoritesDef));
	EXPECT_THAT(DietAppImplementation::total, Eq(totalDef));
	EXPECT_THAT(DietAppImplementation::prevRunDate, Eq(prevRunDateDef));
	EXPECT_THAT(DietAppImplementation::currRunDate, Eq(currRunDateDef));
	EXPECT_THAT(DietAppImplementation::startHour, Eq(startHourDef));
}
TEST_F(DietAppTest, ClearConsumedFile)
{
	DietAppImplementation::consumed.push_back({ { "Food"}, 1 });
	DietAppImplementation::Serialize();
	std::ifstream in(consumedFileDef);
	if (!in)
		abort();
	std::string before;
	in >> before;
	in.close();
	DietAppImplementation::ClearConsumedFile();
	in.open(consumedFileDef);
	if (!in)
		abort();
	std::string after;
	in >> after;
	EXPECT_TRUE(!before.empty());
	EXPECT_TRUE(after.empty());

	EXPECT_THAT(DietAppImplementation::calorieMax, Eq(calorieMaxDef));
	EXPECT_THAT(DietAppImplementation::favorites, Eq(favoritesDef));
	EXPECT_THAT(DietAppImplementation::total, Eq(totalDef));
	EXPECT_THAT(DietAppImplementation::prevRunDate, Eq(prevRunDateDef));
	EXPECT_THAT(DietAppImplementation::currRunDate, Eq(currRunDateDef));
	EXPECT_THAT(DietAppImplementation::startHour, Eq(startHourDef));

}
TEST_F(DietAppTest, History)
{
	DietAppImplementation::History();
	EXPECT_THAT(DietAppImplementation::calorieMax, Eq(calorieMaxDef));
	EXPECT_THAT(DietAppImplementation::consumed, Eq(consumedDef));
	EXPECT_THAT(DietAppImplementation::favorites, Eq(favoritesDef));
	EXPECT_THAT(DietAppImplementation::total, Eq(totalDef));
	EXPECT_THAT(DietAppImplementation::prevRunDate, Eq(prevRunDateDef));
	EXPECT_THAT(DietAppImplementation::currRunDate, Eq(currRunDateDef));
	EXPECT_THAT(DietAppImplementation::startHour, Eq(startHourDef));
}
TEST_F(DietAppTest, Options)
{
	DietAppImplementation::Options();
	EXPECT_THAT(DietAppImplementation::calorieMax, Eq(calorieMaxDef));
	EXPECT_THAT(DietAppImplementation::consumed, Eq(consumedDef));
	EXPECT_THAT(DietAppImplementation::favorites, Eq(favoritesDef));
	EXPECT_THAT(DietAppImplementation::total, Eq(totalDef));
	EXPECT_THAT(DietAppImplementation::prevRunDate, Eq(prevRunDateDef));
	EXPECT_THAT(DietAppImplementation::currRunDate, Eq(currRunDateDef));
	EXPECT_THAT(DietAppImplementation::startHour, Eq(startHourDef));
}
TEST_F(DietAppTest, SetCalorieMax)
{
	float newCalMax = 3000.0f;
	DietAppImplementation::SetCalorieMax(newCalMax);
	EXPECT_THAT(DietAppImplementation::calorieMax, Eq(newCalMax));
	EXPECT_THAT(DietAppImplementation::consumed, Eq(consumedDef));
	EXPECT_THAT(DietAppImplementation::favorites, Eq(favoritesDef));
	EXPECT_THAT(DietAppImplementation::total, Eq(totalDef));
	EXPECT_THAT(DietAppImplementation::prevRunDate, Eq(prevRunDateDef));
	EXPECT_THAT(DietAppImplementation::currRunDate, Eq(currRunDateDef));
	EXPECT_THAT(DietAppImplementation::startHour, Eq(startHourDef));
}