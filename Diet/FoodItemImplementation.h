#pragma once

#include <string>
#include <iostream>
#include <fstream>

namespace Diet
{
	namespace Internal
	{
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
			float erythritol = 0.0f;
			bool operator == (const Carbohydrate& rhs) const;
		};

		struct FoodItemImplementation
		{
			struct NutritionInfo
			{
				float calories;
				Diet::Internal::Fats fat;
				float cholesterol;
				float sodium;
				Carbohydrate carbohydrates;
				float protein;

				NutritionInfo();

				NutritionInfo& operator += (const NutritionInfo& rhs);
				NutritionInfo& operator *=(const float rhs);
				bool operator== (const NutritionInfo& rhs);

				friend std::ostream& operator << (std::ostream& out, const NutritionInfo& ni);

				void Serialize(std::ofstream& out) const;
				void Deserialize(std::ifstream& in);
				void New();
			};

			FoodItemImplementation();
			FoodItemImplementation(std::string name);

			std::string name;
			NutritionInfo info;
		};
	}
}