#pragma once
#include <string>

extern const std::string BAD_DEPOSIT_AMOUNT_STRING;
extern const std::string BAD_WITHDRAW_AMOUNT_STRING;

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