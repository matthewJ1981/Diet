#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "NutrifitionInfoTest.h"
#include "../NutritionInfo.h"

TEST_F(NutritionInfoTest, DefaultConstructor)
{
	EXPECT_THAT(niDef, ::testing::Eq(Diet::NutritionInfo(0, { 0, 0, 0, 0, 0 }, 0, 0, { 0, 0, { 0, 0 }, 0 }, 0)));
}
