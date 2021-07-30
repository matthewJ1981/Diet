#pragma once

namespace Diet
{
	typedef unsigned int uint;


	struct Sugar
	{
		uint total = 0;
		uint added = 0;
		bool operator == (const Sugar& rhs) const
		{
			return total == rhs.total && added == rhs.added;
		}
	};

	class Fats
	{
	public:
		uint total = 0;
		uint saturated = 0;
		uint trans = 0;
		uint poly = 0;
		uint mono = 0;
		bool operator == (const Fats& rhs) const
		{
			return total == rhs.total && saturated == rhs.saturated &&
				trans == rhs.trans && poly == rhs.poly && mono == rhs.mono;
		}
	};

	struct Carbohydrate
	{
		uint total = 0;
		uint dietryFiber = 0;
		Sugar sugars;
		uint erythitol = 0;
		bool operator == (const Carbohydrate& rhs) const
		{
			return total == rhs.total && dietryFiber == rhs.dietryFiber && sugars == rhs.sugars && erythitol == rhs.erythitol;
		}
	};
}

