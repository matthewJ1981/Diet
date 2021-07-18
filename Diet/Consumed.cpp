#include "Consumed.h"
namespace Food
{
	void Consumed::Add(Food::FoodItem f)
	{
		food.push_back(f);
		total += f.NutInfo();
	}

	Info::NutritionInfo Consumed::Total() const
	{
		return total;
	}

}