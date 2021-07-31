#include "FoodItemImplementation.h"
#include "Util.h"
#include <iomanip>

using Util::Eq;

namespace Diet
{
	namespace Internal
	{
		bool Sugar::operator == (const Sugar& rhs) const
		{
			return Eq(total, rhs.total) && Eq(added, rhs.added);
		}

		bool Fats::operator == (const Fats& rhs) const
		{
			return Eq(total, rhs.total) && Eq(saturated, rhs.saturated) &&
				Eq(trans, rhs.trans) && Eq(poly, rhs.poly) && Eq(mono, rhs.mono);
		}

		bool Carbohydrate::operator == (const Carbohydrate& rhs) const
		{
			return Eq(total, rhs.total) && Eq(dietryFiber, rhs.dietryFiber) && sugars == rhs.sugars && Eq(erythritol, rhs.erythritol);
		}


		FoodItemImplementation::NutritionInfo::NutritionInfo()
			:
			calories(0.0f),
			fat({ 0.0f, 0.0f }),
			cholesterol(0.0f),
			sodium(0.0f),
			carbohydrates({ 0.0f, 0.0f, { 0.0f, 0.0f }, 0.0f }),
			protein(0.0f)
		{}

		FoodItemImplementation::NutritionInfo& FoodItemImplementation::NutritionInfo::operator += (const NutritionInfo& rhs)
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
			carbohydrates.erythritol += rhs.carbohydrates.erythritol;
			protein += rhs.protein;

			return *this;
		}

		FoodItemImplementation::NutritionInfo& FoodItemImplementation::NutritionInfo::operator *=(const float rhs)
		{
			calories *= rhs;
			fat.total *= rhs;
			fat.saturated *= rhs;
			fat.trans *= rhs;
			fat.poly *= rhs;
			fat.mono *= rhs;
			cholesterol *= rhs;
			sodium *= rhs;
			carbohydrates.total *= rhs;
			carbohydrates.dietryFiber *= rhs;
			carbohydrates.sugars.total *= rhs;
			carbohydrates.sugars.added *= rhs;
			carbohydrates.erythritol *= rhs;
			protein *= rhs;

			return *this;
		}

		bool FoodItemImplementation::NutritionInfo::operator== (const NutritionInfo& rhs)
		{
			return Eq(calories, rhs.calories) &&
				fat == rhs.fat &&
				Eq(cholesterol, rhs.cholesterol) &&
				Eq(sodium, rhs.sodium) &&
				carbohydrates == rhs.carbohydrates &&
				Eq(protein, rhs.protein);

		}

		std::ostream& operator << (std::ostream& out, const FoodItemImplementation::NutritionInfo& ni)
		{
			out << std::setprecision(1) << std::fixed;
			out << "Calories: " << ni.calories << "\n";
			out << "Total Fat: " << ni.fat.total << "g\n";
			out << "  Saturated Fat: " << ni.fat.saturated << "g\n";
			out << "  Trans Fat: " << ni.fat.trans << "g\n";
			out << "  Polyunsaturated: " << ni.fat.poly << "g\n";
			out << "  Monounsaturated: " << ni.fat.mono << "g\n";
			out << "Cholesterol: " << ni.cholesterol << "mg\n";
			out << "Sodium: " << ni.sodium << "mg\n";
			out << "Total Carbohydrate: " << ni.carbohydrates.total << "g\n";
			out << "  Dietary Fibre: " << ni.carbohydrates.dietryFiber << "g\n";
			out << "  Total Sugars: " << ni.carbohydrates.sugars.total << "g\n";
			out << "    Added Sugars: " << ni.carbohydrates.sugars.added << "g\n";
			if (ni.carbohydrates.erythritol)
				out << "    Erythitol: " << ni.carbohydrates.erythritol << "g\n";
			out << "Protein: " << ni.protein << "g\n";

			return out;
		}

		void FoodItemImplementation::NutritionInfo::Serialize(std::ofstream& out) const
		{
			out << calories << " " << fat.total << " " << fat.saturated << " "
				<< fat.trans << " " << fat.poly << " " << fat.mono << " "
				<< cholesterol << " " << sodium << " " << carbohydrates.total << " "
				<< carbohydrates.dietryFiber << " " << carbohydrates.sugars.total << " "
				<< carbohydrates.sugars.added << " " << carbohydrates.erythritol << " "
				<< protein;
		}

		void FoodItemImplementation::NutritionInfo::Deserialize(std::ifstream& in)
		{
			in >> calories >> fat.total >> fat.saturated
				>> fat.trans >> fat.poly >> fat.mono
				>> cholesterol >> sodium >> carbohydrates.total
				>> carbohydrates.dietryFiber >> carbohydrates.sugars.total
				>> carbohydrates.sugars.added >> carbohydrates.erythritol
				>> protein;
		}

		void FoodItemImplementation::NutritionInfo::New()
		{
			static constexpr float min = 0.0f;
			static constexpr float max = 10000.0f;

			calories = Util::Input("Calories: ", min, max);
			fat.total = Util::Input("Total Fat: ", min, max);
			fat.saturated = Util::Input("Saturated Fat: ", min, max);
			fat.trans = Util::Input("Trans Fat: ", min, max);
			fat.poly = Util::Input("Polyunsaturated Fat: ", min, max);
			fat.mono = Util::Input("Monounsaturated Fat: ", min, max);
			cholesterol = Util::Input("Cholesterol: ", min, max);
			sodium = Util::Input("Sodium: ", min, max);
			carbohydrates.total = Util::Input("Total Carbs: ", min, max);
			carbohydrates.dietryFiber = Util::Input("Dietry Fiber: ", min, max);
			carbohydrates.sugars.total = Util::Input("Total Sugars: ", min, max);
			carbohydrates.sugars.added = Util::Input("Added Sugars ", min, max);
			carbohydrates.erythritol = Util::Input("Eryhitol ", min, max);
			protein = Util::Input("Protein: ", min, max);
		}

		FoodItemImplementation::FoodItemImplementation() = default;
		FoodItemImplementation::FoodItemImplementation(std::string name)
			:
			name(name),
			info(NutritionInfo())
		{}
	}
}