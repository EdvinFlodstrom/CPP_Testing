#include "BankAccount.h"
#include <sstream>
#include <iomanip>

auto inputAmountIsValid = [](double inputAmount) -> bool { return inputAmount > 0; };

const std::string BAD_DEPOSIT_AMOUNT_STRING = "The requested amount may not be 0 or below.";
const std::string BAD_WITHDRAW_AMOUNT_STRING = "You may not withdraw more money than you have in your bank.";

BankAccount::BankAccount(int accountNumber, std::string accountHolderName, double balance) 
	: accountNumber(accountNumber), accountHolderName(accountHolderName), balance(balance) { }

int BankAccount::getAccountNumber() const {
	return accountNumber;
}

std::string BankAccount::displayDetails() const {
	double roundedBalance = std::round(balance * 10.0) / 10.0;

	std::ostringstream oss;
	oss << "Account details are as follow.\n"
		<< "Account number: " << accountNumber << "\n"
		<< "Account holder name: " << accountHolderName << "\n" // Round to one decimal.
		<< "Balance: $" << std::fixed << std::setprecision(1) << roundedBalance << "\n";

	return oss.str();
}

std::string BankAccount::deposit(double amount) {
	if (!inputAmountIsValid(amount))
		return BAD_DEPOSIT_AMOUNT_STRING;

	balance += amount;

	std::ostringstream oss;
	oss << "You successfully deposited " << amount << ". \n"
		<< "Your new balance is: $" << balance << "\n";

	return oss.str();
}

std::string BankAccount::withdraw(double amount) {
	if (!inputAmountIsValid(amount))
		return BAD_DEPOSIT_AMOUNT_STRING;

	if (balance < amount)
		return BAD_WITHDRAW_AMOUNT_STRING;

	balance -= amount;

	std::ostringstream oss;
	oss << "You successfully withdrew " << amount << ". \n"
		<< "Your new balance is: $" << balance << "\n";

	return oss.str();
}