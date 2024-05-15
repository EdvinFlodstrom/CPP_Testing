#include "Random.h"
#include <random>
#include <vector>

std::vector<int> GetRandomValues(int min, int max, int numberOfRandomValues)
{
	if (min > max)
	{
		return std::vector<int>();
	}

	std::vector<int> randomValues;

	std::random_device rd;
	std::mt19937 engine(rd());
	std::uniform_int_distribution<int> dist(min, max);

	for (int i = 0; i < numberOfRandomValues; i++)
	{
		randomValues.push_back(dist(engine));
	}

	return randomValues;
}

int GetRandomValue(int min, int max)
{
	if (min > max)
	{
		return 0;
	}

	static std::random_device rd;
	static std::mt19937 engine(rd());
	std::uniform_int_distribution<int> dist(min, max);

	return dist(engine);
}