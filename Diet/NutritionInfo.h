#pragma once

/**
 *	Simple class to store the nutritional information of a food item
 */
namespace Diet
{
	typedef unsigned int uint;

	struct Sugar
	{
		uint total = 0;
		uint added = 0;
	};

	struct Fats
	{
		uint total = 0;
		uint saturated = 0;
		uint trans = 0;
		uint poly = 0;
		uint mono = 0;
	};

	struct Carbohydrate
	{
		uint total = 0;
		uint dietryFiber = 0;
		Sugar sugars;
		uint erythitol = 0;
	};
	
	class NutritionInfo
	{
	public:
		NutritionInfo();
		NutritionInfo(uint calories, Fats fat, uint cholesterol, uint sodium, Carbohydrate carbs, uint protein);

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
		friend std::ostream& operator << (std::ostream& out, const NutritionInfo& ni);
		friend std::istream& operator >> (std::istream& in,  NutritionInfo& ni);

	private:
		uint calories;
		Fats fat;
		uint cholesterol;
		uint sodium;
		Carbohydrate carbohydrates;
		uint protein;
	
	};
}

