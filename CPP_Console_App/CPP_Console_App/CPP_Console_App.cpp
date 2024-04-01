#include <iostream>
#include <sstream>
#include <cmath>
#include <random>
#include <list>
#include "Log.h"
#include "DiceHolder.h"
#include "SubClass.h"

static void ConvertBetweenFahrenheitAndCelsius();
static void CalculateAreaOfCircle();
static void SimulateDiceRoll(int numberOfThrows);
static void Multiplication(const std::list<std::pair<int, int>>& listOfNumbers);
static void CreateAndThrowDices(int numberOfDicesToCreate);
static void LogInheritors();

int main()
{
	InitialLog();

	//ConvertBetweenFahrenheitAndCelsius();
	//CalculateAreaOfCircle();
	//SimulateDiceRoll(10);
	/*Multiplication({
		{10, 10},
		{20, 20},
		{5, 9},
		});*/
	//CreateAndThrowDices(5);
	LogInheritors();
	
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n').get();
}

static void ConvertBetweenFahrenheitAndCelsius()
{
	int currentTemperature = 0;
	int temporaryFahrenheitToCelsius = 0;
	bool convertFahrenheitToCelsius = true;
	auto fahrenheitToCelsius = [](int fahrenheitTemperature) ->
		double
		{
			return (5.0 / 9.0) * (fahrenheitTemperature - 32);
		};
	auto celsiusToFahrenheit = [](int celsiusTemperature) ->
		double
		{
			return ((9.0 / 5.0) * celsiusTemperature) + 32;
		};

	std::cout << "Convert F to C? Enter 0 to agree, any other integer number to disagree: "
		, std::cin >> temporaryFahrenheitToCelsius, std::cout << "\n";

	convertFahrenheitToCelsius = ((temporaryFahrenheitToCelsius == 0) ? true : false);

	std::ostringstream buffer;
	buffer << "Converting " << (convertFahrenheitToCelsius
		? "Fahrneheit to Celsius..."
		: "Celsius to Fahrenheit...");

	std::cout << buffer.str() << std::endl
		<< "Please enter the temperature: ",
		std::cin >> currentTemperature;
	buffer.str("");

	buffer << "The temperature in " << (convertFahrenheitToCelsius
		? "Celsius "
		: "Fahrenheit ")
		<< "is: " <<
		(convertFahrenheitToCelsius
			? fahrenheitToCelsius(currentTemperature)
			: celsiusToFahrenheit(currentTemperature));

	std::cout << buffer.str() << std::endl;
}

static void CalculateAreaOfCircle()
{
	const float pi = 3.14159F; // Always remember 'F' at the end of a float.
	double radiusOfCircle = 0;

	std::cout << "Please enter the radius of the circle: ",
		std::cin >> radiusOfCircle;

	std::cout << "The area of the circle is: " << (pi * std::pow(radiusOfCircle, 2));
}

static void SimulateDiceRoll(int numberOfThrows)
{
	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<> dis(1, 6);

	for (int i = 1; i <= numberOfThrows; i++)
	{
		int randomNumber = dis(gen);

		std::cout << "Throw nr " << i << " lands: " << randomNumber << std::endl;
	}
}

static void Multiplication(const std::list<std::pair<int, int>>& listOfNumbers)
{
	std::ostringstream buffer;

	auto multiplyPairOfNumbers = [](int a, int b) -> int { return a * b; };

	for (auto it = listOfNumbers.begin(); it != listOfNumbers.end(); it++)
	{
		std::pair<int, int> pairOfNumbers = *it;

		SaveLogToBuffer(std::to_string(multiplyPairOfNumbers(pairOfNumbers.first, pairOfNumbers.second)), buffer);
	}
	LogBuffer(buffer);
}

static void CreateAndThrowDices(int numberOfDicesToCreate)
{
	std::ostringstream buffer;
	std::list<DiceHolder> listOfDices;
	std::vector<int> numberOfSidesOnEachDice;	
	numberOfSidesOnEachDice.reserve(numberOfDicesToCreate);

	std::cout << "Now, please enter the number of sides of each dice." << std::endl;

	for (int i = 1; i <= numberOfDicesToCreate; i++)
	{
		int numberOfSides;
		std::cout << "Dice " + std::to_string(i) << ": ", std::cin >> numberOfSides;
		numberOfSidesOnEachDice.push_back(numberOfSides);
	}	

	for (int i = 1; i <= numberOfDicesToCreate; i++)
	{
		listOfDices.push_back(DiceHolder(numberOfSidesOnEachDice[i - 1]));
	}
	
	SaveLogToBuffer(DiceHolder::LogNumberOfDices(), buffer);
	SaveLogToBuffer("The result of each dice throw is as follows...", buffer);
	for (auto it = listOfDices.begin(); it != listOfDices.end(); it++)
	{
		DiceHolder dice = *it;

		SaveLogToBuffer(std::to_string(dice.ThrowDice()), buffer);
	}
	LogBuffer(buffer);
}

static void LogInheritors()
{
	std::ostringstream buffer;
	SubClass subClass("Rolf");
	SubClass subClass2("Torsten");

	SaveLogToBuffer("The name of the inheritors is as follows... ", buffer);
	SaveLogToBuffer(subClass.GetName(), buffer);
	SaveLogToBuffer(subClass2.GetName(), buffer);
	LogBuffer(buffer);
}