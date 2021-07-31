#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "FoodItemTest.h"
#include "../FoodItem.h"

using ::testing::Eq;

TEST_F(FoodItemTest, DefaultConstructor)
{
	EXPECT_THAT(fiDef.Name(), Eq(""));
	EXPECT_THAT(fiDef.Calories(), Eq(0));
	EXPECT_THAT(fiDef.TotalFat(), Eq(0));
	EXPECT_THAT(fiDef.SaturatedFat(), Eq(0));
	EXPECT_THAT(fiDef.TransFat(), Eq(0));
	EXPECT_THAT(fiDef.PolyUnsaturatedFat(), Eq(0));
	EXPECT_THAT(fiDef.MonoUnsaturatedFat(), Eq(0));
	EXPECT_THAT(fiDef.Cholesterol(), Eq(0));
	EXPECT_THAT(fiDef.Sodium(), Eq(0));
	EXPECT_THAT(fiDef.TotalCarbohydrates(), Eq(0));
	EXPECT_THAT(fiDef.DietryFiber(), Eq(0));
	EXPECT_THAT(fiDef.TotalSuger(), Eq(0));
	EXPECT_THAT(fiDef.AddedSugar(), Eq(0));
	EXPECT_THAT(fiDef.Erythritol(), Eq(0));
	EXPECT_THAT(fiDef.Protein(), Eq(0));
}


TEST_F(FoodItemTest, Constructor)
{
	EXPECT_THAT(fi.Name(), Eq("Bacon"));
	EXPECT_THAT(fi.Calories(), Eq(1));
	EXPECT_THAT(fi.TotalFat(), Eq(1));
	EXPECT_THAT(fi.SaturatedFat(), Eq(1));
	EXPECT_THAT(fi.TransFat(), Eq(1));
	EXPECT_THAT(fi.PolyUnsaturatedFat(), Eq(1));
	EXPECT_THAT(fi.MonoUnsaturatedFat(), Eq(1));
	EXPECT_THAT(fi.Cholesterol(), Eq(1));
	EXPECT_THAT(fi.Sodium(), Eq(1));
	EXPECT_THAT(fi.TotalCarbohydrates(), Eq(1));
	EXPECT_THAT(fi.DietryFiber(), Eq(1));
	EXPECT_THAT(fi.TotalSuger(), Eq(1));
	EXPECT_THAT(fi.AddedSugar(), Eq(1));
	EXPECT_THAT(fi.Erythritol(), Eq(1));
	EXPECT_THAT(fi.Protein(), Eq(1));
}

TEST_F(FoodItemTest, CopyConstructor)
{
	Diet::FoodItem fiC(fi);

	EXPECT_THAT(fiC, Eq(fi));
	EXPECT_THAT(fiC.Name(), Eq("Bacon"));
	EXPECT_THAT(fiC.Calories(), Eq(1));
	EXPECT_THAT(fiC.TotalFat(), Eq(1));
	EXPECT_THAT(fiC.SaturatedFat(), Eq(1));
	EXPECT_THAT(fiC.TransFat(), Eq(1));
	EXPECT_THAT(fiC.PolyUnsaturatedFat(), Eq(1));
	EXPECT_THAT(fiC.MonoUnsaturatedFat(), Eq(1));
	EXPECT_THAT(fiC.Cholesterol(), Eq(1));
	EXPECT_THAT(fiC.Sodium(), Eq(1));
	EXPECT_THAT(fiC.TotalCarbohydrates(), Eq(1));
	EXPECT_THAT(fiC.DietryFiber(), Eq(1));
	EXPECT_THAT(fiC.TotalSuger(), Eq(1));
	EXPECT_THAT(fiC.AddedSugar(), Eq(1));
	EXPECT_THAT(fiC.Erythritol(), Eq(1));
	EXPECT_THAT(fiC.Protein(), Eq(1));
}

TEST_F(FoodItemTest, CopyAssignment)
{
	fiDef = fi;
	EXPECT_THAT(fiDef, Eq(fi));
	EXPECT_THAT(fiDef.Name(), Eq("Bacon"));
	EXPECT_THAT(fiDef.Calories(), Eq(1));
	EXPECT_THAT(fiDef.TotalFat(), Eq(1));
	EXPECT_THAT(fiDef.SaturatedFat(), Eq(1));
	EXPECT_THAT(fiDef.TransFat(), Eq(1));
	EXPECT_THAT(fiDef.PolyUnsaturatedFat(), Eq(1));
	EXPECT_THAT(fiDef.MonoUnsaturatedFat(), Eq(1));
	EXPECT_THAT(fiDef.Cholesterol(), Eq(1));
	EXPECT_THAT(fiDef.Sodium(), Eq(1));
	EXPECT_THAT(fiDef.TotalCarbohydrates(), Eq(1));
	EXPECT_THAT(fiDef.DietryFiber(), Eq(1));
	EXPECT_THAT(fiDef.TotalSuger(), Eq(1));
	EXPECT_THAT(fiDef.AddedSugar(), Eq(1));
	EXPECT_THAT(fiDef.Erythritol(), Eq(1));
	EXPECT_THAT(fiDef.Protein(), Eq(1));
}

TEST_F(FoodItemTest, New)
{
	RunNew(fi, "Test/FoodItemNewTest.txt");

	EXPECT_THAT(fi.Name(), Eq("Fries"));
	EXPECT_THAT(fi.Calories(), Eq(3));
	EXPECT_THAT(fi.TotalFat(), Eq(3));
	EXPECT_THAT(fi.SaturatedFat(), Eq(3));
	EXPECT_THAT(fi.TransFat(), Eq(3));
	EXPECT_THAT(fi.PolyUnsaturatedFat(), Eq(3));
	EXPECT_THAT(fi.MonoUnsaturatedFat(), Eq(3));
	EXPECT_THAT(fi.Cholesterol(), Eq(3));
	EXPECT_THAT(fi.Sodium(), Eq(3));
	EXPECT_THAT(fi.TotalCarbohydrates(), Eq(3));
	EXPECT_THAT(fi.DietryFiber(), Eq(3));
	EXPECT_THAT(fi.TotalSuger(), Eq(3));
	EXPECT_THAT(fi.AddedSugar(), Eq(3));
	EXPECT_THAT(fi.Erythritol(), Eq(3));
	EXPECT_THAT(fi.Protein(), Eq(3));
}

TEST_F(FoodItemTest, OperatorPlusEquals)
{
	fiDef += fi;

	EXPECT_THAT(fiDef.Name(), Eq(""));
	EXPECT_THAT(fiDef.Calories(), Eq(1));
	EXPECT_THAT(fiDef.TotalFat(), Eq(1));
	EXPECT_THAT(fiDef.SaturatedFat(), Eq(1));
	EXPECT_THAT(fiDef.TransFat(), Eq(1));
	EXPECT_THAT(fiDef.PolyUnsaturatedFat(), Eq(1));
	EXPECT_THAT(fiDef.MonoUnsaturatedFat(), Eq(1));
	EXPECT_THAT(fiDef.Cholesterol(), Eq(1));
	EXPECT_THAT(fiDef.Sodium(), Eq(1));
	EXPECT_THAT(fiDef.TotalCarbohydrates(), Eq(1));
	EXPECT_THAT(fiDef.DietryFiber(), Eq(1));
	EXPECT_THAT(fiDef.TotalSuger(), Eq(1));
	EXPECT_THAT(fiDef.AddedSugar(), Eq(1));
	EXPECT_THAT(fiDef.Erythritol(), Eq(1));
	EXPECT_THAT(fiDef.Protein(), Eq(1));
}

TEST_F(FoodItemTest, OperatorPlus)
{
	Diet::FoodItem f = fiDef + fi;

	EXPECT_THAT(f.Name(), Eq(""));
	EXPECT_THAT(f.Calories(), Eq(1));
	EXPECT_THAT(f.TotalFat(), Eq(1));
	EXPECT_THAT(f.SaturatedFat(), Eq(1));
	EXPECT_THAT(f.TransFat(), Eq(1));
	EXPECT_THAT(f.PolyUnsaturatedFat(), Eq(1));
	EXPECT_THAT(f.MonoUnsaturatedFat(), Eq(1));
	EXPECT_THAT(f.Cholesterol(), Eq(1));
	EXPECT_THAT(f.Sodium(), Eq(1));
	EXPECT_THAT(f.TotalCarbohydrates(), Eq(1));
	EXPECT_THAT(f.DietryFiber(), Eq(1));
	EXPECT_THAT(f.TotalSuger(), Eq(1));
	EXPECT_THAT(f.AddedSugar(), Eq(1));
	EXPECT_THAT(f.Erythritol(), Eq(1));
	EXPECT_THAT(f.Protein(), Eq(1));
}

TEST_F(FoodItemTest, OperatorTimesEquals)
{
	fi *= 3;

	EXPECT_THAT(fi.Name(), Eq("Bacon"));
	EXPECT_THAT(fi.Calories(), Eq(3));
	EXPECT_THAT(fi.TotalFat(), Eq(3));
	EXPECT_THAT(fi.SaturatedFat(), Eq(3));
	EXPECT_THAT(fi.TransFat(), Eq(3));
	EXPECT_THAT(fi.PolyUnsaturatedFat(), Eq(3));
	EXPECT_THAT(fi.MonoUnsaturatedFat(), Eq(3));
	EXPECT_THAT(fi.Cholesterol(), Eq(3));
	EXPECT_THAT(fi.Sodium(), Eq(3));
	EXPECT_THAT(fi.TotalCarbohydrates(), Eq(3));
	EXPECT_THAT(fi.DietryFiber(), Eq(3));
	EXPECT_THAT(fi.TotalSuger(), Eq(3));
	EXPECT_THAT(fi.AddedSugar(), Eq(3));
	EXPECT_THAT(fi.Erythritol(), Eq(3));
	EXPECT_THAT(fi.Protein(), Eq(3));
}

TEST_F(FoodItemTest, OperatorTimes)
{
	Diet::FoodItem f = fi * 3;

	EXPECT_THAT(f.Name(), Eq("Bacon"));
	EXPECT_THAT(f.Calories(), Eq(3));
	EXPECT_THAT(f.TotalFat(), Eq(3));
	EXPECT_THAT(f.SaturatedFat(), Eq(3));
	EXPECT_THAT(f.TransFat(), Eq(3));
	EXPECT_THAT(f.PolyUnsaturatedFat(), Eq(3));
	EXPECT_THAT(f.MonoUnsaturatedFat(), Eq(3));
	EXPECT_THAT(f.Cholesterol(), Eq(3));
	EXPECT_THAT(f.Sodium(), Eq(3));
	EXPECT_THAT(f.TotalCarbohydrates(), Eq(3));
	EXPECT_THAT(f.DietryFiber(), Eq(3));
	EXPECT_THAT(f.TotalSuger(), Eq(3));
	EXPECT_THAT(f.AddedSugar(), Eq(3));
	EXPECT_THAT(f.Erythritol(), Eq(3));
	EXPECT_THAT(f.Protein(), Eq(3));
}

TEST_F(FoodItemTest, OperatorEquals)
{
	Diet::FoodItem f;
	RunNew(f, "Test/FoodItemNewTest.txt");
	RunNew(fi, "Test/FoodItemNewTest.txt");

	EXPECT_TRUE(fi == f);

	EXPECT_THAT(f.Name(), Eq("Fries"));
	EXPECT_THAT(f.Calories(), Eq(3));
	EXPECT_THAT(f.TotalFat(), Eq(3));
	EXPECT_THAT(f.SaturatedFat(), Eq(3));
	EXPECT_THAT(f.TransFat(), Eq(3));
	EXPECT_THAT(f.PolyUnsaturatedFat(), Eq(3));
	EXPECT_THAT(f.MonoUnsaturatedFat(), Eq(3));
	EXPECT_THAT(f.Cholesterol(), Eq(3));
	EXPECT_THAT(f.Sodium(), Eq(3));
	EXPECT_THAT(f.TotalCarbohydrates(), Eq(3));
	EXPECT_THAT(f.DietryFiber(), Eq(3));
	EXPECT_THAT(f.TotalSuger(), Eq(3));
	EXPECT_THAT(f.AddedSugar(), Eq(3));
	EXPECT_THAT(f.Erythritol(), Eq(3));
	EXPECT_THAT(f.Protein(), Eq(3));

}


TEST_F(FoodItemTest, OperatorInsertion)
{
	std::stringstream ss;
	ss << fi;

	std::string out = "Name: Bacon\n";
	out += "Calories: 1.0\n";
	out += "Total Fat: 1.0g\n";
	out += "  Saturated Fat: 1.0g\n";
	out += "  Trans Fat: 1.0g\n";
	out += "  Polyunsaturated: 1.0g\n";
	out += "  Monounsaturated: 1.0g\n";
	out += "Cholesterol: 1.0mg\n";
	out += "Sodium: 1.0mg\n";
	out += "Total Carbohydrate: 1.0g\n";
	out += "  Dietary Fibre: 1.0g\n";
	out += "  Total Sugars: 1.0g\n";
	out += "    Added Sugars: 1.0g\n";
    out += "    Erythitol: 1.0g\n";
	out += "Protein: 1.0g\n\n";

	EXPECT_THAT(ss.str(), Eq(out));

	EXPECT_THAT(fi.Name(), Eq("Bacon"));
	EXPECT_THAT(fi.Calories(), Eq(1));
	EXPECT_THAT(fi.TotalFat(), Eq(1));
	EXPECT_THAT(fi.SaturatedFat(), Eq(1));
	EXPECT_THAT(fi.TransFat(), Eq(1));
	EXPECT_THAT(fi.PolyUnsaturatedFat(), Eq(1));
	EXPECT_THAT(fi.MonoUnsaturatedFat(), Eq(1));
	EXPECT_THAT(fi.Cholesterol(), Eq(1));
	EXPECT_THAT(fi.Sodium(), Eq(1));
	EXPECT_THAT(fi.TotalCarbohydrates(), Eq(1));
	EXPECT_THAT(fi.DietryFiber(), Eq(1));
	EXPECT_THAT(fi.TotalSuger(), Eq(1));
	EXPECT_THAT(fi.AddedSugar(), Eq(1));
	EXPECT_THAT(fi.Erythritol(), Eq(1));
	EXPECT_THAT(fi.Protein(), Eq(1));
}


TEST_F(FoodItemTest, Serialize)
{
	std::string output = "Bacon 1 1 1 1 1 1 1 1 1 1 1 1 1 1";
	std::string input = SerializeTest(fi);

	EXPECT_THAT(input, Eq(output));

	EXPECT_THAT(fi.Name(), Eq("Bacon"));
	EXPECT_THAT(fi.Calories(), Eq(1));
	EXPECT_THAT(fi.TotalFat(), Eq(1));
	EXPECT_THAT(fi.SaturatedFat(), Eq(1));
	EXPECT_THAT(fi.TransFat(), Eq(1));
	EXPECT_THAT(fi.PolyUnsaturatedFat(), Eq(1));
	EXPECT_THAT(fi.MonoUnsaturatedFat(), Eq(1));
	EXPECT_THAT(fi.Cholesterol(), Eq(1));
	EXPECT_THAT(fi.Sodium(), Eq(1));
	EXPECT_THAT(fi.TotalCarbohydrates(), Eq(1));
	EXPECT_THAT(fi.DietryFiber(), Eq(1));
	EXPECT_THAT(fi.TotalSuger(), Eq(1));
	EXPECT_THAT(fi.AddedSugar(), Eq(1));
	EXPECT_THAT(fi.Erythritol(), Eq(1));
	EXPECT_THAT(fi.Protein(), Eq(1));
}

TEST_F(FoodItemTest, Deserialize)
{
	Diet::FoodItem f = DeserializeTest("deserializeTest.txt");

	EXPECT_THAT(f.Name(), Eq("Mustard"));
	EXPECT_THAT(f.Calories(), Eq(100));
	EXPECT_THAT(f.TotalFat(), Eq(0));
	EXPECT_THAT(f.SaturatedFat(), Eq(0));
	EXPECT_THAT(f.TransFat(), Eq(0));
	EXPECT_THAT(f.PolyUnsaturatedFat(), Eq(0));
	EXPECT_THAT(f.MonoUnsaturatedFat(), Eq(0));
	EXPECT_THAT(f.Cholesterol(), Eq(0));
	EXPECT_THAT(f.Sodium(), Eq(0));
	EXPECT_THAT(f.TotalCarbohydrates(), Eq(0));
	EXPECT_THAT(f.DietryFiber(), Eq(0));
	EXPECT_THAT(f.TotalSuger(), Eq(0));
	EXPECT_THAT(f.AddedSugar(), Eq(0));
	EXPECT_THAT(f.Erythritol(), Eq(0));
	EXPECT_THAT(f.Protein(), Eq(1));
}