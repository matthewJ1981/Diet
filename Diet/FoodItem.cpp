#include "FoodItem.h"

namespace Diet
{
	FoodItem::FoodItem(std::string name, Diet::NutritionInfo info)
		:
		name(name),
		info(info)
	{}
	std::string FoodItem::Name() const
	{
		return name;
	}

	Diet::NutritionInfo FoodItem::NutInfo() const
	{
		return info;
	}

	std::ostream& operator << (std::ostream& out, const FoodItem& fi)
	{
		if (typeid(out) == typeid(std::ofstream))
		{
			out << fi.name << " " << fi.info;
				return out;
		}
		else
		{
			out << "Name: " << fi.Name() << "\n";
			out << fi.NutInfo();
			return out;

		}
	}

	std::istream& operator >> (std::istream& in, FoodItem& fi)
	{
		in >> fi.name >> fi.info;

		return in;
	}
}