#pragma once
#include <string>
#include <iostream>
#include "NutritionInfo.h"
#include <fstream>

/**
* Simple class to store a food item.  Consists of a name and nutritional info
*/
namespace Diet
{
	class FoodItem
	{
	public:
		FoodItem() = default;
		FoodItem(std::string name, Diet::NutritionInfo info);
		std::string Name() const;
		Diet::NutritionInfo NutInfo() const;

		// The ofstream overload will not work corretly with chaining because << for built in types will return a basic ostream& 
		// and the ostream overload will then take over.
		friend std::istream& operator >> (std::istream& in, FoodItem& fi);
		friend std::ostream& operator << (std::ostream& out, const FoodItem& fi);
		friend std::ofstream& operator << (std::ofstream& out, const FoodItem& fi);
	private:
		std::string name;
		Diet::NutritionInfo info;
	};
}
