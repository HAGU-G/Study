#include "BankAccount.h"
#include <iostream>

BankAccount::BankAccount(const char* accountNumber, double balance) : accountNumber(nullptr), balance(balance)
{
	this->accountNumber = new char[strlen(accountNumber) + 1];
	strcpy_s(this->accountNumber, strlen(accountNumber) + 1, accountNumber);
}

BankAccount::~BankAccount()
{
	delete[] accountNumber;
	accountNumber = nullptr;
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
	else if (balance < amount)
	{
		std::cout << "잔액이 부족합니다." << std::endl;
		return;
	}
	balance -= amount;
	std::cout << amount << " 출금" << std::endl;
}

void BankAccount::displayAccount() const
{
	std::cout << std::fixed;
	std::cout.precision(1);
	std::cout << "Account Number: " << accountNumber << std::endl << "Balance: " << balance << std::endl;
}
