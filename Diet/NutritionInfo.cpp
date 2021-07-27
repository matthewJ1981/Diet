#include <iostream>
#include "NutritionInfo.h"
#include "Util.h"
#include <fstream>

namespace Diet
{
	NutritionInfo::NutritionInfo()
		:
		calories(0),
		fat(Diet::Fats()),
		cholesterol(0),
		sodium(0),
		carbohydrates(Diet::Carbohydrate()),
		protein(0)
	{}

	NutritionInfo::NutritionInfo(uint calories, Fats fat, uint cholesterol, uint sodium, Carbohydrate carbs, uint protein)
		:
		calories(calories),
		fat(fat),
		cholesterol(cholesterol),
		sodium(sodium),
		carbohydrates(carbs),
		protein(protein)
	{}

	NutritionInfo NutritionInfo::NewInfo()
	{
		static constexpr int min = 0;
		static constexpr int max = 10000;
		NutritionInfo ni;

		ni.calories = Util::Input("Calories: ", min, max);
		ni.fat.total = Util::Input("Total Fat: ", min, max);
		ni.fat.saturated = Util::Input("Saturated Fat: ", min, max);
		ni.fat.trans = Util::Input("Trans Fat: ", min, max);
		ni.fat.poly = Util::Input("Polyunsaturated Fat: ", min, max);
		ni.fat.mono = Util::Input("Monounsaturated Fat: ", min, max);
		ni.cholesterol = Util::Input("Cholesterol: ", min, max);
		ni.sodium = Util::Input("Sodium: ", min, max);
		ni.carbohydrates.total = Util::Input("Total Carbs: ", min, max);
		ni.carbohydrates.dietryFiber = Util::Input("Dietry Fiber: ", min, max);
		ni.carbohydrates.sugars.total = Util::Input("Total Sugars: ", min, max);
		ni.carbohydrates.sugars.added = Util::Input("Added Sugars ", min, max);
		ni.carbohydrates.erythitol = Util::Input("Eryhitol ", min, max);
		ni.protein = Util::Input("Protein: ", min, max);

		return ni;
	}

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
		fat.total += rhs.fat.total;
		fat.saturated += rhs.fat.saturated;
		fat.trans += rhs.fat.trans;
		fat.poly += rhs.fat.poly;
		fat.mono += rhs.fat.mono;
		cholesterol += rhs.cholesterol;
		sodium += rhs.sodium;
		carbohydrates.total += rhs.carbohydrates.total;
		carbohydrates.dietryFiber += rhs.carbohydrates.dietryFiber;
		carbohydrates.sugars.total += rhs.carbohydrates.sugars.total;
		carbohydrates.sugars.added += rhs.carbohydrates.sugars.added;
		carbohydrates.erythitol += rhs.carbohydrates.erythitol;
		protein += rhs.protein;

		return *this;
	}

	std::ostream& operator << (std::ostream& out, const NutritionInfo& ni)
	{
		if (typeid(out) == typeid(std::ofstream))
		{
			out << ni.calories << " " << ni.fat.total << " " << ni.fat.saturated << " "
				<< ni.fat.trans << " " << ni.fat.poly << " " << ni.fat.mono << " "
				<< ni.cholesterol << " " << ni.sodium << " " << ni.carbohydrates.total << " "
				<< ni.carbohydrates.dietryFiber << " " << ni.carbohydrates.sugars.total << " "
				<< ni.carbohydrates.sugars.added << " " << ni.carbohydrates.erythitol << " "
				<< ni.protein;

			return out;
		}
		else
		{
			out << "Calories: " << ni.Calories() << "\n";
			out << "Total Fat: " << ni.Fat().total << "g\n";
			out << "  Saturated Fat: " << ni.Fat().saturated << "g\n";
			out << "  Trans Fat: " << ni.Fat().trans << "g\n";
			out << "  Polyunsaturated: " << ni.Fat().poly << "g\n";
			out << "  Monounsaturated: " << ni.Fat().mono << "g\n";
			out << "Cholesterol: " << ni.Cholesterol() << "mg\n";
			out << "Sodium: " << ni.Sodium() << "mg\n";
			out << "Total Carbohydrate: " << ni.Carbohydrates().total << "g\n";
			out << "  Dietary Fibre: " << ni.Carbohydrates().dietryFiber << "g\n";
			out << "  Total Sugars: " << ni.Carbohydrates().sugars.total << "g\n";
			out << "    Added Sugars: " << ni.Carbohydrates().sugars.added << "g\n";
			if (ni.Carbohydrates().erythitol)
				out << "    Erythitol: " << ni.Carbohydrates().erythitol << "g\n";
			out << "Protein: " << ni.Protein() << "g\n";

			return out;
		}
	}

	std::istream& operator >> (std::istream& in, NutritionInfo& ni)
	{
		in >> ni.calories >> ni.fat.total >> ni.fat.saturated 
			>> ni.fat.trans >> ni.fat.poly >> ni.fat.mono 
			>> ni.cholesterol >> ni.sodium >> ni.carbohydrates.total 
			>> ni.carbohydrates.dietryFiber >> ni.carbohydrates.sugars.total 
			>> ni.carbohydrates.sugars.added >> ni.carbohydrates.erythitol 
			>> ni.protein;

		return in;
	}
}

