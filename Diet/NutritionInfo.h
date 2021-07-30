#pragma once
#include <memory>
#include <fstream>
/**
 *	Simple class to store the nutritional information of a food item
 */

namespace Diet
{
	namespace Internal
	{
		class NutritionInfoImplementation;
	}

	struct Sugar
	{
		float total = 0.0f;
		float added = 0.0f;
		bool operator == (const Sugar& rhs) const;
	};

	struct Fats
	{
		float total = 0.0f;
		float saturated = 0.0f;
		float trans = 0.0f;
		float poly = 0.0f;
		float mono = 0.0f;
		bool operator == (const Fats& rhs) const;
	};

	struct Carbohydrate
	{
		float total = 0.0f;
		float dietryFiber = 0.0f;
		Sugar sugars;
		float erythitol = 0.0f;
		bool operator == (const Carbohydrate& rhs) const;

	};

	class NutritionInfo
	{
	public:
		NutritionInfo();
		NutritionInfo(float calories, Fats fat, float cholesterol, float sodium, Carbohydrate carbs, float protein);
		~NutritionInfo();
		NutritionInfo(const NutritionInfo& rhs);
		NutritionInfo& operator=(const NutritionInfo& rhs);
		//void Assign(const NutritionInfo& rhs);
		/**
		 * Generate new NutirifionInfo object based upon user entry
		 */
		static NutritionInfo NewInfo();

		float Calories() const;
		Fats Fat() const;
		float Cholesterol() const;
		float Sodium() const;
		Carbohydrate Carbohydrates() const;
		float Protein() const;

		NutritionInfo& operator +=(const NutritionInfo& rhs);
		const NutritionInfo operator + (const NutritionInfo& rhs);

		NutritionInfo& operator *= (const float rhs);
		const NutritionInfo operator * (const float rhs);

		bool operator == (const NutritionInfo& rhs) const;

		friend std::ofstream& operator << (std::ofstream& out, const NutritionInfo& ni);
		friend std::ostream& operator << (std::ostream& out, const NutritionInfo& ni);
		friend std::istream& operator >> (std::istream& in,  NutritionInfo& ni);

	private:
		std::unique_ptr<Internal::NutritionInfoImplementation> p;
	};
}

