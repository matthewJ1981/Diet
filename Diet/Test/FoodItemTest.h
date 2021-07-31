#pragma once
#include <gtest/gtest.h>
#include "..\FoodItem.h"

class FoodItemTest : public ::testing::Test
{
protected:
	void SetUp() override
	{
		;
	}

	Diet::FoodItem fiDef;
	Diet::FoodItem fi{ "Food" };
};

