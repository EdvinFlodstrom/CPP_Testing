#pragma once

#include "BankAccount.h"
#include <vector>

extern int CURRENT_ACCOUNT_NUMBER;
extern int const INITIAL_BALANCE;

static int convertStringToInt(std::string numberAsString);

static BankAccount* findBankAccount(std::vector<BankAccount*>& bankAccounts, int accountNumber);

static BankAccount* getBankAccountConsoleInput(std::vector<BankAccount*>& bankAccounts);

static void depositOrWithdrawMoney(BankAccount& bankAccount, bool deposit);

int bankInteraction();