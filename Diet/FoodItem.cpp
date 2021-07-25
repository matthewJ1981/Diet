#include "FoodItem.h"
#include <algorithm>

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
		//Produce different output if writing to a file
		if (typeid(out) == typeid(std::ofstream))
		{
			std::string temp = fi.name;
			std::replace(temp.begin(), temp.end(), ' ', '_');
			out << temp << " " << fi.info;
		}
		else
		{
			out << "Name: " << fi.Name() << "\n";
			out << fi.NutInfo();
		}
		return out;
	}

	std::istream& operator >> (std::istream& in, FoodItem& fi)
	{
		in >> fi.name >> fi.info;
		std::replace(fi.name.begin(), fi.name.end(), '_', ' ');

		return in;
	}
}