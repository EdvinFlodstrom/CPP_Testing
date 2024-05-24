#pragma once
#include <string>

constexpr const char* BAD_DEPOSIT_AMOUNT_STRING = "The requested amount may not be 0 or below.\n";
constexpr const char* BAD_WITHDRAW_AMOUNT_STRING = "You may not withdraw more money than you have in your bank.\n";

class BankAccount
{
private:
	int accountNumber;
	std::string accountHolderName;
	double balance;

public:
	BankAccount(int accountNumber, std::string accountHolderName, double balance);

	int getAccountNumber() const;
	std::string displayDetails() const;
	std::string deposit(double amount);
	std::string withdraw(double amount);
};