#include <iostream>
#include "NutritionInfo.h"
#include "NutritionInfoImplementation.h"
#include "Util.h"
#include <fstream>

namespace Diet
{
	NutritionInfo::NutritionInfo()
		:
		/*calories(0),
		fat(Diet::Fats()),
		cholesterol(0),
		sodium(0),
		carbohydrates(Diet::Carbohydrate()),
		protein(0)*/
		p(std::make_unique<Internal::NutritionInfoImplementation>())
	{}

	NutritionInfo::NutritionInfo(uint calories, Fats fat, uint cholesterol, uint sodium, Carbohydrate carbs, uint protein)
		:
		//calories(calories),
		//fat(fat),
		//cholesterol(cholesterol),
		//sodium(sodium),
		//carbohydrates(carbs),
		//protein(protein)
		p(std::make_unique<Internal::NutritionInfoImplementation>(calories, fat, cholesterol, sodium, carbs, protein))
	{}

	NutritionInfo::~NutritionInfo()
	{
		//delete p;
		//p = nullptr;
	}

	NutritionInfo::NutritionInfo(const NutritionInfo& rhs)
		:
		p(std::make_unique<Internal::NutritionInfoImplementation>())
	{
		Assign(rhs);
	}

	NutritionInfo& NutritionInfo::operator=(const NutritionInfo& rhs)
	{
		Assign(rhs);
		return *this;
	}

	void NutritionInfo::Assign(const NutritionInfo& rhs)
	{
		p->calories = rhs.p->calories;
		p->fat.total = rhs.p->fat.total;
		p->fat.saturated = rhs.p->fat.saturated;
		p->fat.trans = rhs.p->fat.trans;
		p->fat.poly = rhs.p->fat.poly;
		p->fat.mono = rhs.p->fat.mono;
		p->cholesterol = rhs.p->cholesterol;
		p->sodium = rhs.p->sodium;
		p->carbohydrates.total = rhs.p->carbohydrates.total;
		p->carbohydrates.dietryFiber = rhs.p->carbohydrates.dietryFiber;
		p->carbohydrates.sugars.total = rhs.p->carbohydrates.sugars.total;
		p->carbohydrates.sugars.added = rhs.p->carbohydrates.sugars.added;
		p->carbohydrates.erythitol = rhs.p->carbohydrates.erythitol;
		p->protein = rhs.p->protein;
	}

	NutritionInfo NutritionInfo::NewInfo()
	{
		NutritionInfo ni;
		ni.p->NewInfo();
		return ni;
	}

	uint NutritionInfo::Calories() const
	{
		return p->calories;
	}

	Fats NutritionInfo::Fat() const
	{
		return p->fat;
	}

	uint NutritionInfo::Cholesterol() const
	{
		return p->cholesterol;
	}

	uint NutritionInfo::Sodium() const
	{
		return p->sodium;
	}

	Carbohydrate NutritionInfo::Carbohydrates() const
	{
		return p->carbohydrates;
	}

	uint NutritionInfo::Protein() const
	{
		return p->protein;
	}

	NutritionInfo& NutritionInfo::operator += (const NutritionInfo& rhs)
	{
		*p += *rhs.p;
		return *this;
	}

	const NutritionInfo NutritionInfo::operator + (const NutritionInfo& rhs)
	{
		NutritionInfo result = *this;
		result += rhs;
		return result;
	}

	NutritionInfo& NutritionInfo::operator *=(const float rhs)
	{
		*p *= rhs;
		return *this;
	}

	const NutritionInfo NutritionInfo::operator * (const float rhs)
	{
		NutritionInfo result = *this;
		result *= rhs;
		return result;
	}

	bool NutritionInfo::operator == (const NutritionInfo& rhs) const
	{
		return *p == *rhs.p;
	}

	std::ostream& operator << (std::ostream& out, const NutritionInfo& ni)
	{
		//Produce different output if writing to a file
		if (typeid(out) == typeid(std::ofstream))
		{
			out << ni.p->calories << " " << ni.p->fat.total << " " << ni.p->fat.saturated << " "
				<< ni.p->fat.trans << " " << ni.p->fat.poly << " " << ni.p->fat.mono << " "
				<< ni.p->cholesterol << " " << ni.p->sodium << " " << ni.p->carbohydrates.total << " "
				<< ni.p->carbohydrates.dietryFiber << " " << ni.p->carbohydrates.sugars.total << " "
				<< ni.p->carbohydrates.sugars.added << " " << ni.p->carbohydrates.erythitol << " "
				<< ni.p->protein;

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
		in >> ni.p->calories >> ni.p->fat.total >> ni.p->fat.saturated 
			>> ni.p->fat.trans >> ni.p->fat.poly >> ni.p->fat.mono 
			>> ni.p->cholesterol >> ni.p->sodium >> ni.p->carbohydrates.total 
			>> ni.p->carbohydrates.dietryFiber >> ni.p->carbohydrates.sugars.total 
			>> ni.p->carbohydrates.sugars.added >> ni.p->carbohydrates.erythitol 
			>> ni.p->protein;

		return in;
	}
}

