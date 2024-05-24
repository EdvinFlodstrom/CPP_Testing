#include "BankInteraction.h"
#include "BankAccount.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <conio.h>

int CURRENT_ACCOUNT_NUMBER = 1;
int const INITIAL_BALANCE = 500;

static int convertStringToInt(std::string numberAsString) {
	try {
		return std::stoi(numberAsString);
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Invalid input. Please enter a valid integer.\n";
		return 0;
	}
}

static BankAccount* findBankAccount(std::vector<BankAccount*>& bankAccounts, int accountNumber) {
	for (auto account : bankAccounts) {
		if (account->getAccountNumber() == accountNumber)
			return account;
	}

	return nullptr;
}

static BankAccount* getBankAccountConsoleInput(std::vector<BankAccount*>& bankAccounts) {
	std::cout << "Enter account number: ";

	int accountNumber = 0;
	std::string accountNumberString;

	std::cin >> accountNumberString;
	accountNumber = convertStringToInt(accountNumberString);
	
	if (accountNumber <= 0) {
		return nullptr;
	}

	BankAccount* bankAccount = findBankAccount(bankAccounts, accountNumber);

	if (bankAccount == nullptr) {
		std::cerr << "Bank account not found. Please try again.\n";
	}
	return bankAccount;
}

static void depositOrWithdrawMoney(BankAccount& bankAccount, bool deposit) {
	double amount;
	std::string stringAmount;

	std::cout << "Please input the amount of money you would like to " << (deposit ? "deposit" : "withdraw") << ": $";

	std::cin >> stringAmount;
	amount = convertStringToInt(stringAmount);

	if (amount > 0) {
		std::cout << (deposit ? bankAccount.deposit(amount) : bankAccount.withdraw(amount)) << "\n";
	}
}

int bankInteraction() {
	std::cout << "Welcome to the bank!\n";

	std::vector<BankAccount*> bankAccounts;
	std::ostringstream oss;
	oss << "\nYour options are as follow:\n"
		<< "1. Create a bank account\n"
		<< "2. Display account details\n"
		<< "3. Deposit money\n"
		<< "4. Withdraw money\n"
		<< "5. Exit\n \n";

	std::string stringChoice = "";
	int choice = 0;

	do {
		std::cout << oss.str();
		std::cin >> stringChoice;
		choice = std::stoi(stringChoice);

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (choice == 1) {
			std::cout << "Creating bank account...\n"
				<< "Enter your name: ";

			std::string name;
			std::getline(std::cin, name);

			bankAccounts.push_back(new BankAccount(CURRENT_ACCOUNT_NUMBER++, name, INITIAL_BALANCE));

			std::cout << "Successfully created bank account for " << name << " with $" << INITIAL_BALANCE << ".\n";
		}
		else if (choice == 2) {
			std::cout << "Displaying account details...\n";

			BankAccount* bankAccount = getBankAccountConsoleInput(bankAccounts);
			
			if (bankAccount != nullptr) {
				std::cout << bankAccount->displayDetails() << "\n";
			}
		}
		else if (choice == 3) {
			std::cout << "Depositing money...\n";

			BankAccount* bankAccount = getBankAccountConsoleInput(bankAccounts);

			if (bankAccount != nullptr) {
				depositOrWithdrawMoney(*bankAccount, true);
			}
		}
		else if (choice == 4) {
			std::cout << "Withdrawing money...\n";

			BankAccount* bankAccount = getBankAccountConsoleInput(bankAccounts);

			if (bankAccount != nullptr) {
				depositOrWithdrawMoney(*bankAccount, false);
			}

		}
		else {
			std::cout << "Exiting program...\n";
			choice = 5;
		}
	} while (choice != 5);

	for (auto bankAccount : bankAccounts) {
		delete bankAccount;
	}

	bankAccounts.clear();
	return 0;
}