#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "NutrifitionInfoTest.h"
#include "../NutritionInfo.h"

TEST_F(NutritionInfoTest, DefaultConstructor)
{
	EXPECT_EQ(niDef, (Diet::NutritionInfo(0, Diet::Fats{ 0, 0, 0, 0, 0 }, 0, 0, Diet::Carbohydrate{ 0, 0, Diet::Sugar{ 0, 0 }, 0 }, 0)));
}
