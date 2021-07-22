#pragma once

namespace Diet
{
	typedef unsigned int uint;

	struct Sugar
	{
		uint total() const;
		uint added;
	};

	struct Fats
	{
		uint total() const;
		uint saturated;
		uint trans;
		uint poly;
		uint mono;
	};

	struct Carbohydrate
	{
		uint total() const;
		uint dietryFiber;
		Sugar sugars;
		uint erythitol;
	};
	
	class NutritionInfo
	{
	public:
		NutritionInfo() = default;
		NutritionInfo(uint calories, Fats fat, uint cholesterol, uint sodium, Carbohydrate carbs, uint protein);
		uint Calories() const;
		Fats Fat() const;
		uint Cholesterol() const;
		uint Sodium() const;
		Carbohydrate Carbohydrates() const;
		uint Protein() const;

		NutritionInfo& operator +=(const NutritionInfo& rhs);
		friend std::ostream& operator << (std::ostream& out, const NutritionInfo& ni);
	private:

		uint calories;
		Fats fat;
		uint cholesterol;
		uint sodium;
		Carbohydrate carbohydrates;
		uint protein;
	};
}

