#include <iostream>
#include "NutritionInfo.h"
#include "Util.h"
#include <fstream>

namespace Diet
{
	using Util::Eq;


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
		return Eq(total, rhs.total) && Eq(dietryFiber, rhs.dietryFiber) && sugars == rhs.sugars && Eq(erythitol, rhs.erythitol);
	}

	namespace Internal
	{
		class NutritionInfoImplementation
		{
		public:
			NutritionInfoImplementation()
				:
				calories(0.0f),
				fat({ 0.0f, 0.0f }),
				cholesterol(0.0f),
				sodium(0.0f),
				carbohydrates({ 0.0f, 0.0f, { 0.0f, 0.0f }, 0.0f }),
				protein(0.0f)
			{}

			NutritionInfoImplementation(float calories, Fats fat, float cholesterol, float sodium, Carbohydrate carbs, float protein)
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
				return Eq(calories, rhs.calories) &&
					fat == rhs.fat &&
					Eq(cholesterol, rhs.cholesterol) &&
					Eq(sodium, rhs.sodium) &&
					carbohydrates == rhs.carbohydrates &&
					Eq(protein, rhs.protein);
			}

			float calories;
			Fats fat;
			float cholesterol;
			float sodium;
			Carbohydrate carbohydrates;
			float protein;
		};
	}

	NutritionInfo::NutritionInfo()
		:
		p(std::make_unique<Internal::NutritionInfoImplementation>())
	{}

	NutritionInfo::NutritionInfo(float calories, Fats fat, float cholesterol, float sodium, Carbohydrate carbs, float protein)
		:
		p(std::make_unique<Internal::NutritionInfoImplementation>(calories, fat, cholesterol, sodium, carbs, protein))
	{}

	NutritionInfo::~NutritionInfo() = default;

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

	float NutritionInfo::Calories() const
	{
		return p->calories;
	}

	Fats NutritionInfo::Fat() const
	{
		return p->fat;
	}

	float NutritionInfo::Cholesterol() const
	{
		return p->cholesterol;
	}

	float NutritionInfo::Sodium() const
	{
		return p->sodium;
	}

	Carbohydrate NutritionInfo::Carbohydrates() const
	{
		return p->carbohydrates;
	}

	float NutritionInfo::Protein() const
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

