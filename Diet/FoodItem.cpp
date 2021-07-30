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
		out << "Name: " << fi.Name() << "\n";
		out << fi.NutInfo();

		return out;
	}

	//std::ofstream& operator << (std::ofstream& out, const FoodItem& fi)
	//{
	//	std::string temp = fi.name;
	//	std::replace(temp.begin(), temp.end(), ' ', '_');
	//	out << temp << " ";
	//	out << fi.info;

	//	return out;
	//}

	//std::istream& operator >> (std::istream& in, FoodItem& fi)
	//{
	//	in >> fi.name >> fi.info;
	//	std::replace(fi.name.begin(), fi.name.end(), '_', ' ');

	//	return in;
	//}

	void FoodItem::Serialize(std::ofstream& out) const
	{
		std::string temp = name;
		std::replace(temp.begin(), temp.end(), ' ', '_');
		out << temp << " ";
		//out << fi.info;
		info.Serialize(out);
	}

	void FoodItem::Deserialize(std::ifstream& in)
	{
		in >> name;
		info.Deserialize(in);
	}
}