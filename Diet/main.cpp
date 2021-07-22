#include <iostream>
#include "Consumed.h"
#include "DietApp.h"

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
	std::cout << d;
	return 0;
}