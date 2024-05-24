#pragma once

#include "BankAccount.h"
#include <vector>

extern int CURRENT_ACCOUNT_NUMBER;
extern int const INITIAL_BALANCE;

static BankAccount* findBankAccount(std::vector<BankAccount*>& bankAccounts, int accountNumber);

static BankAccount* getBankAccountConsoleInput(std::vector<BankAccount*>& bankAccounts);

int bankInteraction();