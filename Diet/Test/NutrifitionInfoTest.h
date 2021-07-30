#pragma once
#include <gtest/gtest.h>
#include "..\NutritionInfo.h"

class NutritionInfoTest : public ::testing::Test
{
protected:
	void SetUp() override
	{
		;
	}

	Diet::NutritionInfo niDef;
	Diet::NutritionInfo ni{ 1, { 1, 1, 1, 1, 1 }, 1, 1, { 1, 1, {1, 1}, 1 }, 1 };
};

