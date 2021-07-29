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


	Diet::NutritionInfo ni;
};

