#include "BankAccount.h"
#include <iostream>

BankAccount::BankAccount(std::string accountNumber, double balance) : accountNumber(accountNumber), balance(balance)
{
}

void BankAccount::deposit(double amount)
{
	if (amount < 0.0)
	{
		std::cout << "양의 실수를 입력해주세요." << std::endl;
		return;
	}
	balance += amount;
	std::cout << amount << " 입금" << std::endl;
}

void BankAccount::withdraw(double amount)
{
	if (amount < 0.0)
	{
		std::cout << "양의 실수를 입력해주세요." << std::endl;
		return;
	}
	balance -= amount;
	std::cout << amount << " 출금" << std::endl;
}

void BankAccount::displayAccount()
{
	std::cout << std::fixed;
	std::cout.precision(1);
	std::cout << "Account Number: " << accountNumber << std::endl << "Balance: " << balance << std::endl;
}
