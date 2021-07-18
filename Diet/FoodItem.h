#pragma once
#include <string>
#include <iostream>
#include "NutritionInfo.h"

namespace Food
{
	class FoodItem
	{
	public:
		FoodItem(std::string name, Info::NutritionInfo info);
		std::string Name() const;
		Info::NutritionInfo NutInfo() const;

		friend std::ostream& operator << (std::ostream& out, const FoodItem& fi);
	private:
		std::string name;
		Info::NutritionInfo info;
	};
}
