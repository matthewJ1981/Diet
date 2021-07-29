#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "NutrifitionInfoTest.h"
#include "..\NutritionInfo.h"

TEST_F(NutritionInfoTest, DefaultConstructor)
{
	EXPECT_EQ(ni.Calories(), 0);
}
