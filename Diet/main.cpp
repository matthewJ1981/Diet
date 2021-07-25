#include <iostream>
#include "DietApp.h"
#include <sstream>
#include "Util.h"

int main()
{
	Diet::DietApp d;
	bool running = true;
	while (running)
	{
		d.CheckTime();
		std::cout << d;
		int selection = Util::Input("Consume food (1)\nAdjust Calorie Goal(2)\nQuit(3)\n", 1, 3);

		switch (selection)
		{
		case 1:
			d.ConsumeFood();
			break;
		case 2:
			d.SetCalorieMax(Util::Input("Enter new calorie goal: ", 1, 10000));
			break;
		case 3:
			running = false;
			break;
		default:
			throw std::runtime_error("Invalid input");
		}
	}

	return 0;
}