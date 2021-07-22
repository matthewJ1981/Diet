#pragma once
#include <string>

namespace Util
{
	enum class Type{IntegerRange, YesNo};
	int Input(std::string msg, Type type);
};

