#include <iostream>
#include "DietApp.h"
#include <sstream>
#include "Util.h"

int main()
{
	//Diet::Consumed c;
	//Diet::FoodItem fi("Bacon", { 80, {2, 0}, 15, 320, {0, 0, 0}, 5 });
	//c.Add(fi);
	//c.Add({ "Bacon", { 80, {2, 0}, 15, 320, {0, 0, 0}, 5 } });
	//std::cout << c.Total() << "\n\n";
	//
	Diet::DietApp d;
	d.SetCalorieMax(2000.0f);
	bool running = true;
	while (running)
	{
		std::cout << d << "\n\n";

		int selection = Util::Input("Consume food (1)\nQuit(2)\n", 1, 2);

		switch (selection)
		{
		case 1:
			d.ConsumeFood();
			break;
		case 2:
			running = false;
			break;
		default:
			throw std::runtime_error("Invalid input");
		}
	}

	return 0;
}