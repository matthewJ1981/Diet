#pragma once
#include "Util.h"
#include "NIStructs.h"

namespace Diet
{
	namespace Internal
	{
		class NutritionInfoImplementation
		{
		public:
			NutritionInfoImplementation()
				:
			calories( 0 ),
			fat({ 0, 0 }),
			cholesterol(0),
			sodium( 0 ),
			carbohydrates({ 0, 0, { 0, 0 }, 0 }),
			protein( 0 )
			{}

			NutritionInfoImplementation(uint calories, Fats fat, uint cholesterol, uint sodium, Carbohydrate carbs, uint protein)
				:
				calories(calories),
				fat(fat),
				cholesterol(cholesterol),
				sodium(sodium),
				carbohydrates(carbs),
				protein(protein)
			{}

			void NewInfo()
			{
				static constexpr int min = 0;
				static constexpr int max = 10000;

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
				carbohydrates.erythitol = Util::Input("Eryhitol ", min, max);
				protein = Util::Input("Protein: ", min, max);

			}

			NutritionInfoImplementation& operator *=(const float rhs)
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
				carbohydrates.erythitol *= rhs;
				protein *= rhs;

				return *this;
			}

			NutritionInfoImplementation& operator += (const NutritionInfoImplementation& rhs)
			{
				calories += calories;
				fat.total += fat.total;
				fat.saturated += fat.saturated;
				fat.trans += fat.trans;
				fat.poly += fat.poly;
				fat.mono += fat.mono;
				cholesterol += cholesterol;
				sodium += sodium;
				carbohydrates.total += carbohydrates.total;
				carbohydrates.dietryFiber += carbohydrates.dietryFiber;
				carbohydrates.sugars.total += carbohydrates.sugars.total;
				carbohydrates.sugars.added += carbohydrates.sugars.added;
				carbohydrates.erythitol += carbohydrates.erythitol;
				protein += protein;

				return *this;
			}

			bool operator== (const NutritionInfoImplementation& rhs)
			{
				return calories == rhs.calories &&
					fat == rhs.fat &&
					cholesterol == rhs.cholesterol &&
					sodium == rhs.sodium &&
					carbohydrates == rhs.carbohydrates &&
					protein == rhs.protein;

			}
			uint calories;
			Fats fat;
			uint cholesterol;
			uint sodium;
			Carbohydrate carbohydrates;
			uint protein;
		};
	}
}
