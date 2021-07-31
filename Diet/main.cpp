//#define TESTING 1

#ifndef TESTING

#include <iostream>
#include "DietApp.h"
#include <sstream>
#include "Util.h"

#include "Fooditem.h"


int main()
{
	Diet::DietApp::Go();
	return 0;
}

#else

#include <gtest/gtest.h>

#endif //TESTING