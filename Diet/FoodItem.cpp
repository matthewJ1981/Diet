#include "FoodItem.h"

namespace Food
{
	FoodItem::FoodItem(std::string name, Info::NutritionInfo info)
		:
		name(name),
		info(info)
	{}
	std::string FoodItem::Name() const
	{
		return name;
	}

	Info::NutritionInfo FoodItem::NutInfo() const
	{
		return info;
	}

	std::ostream& operator << (std::ostream& out, const FoodItem& fi)
	{
		out << fi.Name() << "\n";
		out << fi.NutInfo() << "\n";

		return out;
	}
}