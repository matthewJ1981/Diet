#pragma once
#include <gtest/gtest.h>
#include "..\FoodItem.h"
#include <fstream>
#include <iostream>

class FoodItemTest : public ::testing::Test
{
protected:
	void SetUp() override
	{	
		RunNew(fi);
	}

	void RunNew(Diet::FoodItem& f, std::string inFile = "FoodItemNewDriver.txt", std::string outFile = "FoodItemTestOut.txt")
	{
		std::ofstream out(outFile);
		std::ifstream in(inFile);
		if (!out || !in)
			abort();

		f.New(out, in);
	}

	std::string SerializeTest(Diet::FoodItem f)
	{
		std::ofstream out("serializeTest.txt");
		f.Serialize(out);
		out.close();
		std::ifstream in("serializeTest.txt");
		if (!in)
			abort();
		std::string input;
		std::getline(in, input);
		return input;
	}

	Diet::FoodItem DeserializeTest(std::string in)
	{
		std::ifstream inFile(in);
		if (!inFile)
			abort();
		Diet::FoodItem f;
		f.Deserialize(inFile);
		return f;
	}

	Diet::FoodItem fiDef;
	Diet::FoodItem fi{ "Food" };
};

