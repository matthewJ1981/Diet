#pragma once
#include <string>
#include <iostream>
#include "NutritionInfo.h"
#include <fstream>

namespace Diet
{
	class FoodItem
	{
	public:
		FoodItem() = default;
		FoodItem(std::string name, Diet::NutritionInfo info);
		std::string Name() const;
		Diet::NutritionInfo NutInfo() const;

		friend std::ostream& operator << (std::ostream& out, const FoodItem& fi);
	private:
		std::string name;
		Diet::NutritionInfo info;
	};
}
