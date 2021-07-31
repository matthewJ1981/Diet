#pragma once

#include <memory>

typedef unsigned int uint;

namespace Diet
{
	namespace Internal
	{
		class DietAppImplementation;
	}

	class DietApp
	{
	public:
		static void Go();
	private:
		DietApp() {}
		static std::unique_ptr<Internal::DietAppImplementation> impl;
	};
}
