#pragma once

#include <iostream>
#include <fstream>
#include <memory>

/**
* Simple class to store a food item.  Consists of a name and nutritional info
*/
namespace Diet
{
	namespace Internal
	{
		class FoodItemImplementation;
	}
	class FoodItem
	{
	public:
		FoodItem();
		FoodItem(std::string name);
		FoodItem(const FoodItem& rhs);
		FoodItem& operator= (const FoodItem& rhs);
		~FoodItem();
		std::string Name() const;

		float Calories() const;
		float TotalFat() const;
		float SaturatedFat() const;
		float TransFat() const;
		float PolyUnsaturatedFat() const;
		float MonoUnsaturatedFat() const;
		float Cholesterol() const;
		float Sodium() const;
		float TotalCarbohydrates() const;
		float DietryFiber() const;
		float TotalSuger() const;
		float AddedSugar() const;
		float Erythritol() const;
		float Protein() const;

		FoodItem& operator +=(const FoodItem& rhs);
		const FoodItem operator + (const FoodItem& rhs);

		FoodItem& operator *= (const float rhs);
		const FoodItem operator * (const float rhs);

		bool operator == (const FoodItem& rhs) const;

		void New(std::ostream& out = std::cout, std::istream& in = std::cin);
		void Serialize(std::ofstream& out) const;
		void Deserialize(std::ifstream& in);

		friend std::ostream& operator << (std::ostream& out, const FoodItem& fi);

	private:
		std::unique_ptr<Internal::FoodItemImplementation> impl;

	};
}
