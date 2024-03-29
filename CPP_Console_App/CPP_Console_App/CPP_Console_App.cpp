#include <iostream>
#include <sstream>
#include <cmath>
#include <random>

static void ConvertBetweenFahrenheitAndCelsius();
static void CalculateAreaOfCircle();
static void SimulateDiceRoll(int numberOfThrows);

int main()
{
	ConvertBetweenFahrenheitAndCelsius();
	//calculateAreaOfCircle();
	//simulateDiceRoll(10);
	
	std::cin.ignore(std::numeric_limits<std::streamsize>::max()).get();
	return 0;
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