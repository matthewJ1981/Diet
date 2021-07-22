#include <iostream>
#include "Consumed.h"
#include "DietApp.h"
#include <sstream>

int input(std::string msg)
{
	int selection = 0;

	do
	{
		std::cout << msg;
		std::string in = "";
		std::getline(std::cin, in);
		std::stringstream ss(in);
		ss >> selection;

	} while (selection < 1 || selection > 2);

	return selection;
}

int main()
{
	//Diet::Consumed c;
	//Diet::FoodItem fi("Bacon", { 80, {2, 0}, 15, 320, {0, 0, 0}, 5 });
	//c.Add(fi);
	//c.Add({ "Bacon", { 80, {2, 0}, 15, 320, {0, 0, 0}, 5 } });
	//std::cout << c.Total() << "\n\n";
	//
	Diet::DietApp d;
	d.setCalorieMax(2000.0f);
	bool running = true;
	while (running)
	{
		std::cout << d << "\n\n";

		int selection = input("Consume food (1)\nQuit(2)\n");

		switch (selection)
		{
		case 1:
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