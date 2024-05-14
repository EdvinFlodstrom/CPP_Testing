#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

static void WriteToFile(std::fstream* filePtr);
static bool ReturnDecision();

static std::string trim(const std::string& str)
{
	size_t first = str.find_first_not_of(' ');

	if (std::string::npos == first)
	{
		return str;
	}

	size_t last = str.find_last_not_of(' ');
	return str.substr(first, (last - first + 1));
}

static std::fstream CreateFileWithGivenName(const std::string& fileName, bool clearFile)
{
	std::string path = "../Text_Files/";
	std::fstream file = std::fstream(path + fileName, clearFile ? std::ios::out : std::ios::app);

	return file;
}

static int FileInteraction()
{
	std::cout << "Would you like to replace the contents of the file? (y/n): ";

	char ch;
	do
	{
		ch = _getch();
	} while (ch != 'y' && ch != 'n');

	bool replace = ch == 'y';

	std::fstream file = CreateFileWithGivenName("test.txt", ch == 'y');

	if (!file.is_open())
	{
		std::cout << "File could not be opened" << std::endl;
		return 1;
	}

	WriteToFile(&file);

	file.close();
	return 0;
}

static std::string GetMessage()
{
	std::string message;
	std::string line;

	while (ReturnDecision())
	{
		std::cout << std::endl << "Enter a message: " << std::endl;
		std::getline(std::cin, line);
		message += trim(line) + "\n";
	}

	if (!message.empty())
	{
		message.pop_back();
	}

	return trim(message);
}

static bool ReturnDecision()
{
	std::cout << std::endl << "Would you like to add a line? (y/n): ";

	char ch;
	do
	{
		ch = _getch();
	} while (ch != 'y' && ch != 'n');

	return ch == 'y';
}

static void WriteToFile(std::fstream* file)
{
	*file << GetMessage() << std::endl;
}

int main()
{
	return FileInteraction();
}