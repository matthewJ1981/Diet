#include "FoodItem.h"
#include "FoodItemImplementation.h"

#include <algorithm>
#include <iomanip>

namespace Diet
{
	FoodItem::FoodItem()
		:
		impl(std::make_unique<Internal::FoodItemImplementation>())
	{}

	FoodItem::FoodItem(std::string name)
		:
		impl(std::make_unique<Internal::FoodItemImplementation>(name))
	{}

	FoodItem::FoodItem(const FoodItem & rhs)
		:
		impl(std::make_unique<Internal::FoodItemImplementation>())
	{
		*impl = *rhs.impl;
	}

	FoodItem& FoodItem::operator=(const FoodItem& rhs)
	{
		*impl = *rhs.impl;
		return *this;
	}

	FoodItem::~FoodItem()
	{}

	std::string FoodItem::Name() const
	{
		return impl->name;
	}

	float FoodItem::Calories() const
	{
		return impl->info.calories;
	}

	float FoodItem::TotalFat() const
	{
		return impl->info.fat.total;
	}

	float FoodItem::SaturatedFat() const
	{
		return impl->info.fat.saturated;
	}

	float FoodItem::TransFat() const
	{
		return impl->info.fat.trans;
	}

	float FoodItem::PolyUnsaturatedFat() const
	{
		return impl->info.fat.poly;
	}

	float FoodItem::MonoUnsaturatedFat() const
	{
		return impl->info.fat.mono;
	}

	float FoodItem::Cholesterol() const
	{
		return impl->info.cholesterol;
	}

	float FoodItem::Sodium() const
	{
		return impl->info.sodium;
	}

	float FoodItem::TotalCarbohydrates() const
	{
		return impl->info.carbohydrates.total;
	}

	float FoodItem::DietryFiber() const
	{
		return impl->info.carbohydrates.dietryFiber;
	}

	float FoodItem::TotalSuger() const
	{
		return impl->info.carbohydrates.sugars.total;
	}

	float FoodItem::AddedSugar() const
	{
		return impl->info.carbohydrates.sugars.added;
	}

	float FoodItem::Erythritol() const
	{
		return impl->info.carbohydrates.erythritol;
	}

	float FoodItem::Protein() const
	{
		return impl->info.protein;
	}

	FoodItem& FoodItem::operator+=(const FoodItem& rhs)
	{
		impl->info += rhs.impl->info;
		return *this;
	}

	const FoodItem FoodItem::operator+(const FoodItem& rhs)
	{
		FoodItem result = *this;
		return result += rhs;
	}

	FoodItem& FoodItem::operator*=(const float rhs)
	{
		impl->info *= rhs;
		return *this;
	}

	const FoodItem FoodItem::operator*(const float rhs)
	{
		FoodItem result = *this;
		return result *= rhs;
	}

	bool FoodItem::operator==(const FoodItem& rhs) const
	{
		return impl->name == rhs.impl->name && impl->info == rhs.impl->info;
	}

	void FoodItem::New(std::ostream& out, std::istream& in)
	{
		out << "Name of Food? ";
		std::getline(in, impl->name);
		impl->info.New(out, in);
	}

	std::ostream& operator << (std::ostream& out, const FoodItem& fi)
	{
		out << "Name: " << fi.Name() << "\n";
		out << fi.impl->info << "\n";

		return out;
	}

	void FoodItem::Serialize(std::ofstream& out) const
	{
		std::string temp = impl->name;
		std::replace(temp.begin(), temp.end(), ' ', '_');
		out << temp << " ";
		//out << fi.info;
		impl->info.Serialize(out);
	}

	void FoodItem::Deserialize(std::ifstream& in)
	{
		in >> impl->name;
		impl->info.Deserialize(in);
	}
	void FoodItem::Clear()
	{
		impl->info *= 0;
	}
}