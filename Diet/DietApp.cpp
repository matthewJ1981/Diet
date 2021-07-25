#include "DietApp.h"
#include "Util.h"
#include "FoodItem.h"
#include <iomanip>

namespace Diet
{
	DietApp::DietApp()
	{
		
			Read(consumedFile);
			Read(favoritesFile);
			Read(configFile);

	}
	DietApp::~DietApp()
	{
			Write(consumedFile);
			Write(favoritesFile);
			Write(configFile);

	}

	void DietApp::SetCalorieMax(int calories)
	{
		calorieMax = calories;
	}

	int DietApp::GetCalorieMax()
	{
		return calorieMax;
	}

	void DietApp::ConsumeFood()
	{
		char option = '\0';
		if (favorites.size() == 0)
			option = 'N';
		else
			option = Util::Input("Is this something you have eaten before? (Y/N)");

		if (option == 'Y')
			GetFromFav();
		else
			GetNewFood();
	}

	void DietApp::GetNewFood()
	{
		std::string name;
		NutritionInfo ni;
		do
		{
			std::cout << "Name of Food? ";
			std::getline(std::cin, name);
			ni = NutritionInfo::NewInfo();

			std::cout << "\nYou entered...\n\n" << name << "\n" << ni << "\n";
		}
		while (Util::Input("Is this correct ? ") != 'Y');
		std::cout << "\n";

		total += ni;
		consumed.emplace_back(name, ni);
		favorites.emplace_back(name, ni);
	}

	void DietApp::GetFromFav()
	{
		std::cout << "Select from a list of known foods...\n\n";
		for (uint i = 0; i < favorites.size(); ++i)
			std::cout << favorites[i].Name() << " (" << i << ")\n";

		int selection = Util::Input("Select food item: ", 0, int(favorites.size() - 1));
		total += favorites[selection].NutInfo();
		consumed.emplace_back(favorites[selection].Name(), favorites[selection].NutInfo());
	}


	Diet::NutritionInfo DietApp::Total() const
	{
		return total;
	}

	std::ofstream DietApp::GetOfstream(std::string file)
	{
		std::ofstream outFile;
		try
		{
			outFile.open(file);
		}
		catch (std::exception e)
		{
			std::cerr << e.what();
			abort();
		}

		if (!outFile)
		{
			std::cerr << "Cannot open " + file + "\n";
			abort();
		}

		return outFile;
	}

	std::ifstream DietApp::GetIfstream(std::string file)
	{
		std::ifstream inFile;
		try
		{
			inFile.open(file);
		}
		catch (std::exception e)
		{
			std::cerr << e.what();
			abort();
		}

		if (!inFile)
		{
			std::cerr << "Cannot open " + file + "\n";
			abort();
		}

		return inFile;
	}

	void DietApp::Write(std::string file)
	{
		auto outFile = GetOfstream(file);

		if (file == consumedFile)
			for (const auto& f : consumed)
				outFile << f << "\n";
		else if (file == favoritesFile)
			for (const auto& f : favorites)
				outFile << f << "\n";
		else if (file == configFile)
			outFile << calorieMax << "\n";
		else
			throw std::runtime_error("Invalid filename");

		outFile.close();
	}

	void DietApp::Read(std::string file)
	{
		auto inFile = GetIfstream(file);

		if (file == consumedFile)
		{
			while (true)
			{
				FoodItem f;
				inFile >> f;
				if (inFile.eof())
					break;

				consumed.push_back(f);
				total += f.NutInfo();
			}
		}
		else if (file == favoritesFile)
		{
			while (true)
			{
				FoodItem f;
				inFile >> f;
				if (inFile.eof())
					break;
				favorites.push_back(f);
			}
		}
		else if (file == configFile)
		{
			inFile >> DietApp::calorieMax;
		}
		else
			throw std::runtime_error("Invalid filename");

		inFile.close();
	}

	std::ostream& operator << (std::ostream& out, const DietApp& rhs)
	{
		if (!rhs.consumed.empty())
		{
			out << "\nTotal consumed: \n\n";
			DietApp::FormatHelper(out, "Calories:", DietApp::Percentage(int(rhs.total.Calories()), rhs.calorieMax));
			DietApp::FormatHelper(out, "Total Fat:", DietApp::Percentage(rhs.total.Fat().total, rhs.totFatMax));
			DietApp::FormatHelper(out, "  Saturated Fat:", DietApp::Percentage(rhs.total.Fat().saturated, rhs.totSatFatMax));
			DietApp::FormatHelper(out, "  Trans Fat:", 0);
			DietApp::FormatHelper(out, "  Polyunsaturated:", 0);
			DietApp::FormatHelper(out, "  Monounsaturated:", 0);
			DietApp::FormatHelper(out, "Cholesterol:", DietApp::Percentage(rhs.total.Cholesterol(), rhs.totCholMax));
			DietApp::FormatHelper(out, "Sodium", DietApp::Percentage(rhs.total.Sodium(), rhs.totSodMax));
			DietApp::FormatHelper(out, "Total Carbohydrate:", DietApp::Percentage(rhs.total.Carbohydrates().total, rhs.totCarbMax));
			DietApp::FormatHelper(out, "  Dietary Fibre:", DietApp::Percentage(rhs.total.Carbohydrates().dietryFiber, rhs.totFibreMax));
			DietApp::FormatHelper(out, "  Total Sugars:", 0);
			DietApp::FormatHelper(out, "    Added Sugars:", 0);
			if (rhs.total.Carbohydrates().erythitol)
				DietApp::FormatHelper(out, "    Erythitol:", 0);
			DietApp::FormatHelper(out, "Protein:", DietApp::Percentage(rhs.total.Protein(), rhs.totProteinMax));
			out << "\n";
		}

		return out;
	}

	void DietApp::FormatHelper(std::ostream& out, std::string col1, int col2)
	{
		out << std::setw(25) << std::left << col1
			<< std::setw(10) << std::right << col2 << "%\n";

	}

	int DietApp::Percentage(int amount, int max)
	{
		return int(float(amount) / max * 100);
	}

	int DietApp::calorieMax = 2000;
	const std::string DietApp::consumedFile = "consumed.txt";
	const std::string DietApp::favoritesFile = "favorites.txt";
	const std::string DietApp::configFile = "config.txt";
	const std::string DietApp::totalsFile = "totals.txt";
}
