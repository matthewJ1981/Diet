#pragma once
#include <vector>
#include "FoodItem.h"

namespace Diet
{
	class Consumed
	{
	public:
		void Add(Diet::FoodItem f);
		Diet::NutritionInfo Total() const;
	private:
		Diet::NutritionInfo total;
		std::vector<Diet::FoodItem> food;
	};
}
