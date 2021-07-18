#pragma once
#include <vector>
#include "FoodItem.h"

namespace Food
{
	class Consumed
	{
	public:
		void Add(Food::FoodItem f);
		Info::NutritionInfo Total() const;
	private:
		Info::NutritionInfo total;
		std::vector<Food::FoodItem> food;
	};
}
