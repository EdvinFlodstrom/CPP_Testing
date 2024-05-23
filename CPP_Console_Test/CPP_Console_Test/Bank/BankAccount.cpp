#include "BankAccount.h"

BankAccount::BankAccount(int accountNumber, std::string accountHolderName, double balance)
{
	BankAccount::accountNumber = accountNumber;
	BankAccount::accountHolderName = accountHolderName;
	BankAccount::balance = balance;
}

std::string BankAccount::displayDetails() const
{
	return "";
}

std::string BankAccount::deposit(double amount)
{
	return "";
}

std::string BankAccount::withdraw(double amount)
{
	return "";
}