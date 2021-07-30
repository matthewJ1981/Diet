#pragma once
#include "NIStructs.h"
#include <memory>
/**
 *	Simple class to store the nutritional information of a food item
 */

namespace Diet
{
	namespace Internal
	{
		class NutritionInfoImplementation;
	}

	class NutritionInfo
	{
	public:
		NutritionInfo();
		NutritionInfo(uint calories, Fats fat, uint cholesterol, uint sodium, Carbohydrate carbs, uint protein);
		~NutritionInfo();
		NutritionInfo(const NutritionInfo& rhs);
		NutritionInfo& operator=(const NutritionInfo& rhs);
		void Assign(const NutritionInfo& rhs);
		/**
		 * Generate new NutirifionInfo object based upon user entry
		 */
		static NutritionInfo NewInfo();

		uint Calories() const;
		Fats Fat() const;
		uint Cholesterol() const;
		uint Sodium() const;
		Carbohydrate Carbohydrates() const;
		uint Protein() const;

		NutritionInfo& operator +=(const NutritionInfo& rhs);
		const NutritionInfo operator + (const NutritionInfo& rhs);

		NutritionInfo& operator *= (const float rhs);
		const NutritionInfo operator * (const float rhs);

		bool operator == (const NutritionInfo& rhs) const;

		friend std::ostream& operator << (std::ostream& out, const NutritionInfo& ni);
		friend std::istream& operator >> (std::istream& in,  NutritionInfo& ni);

	private:
		std::unique_ptr<Internal::NutritionInfoImplementation> p;
	};
}

