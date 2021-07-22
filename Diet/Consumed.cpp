#include "Consumed.h"

namespace Diet
{
	void Consumed::Add(Diet::FoodItem f)
	{
		food.push_back(f);
		total += f.NutInfo();
	}

	Diet::NutritionInfo Consumed::Total() const
	{
		return total;
	}

}