#include <iostream>
#include "NutritionInfo.h"

namespace Info
{
	uint Sugar::total() const
	{
		return added;
	}

	uint Fats::total() const
	{
		return saturated + trans + poly + mono;
	}

	uint Carbohydrate::total() const
	{
		return dietryFiber + sugars.total() + erythitol;
	}

	NutritionInfo::NutritionInfo(uint calories, Fats fat, uint cholesterol, uint sodium, Carbohydrate carbs, uint protein)
		:
		calories(calories),
		fat(fat),
		cholesterol(cholesterol),
		sodium(sodium),
		carbohydrates(carbs),
		protein(protein)
	{}

	uint NutritionInfo::Calories() const
	{
		return calories;
	}

	Fats NutritionInfo::Fat() const
	{
		return fat;
	}

	uint NutritionInfo::Cholesterol() const
	{
		return cholesterol;
	}

	uint NutritionInfo::Sodium() const
	{
		return sodium;
	}

	Carbohydrate NutritionInfo::Carbohydrates() const
	{
		return carbohydrates;
	}

	uint NutritionInfo::Protein() const
	{
		return protein;
	}

	NutritionInfo& NutritionInfo::operator += (const NutritionInfo& rhs)
	{
		calories += rhs.calories;
		fat.saturated += rhs.fat.saturated;
		fat.trans += rhs.fat.trans;
		fat.poly += rhs.fat.poly;
		fat.mono += rhs.fat.mono;
		cholesterol += rhs.cholesterol;
		sodium += rhs.sodium;
		carbohydrates.dietryFiber += rhs.carbohydrates.dietryFiber;
		carbohydrates.sugars.added += rhs.carbohydrates.sugars.added;
		carbohydrates.erythitol += rhs.carbohydrates.erythitol;
		protein += rhs.protein;

		return *this;
	}

	std::ostream& operator << (std::ostream& out, const NutritionInfo& ni)
	{
		out << "Calories: " << ni.Calories() << "\n";
		out << "Total Fat: " << ni.Fat().total() << "g\n";
		out << "  Saturated Fat: " << ni.Fat().saturated << "g\n";
		out << "  Trans Fat: " << ni.Fat().trans << "g\n";
		out << "  Polyunsaturated: " << ni.Fat().poly << "g\n";
		out << "  Monounsaturated: " << ni.Fat().mono << "g\n";
		out << "Cholesterol: " << ni.Cholesterol() << "mg\n";
		out << "Sodium: " << ni.Sodium() << "mg\n";
		out << "Total Carbohydrate: " << ni.Carbohydrates().total() << "g\n";
		out << "  Dietary Fibre: " << ni.Carbohydrates().dietryFiber << "g\n";
		out << "  Total Sugars: " << ni.Carbohydrates().sugars.total() << "g\n";
		out << "    Added Sugars: " << ni.Carbohydrates().sugars.added << "g\n";
		if (ni.Carbohydrates().erythitol)
			out << "    Erythitol: " << ni.Carbohydrates().erythitol << "g\n";
		out << "Protein: " << ni.Protein() << "g\n";

		return out;
	}
}

