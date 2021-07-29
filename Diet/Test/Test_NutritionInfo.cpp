#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "NutrifitionInfoTest.h"

TEST_F(NutritionInfoTest, DefaultConstructor)
{
	EXPECT_EQ(niDef.Calories(), 0);
}
