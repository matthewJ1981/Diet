#include <iostream>
#include "Consumed.h"

static float calorieMax = 2000.0f;
static int totFatMax = 0;
static int totSatFatMax = 0;
static int totCholMax = 0;
static int totSodMax = 0;
static int totCarbMax = 0;
static int totFibreMax = 0;
static int totProteinMax = 0;

void calcMaximums(float calories)
{
	totFatMax = calories / calorieMax * 75.0f;
	totSatFatMax = calories / calorieMax * 20.0f;
	totCholMax = calories / calorieMax * 300.0f;
	totSodMax = calories / calorieMax * 240.0f;
	totCarbMax = calories / calorieMax * 250.0f;
	totFibreMax = calories / calorieMax * 28.0f;
	totProteinMax = calories / calorieMax * 50.0f;
}

void calcMaximums()
{
	calcMaximums(2000.0f);
}

void print()
{
	std::cout << calorieMax << "\n";
	std::cout << totFatMax << "\n";
	std::cout << totSatFatMax << "\n";
	std::cout << totCholMax << "\n";
	std::cout << totSodMax << "\n";
	std::cout << totCarbMax << "\n";
	std::cout << totFibreMax << "\n";
	std::cout << totProteinMax << "\n";
}

int main()
{
	Diet::Consumed c;
	Diet::FoodItem fi("Bacon", { 80, {2, 0}, 15, 320, {0, 0, 0}, 5 });
	c.Add(fi);
	c.Add({ "Bacon", { 80, {2, 0}, 15, 320, {0, 0, 0}, 5 } });
	std::cout << c.Total() << "\n\n";
	calcMaximums();
	print();
	return 0;
}