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

TEST_F(NutritionInfoTest, CopyAssignment)
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

TEST_F(NutritionInfoTest, Assign)
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

TEST_F(NutritionInfoTest, OperatorPlus)
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

TEST_F(NutritionInfoTest, OperatorTimesEquals)
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

TEST_F(NutritionInfoTest, OperatorTimes)
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
