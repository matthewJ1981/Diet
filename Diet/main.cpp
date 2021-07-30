#define TESTING 1

#ifndef TESTING

#include <iostream>
#include "DietApp.h"
#include <sstream>
#include "Util.h"


int main()
{
	Diet::DietApp::Go();
	return 0;
}

#elseif

#include <gtest/gtest.h>

#endif //TESTING