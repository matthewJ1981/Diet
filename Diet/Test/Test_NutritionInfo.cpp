#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "NutrifitionInfoTest.h"
#include "../NutritionInfo.h"

using ::testing::Eq;

TEST_F(NutritionInfoTest, DefaultConstructor)
{
	EXPECT_THAT(niDef.Calories(), Eq(0));
	EXPECT_THAT(niDef.Fat().total, Eq(0));
	EXPECT_THAT(niDef.Fat().saturated, Eq(0));
	EXPECT_THAT(niDef.Fat().trans, Eq(0));
	EXPECT_THAT(niDef.Fat().poly, Eq(0));
	EXPECT_THAT(niDef.Fat().mono, Eq(0));
	EXPECT_THAT(niDef.Cholesterol(), Eq(0));
	EXPECT_THAT(niDef.Sodium(), Eq(0));
	EXPECT_THAT(niDef.Carbohydrates().total, Eq(0));
	EXPECT_THAT(niDef.Carbohydrates().dietryFiber, Eq(0));
	EXPECT_THAT(niDef.Carbohydrates().sugars.total, Eq(0));
	EXPECT_THAT(niDef.Carbohydrates().sugars.added, Eq(0));
	EXPECT_THAT(niDef.Carbohydrates().erythitol, Eq(0));
	EXPECT_THAT(niDef.Protein(), Eq(0));
}

TEST_F(NutritionInfoTest, Constructor)
{
	EXPECT_THAT(ni.Calories(), Eq(1));
	EXPECT_THAT(ni.Fat().total, Eq(1));
	EXPECT_THAT(ni.Fat().saturated, Eq(1));
	EXPECT_THAT(ni.Fat().trans, Eq(1));
	EXPECT_THAT(ni.Fat().poly, Eq(1));
	EXPECT_THAT(ni.Fat().mono, Eq(1));
	EXPECT_THAT(ni.Cholesterol(), Eq(1));
	EXPECT_THAT(ni.Sodium(), Eq(1));
	EXPECT_THAT(ni.Carbohydrates().total, Eq(1));
	EXPECT_THAT(ni.Carbohydrates().dietryFiber, Eq(1));
	EXPECT_THAT(ni.Carbohydrates().sugars.total, Eq(1));
	EXPECT_THAT(ni.Carbohydrates().sugars.added, Eq(1));
	EXPECT_THAT(ni.Carbohydrates().erythitol, Eq(1));
	EXPECT_THAT(ni.Protein(), Eq(1));
}

TEST_F(NutritionInfoTest, CopyConstructor)
{
	Diet::NutritionInfo niC(ni);
	EXPECT_THAT(niC, Eq(ni));
}

TEST_F(NutritionInfoTest, CopyAssignment)
{
	niDef = ni;
	EXPECT_THAT(niDef, Eq(ni));
}

TEST_F(NutritionInfoTest, NewInfo)
{
	FAIL();
	//EXPECT_THAT(ni.Calories(), Eq(1));
	//EXPECT_THAT(ni.Fat().total, Eq(1));
	//EXPECT_THAT(ni.Fat().saturated, Eq(1));
	//EXPECT_THAT(ni.Fat().trans, Eq(1));
	//EXPECT_THAT(ni.Fat().poly, Eq(1));
	//EXPECT_THAT(ni.Fat().mono, Eq(1));
	//EXPECT_THAT(ni.Cholesterol(), Eq(1));
	//EXPECT_THAT(ni.Sodium(), Eq(1));
	//EXPECT_THAT(ni.Carbohydrates().total, Eq(1));
	//EXPECT_THAT(ni.Carbohydrates().dietryFiber, Eq(1));
	//EXPECT_THAT(ni.Carbohydrates().sugars.total, Eq(1));
	//EXPECT_THAT(ni.Carbohydrates().sugars.added, Eq(1));
	//EXPECT_THAT(ni.Carbohydrates().erythitol, Eq(1));
	//EXPECT_THAT(ni.Protein(), Eq(1));
}

TEST_F(NutritionInfoTest, OperatorPlusEquals)
{
	ni += ni;
	EXPECT_THAT(ni.Calories(), Eq(2));
	EXPECT_THAT(ni.Fat().total, Eq(2));
	EXPECT_THAT(ni.Fat().saturated, Eq(2));
	EXPECT_THAT(ni.Fat().trans, Eq(2));
	EXPECT_THAT(ni.Fat().poly, Eq(2));
	EXPECT_THAT(ni.Fat().mono, Eq(2));
	EXPECT_THAT(ni.Cholesterol(), Eq(2));
	EXPECT_THAT(ni.Sodium(), Eq(2));
	EXPECT_THAT(ni.Carbohydrates().total, Eq(2));
	EXPECT_THAT(ni.Carbohydrates().dietryFiber, Eq(2));
	EXPECT_THAT(ni.Carbohydrates().sugars.total, Eq(2));
	EXPECT_THAT(ni.Carbohydrates().sugars.added, Eq(2));
	EXPECT_THAT(ni.Carbohydrates().erythitol, Eq(2));
	EXPECT_THAT(ni.Protein(), Eq(2));
}

TEST_F(NutritionInfoTest, OperatorPlus)
{
	Diet::NutritionInfo n = ni + ni;
	EXPECT_THAT(n.Calories(), Eq(2));
	EXPECT_THAT(n.Fat().total, Eq(2));
	EXPECT_THAT(n.Fat().saturated, Eq(2));
	EXPECT_THAT(n.Fat().trans, Eq(2));
	EXPECT_THAT(n.Fat().poly, Eq(2));
	EXPECT_THAT(n.Fat().mono, Eq(2));
	EXPECT_THAT(n.Cholesterol(), Eq(2));
	EXPECT_THAT(n.Sodium(), Eq(2));
	EXPECT_THAT(n.Carbohydrates().total, Eq(2));
	EXPECT_THAT(n.Carbohydrates().dietryFiber, Eq(2));
	EXPECT_THAT(n.Carbohydrates().sugars.total, Eq(2));
	EXPECT_THAT(n.Carbohydrates().sugars.added, Eq(2));
	EXPECT_THAT(n.Carbohydrates().erythitol, Eq(2));
	EXPECT_THAT(n.Protein(), Eq(2));
}

TEST_F(NutritionInfoTest, OperatorTimesEquals)
{
	ni *= 3;
	EXPECT_THAT(ni.Calories(), Eq(3));
	EXPECT_THAT(ni.Fat().total, Eq(3));
	EXPECT_THAT(ni.Fat().saturated, Eq(3));
	EXPECT_THAT(ni.Fat().trans, Eq(3));
	EXPECT_THAT(ni.Fat().poly, Eq(3));
	EXPECT_THAT(ni.Fat().mono, Eq(3));
	EXPECT_THAT(ni.Cholesterol(), Eq(3));
	EXPECT_THAT(ni.Sodium(), Eq(3));
	EXPECT_THAT(ni.Carbohydrates().total, Eq(3));
	EXPECT_THAT(ni.Carbohydrates().dietryFiber, Eq(3));
	EXPECT_THAT(ni.Carbohydrates().sugars.total, Eq(3));
	EXPECT_THAT(ni.Carbohydrates().sugars.added, Eq(3));
	EXPECT_THAT(ni.Carbohydrates().erythitol, Eq(3));
	EXPECT_THAT(ni.Protein(), Eq(3));
}

TEST_F(NutritionInfoTest, OperatorTimes)
{
	Diet::NutritionInfo n = ni * 3;
	EXPECT_THAT(n.Calories(), Eq(3));
	EXPECT_THAT(n.Fat().total, Eq(3));
	EXPECT_THAT(n.Fat().saturated, Eq(3));
	EXPECT_THAT(n.Fat().trans, Eq(3));
	EXPECT_THAT(n.Fat().poly, Eq(3));
	EXPECT_THAT(n.Fat().mono, Eq(3));
	EXPECT_THAT(n.Cholesterol(), Eq(3));
	EXPECT_THAT(n.Sodium(), Eq(3));
	EXPECT_THAT(n.Carbohydrates().total, Eq(3));
	EXPECT_THAT(n.Carbohydrates().dietryFiber, Eq(3));
	EXPECT_THAT(n.Carbohydrates().sugars.total, Eq(3));
	EXPECT_THAT(n.Carbohydrates().sugars.added, Eq(3));
	EXPECT_THAT(n.Carbohydrates().erythitol, Eq(3));
	EXPECT_THAT(n.Protein(), Eq(3));
}

TEST_F(NutritionInfoTest, OperatorEqualsDef)
{
	EXPECT_TRUE((niDef == Diet::NutritionInfo(0, { 0, 0, 0, 0, 0 }, 0, 0, { 0, 0, { 0, 0 }, 0 }, 0)));

	EXPECT_THAT(niDef.Calories(), Eq(0));
	EXPECT_THAT(niDef.Fat().total, Eq(0));
	EXPECT_THAT(niDef.Fat().saturated, Eq(0));
	EXPECT_THAT(niDef.Fat().trans, Eq(0));
	EXPECT_THAT(niDef.Fat().poly, Eq(0));
	EXPECT_THAT(niDef.Fat().mono, Eq(0));
	EXPECT_THAT(niDef.Cholesterol(), Eq(0));
	EXPECT_THAT(niDef.Sodium(), Eq(0));
	EXPECT_THAT(niDef.Carbohydrates().total, Eq(0));
	EXPECT_THAT(niDef.Carbohydrates().dietryFiber, Eq(0));
	EXPECT_THAT(niDef.Carbohydrates().sugars.total, Eq(0));
	EXPECT_THAT(niDef.Carbohydrates().sugars.added, Eq(0));
	EXPECT_THAT(niDef.Carbohydrates().erythitol, Eq(0));
	EXPECT_THAT(niDef.Protein(), Eq(0));

}

TEST_F(NutritionInfoTest, OperatorEquals)
{
	EXPECT_TRUE((ni == Diet::NutritionInfo(1, { 1, 1, 1, 1, 1 }, 1, 1, { 1, 1, { 1, 1 }, 1 }, 1)));

	EXPECT_THAT(ni.Calories(), Eq(1));
	EXPECT_THAT(ni.Fat().total, Eq(1));
	EXPECT_THAT(ni.Fat().saturated, Eq(1));
	EXPECT_THAT(ni.Fat().trans, Eq(1));
	EXPECT_THAT(ni.Fat().poly, Eq(1));
	EXPECT_THAT(ni.Fat().mono, Eq(1));
	EXPECT_THAT(ni.Cholesterol(), Eq(1));
	EXPECT_THAT(ni.Sodium(), Eq(1));
	EXPECT_THAT(ni.Carbohydrates().total, Eq(1));
	EXPECT_THAT(ni.Carbohydrates().dietryFiber, Eq(1));
	EXPECT_THAT(ni.Carbohydrates().sugars.total, Eq(1));
	EXPECT_THAT(ni.Carbohydrates().sugars.added, Eq(1));
	EXPECT_THAT(ni.Carbohydrates().erythitol, Eq(1));
	EXPECT_THAT(ni.Protein(), Eq(1));

}

TEST_F(NutritionInfoTest, OperatorInsertion)
{
	std::stringstream ss;
	ss << ni;

	std::string out = "";
	out += "Calories: 1\n";
	out += "Total Fat: 1g\n";
	out += "  Saturated Fat: 1g\n";
	out += "  Trans Fat: 1g\n";
	out += "  Polyunsaturated: 1g\n";
	out += "  Monounsaturated: 1g\n";
	out += "Cholesterol: 1mg\n";
	out += "Sodium: 1mg\n";
	out += "Total Carbohydrate: 1g\n";
	out += "  Dietary Fibre: 1g\n";
	out += "  Total Sugars: 1g\n";
	out += "    Added Sugars: 1g\n";
    out += "    Erythitol: 1g\n";
	out += "Protein: 1g\n";

	EXPECT_THAT(ss.str(), Eq(out));

	EXPECT_THAT(ni.Calories(), Eq(1));
	EXPECT_THAT(ni.Fat().total, Eq(1));
	EXPECT_THAT(ni.Fat().saturated, Eq(1));
	EXPECT_THAT(ni.Fat().trans, Eq(1));
	EXPECT_THAT(ni.Fat().poly, Eq(1));
	EXPECT_THAT(ni.Fat().mono, Eq(1));
	EXPECT_THAT(ni.Cholesterol(), Eq(1));
	EXPECT_THAT(ni.Sodium(), Eq(1));
	EXPECT_THAT(ni.Carbohydrates().total, Eq(1));
	EXPECT_THAT(ni.Carbohydrates().dietryFiber, Eq(1));
	EXPECT_THAT(ni.Carbohydrates().sugars.total, Eq(1));
	EXPECT_THAT(ni.Carbohydrates().sugars.added, Eq(1));
	EXPECT_THAT(ni.Carbohydrates().erythitol, Eq(1));
	EXPECT_THAT(ni.Protein(), Eq(1));
}

TEST_F(NutritionInfoTest, OperatorExtraction)
{
	FAIL();
	//EXPECT_THAT(ni.Calories(), Eq(1));
	//EXPECT_THAT(ni.Fat().total, Eq(1));
	//EXPECT_THAT(ni.Fat().saturated, Eq(1));
	//EXPECT_THAT(ni.Fat().trans, Eq(1));
	//EXPECT_THAT(ni.Fat().poly, Eq(1));
	//EXPECT_THAT(ni.Fat().mono, Eq(1));
	//EXPECT_THAT(ni.Cholesterol(), Eq(1));
	//EXPECT_THAT(ni.Sodium(), Eq(1));
	//EXPECT_THAT(ni.Carbohydrates().total, Eq(1));
	//EXPECT_THAT(ni.Carbohydrates().dietryFiber, Eq(1));
	//EXPECT_THAT(ni.Carbohydrates().sugars.total, Eq(1));
	//EXPECT_THAT(ni.Carbohydrates().sugars.added, Eq(1));
	//EXPECT_THAT(ni.Carbohydrates().erythitol, Eq(1));
	//EXPECT_THAT(ni.Protein(), Eq(1));
}
