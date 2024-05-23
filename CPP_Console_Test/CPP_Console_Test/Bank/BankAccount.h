#pragma once
#include <string>

class BankAccount
{
private:
	int accountNumber;
	std::string accountHolderName;
	double balance;

public:
	BankAccount(int accountNumber, std::string accountHolderName, double balance);

	std::string displayDetails() const;
	std::string deposit(double amount);
	std::string withdraw(double amount);
};