#include "BankAccount.h"
#include <iostream>

BankAccount::BankAccount(std::string accountNumber, double balance) : accountNumber(accountNumber), balance(balance)
{
}

void BankAccount::deposit(double amount)
{
	if (amount < 0.0)
	{
		std::cout << "���� �Ǽ��� �Է����ּ���." << std::endl;
		return;
	}
	balance += amount;
	std::cout << amount << " �Ա�" << std::endl;
}

void BankAccount::withdraw(double amount)
{
	if (amount < 0.0)
	{
		std::cout << "���� �Ǽ��� �Է����ּ���." << std::endl;
		return;
	}
	balance -= amount;
	std::cout << amount << " ���" << std::endl;
}

void BankAccount::displayAccount()
{
	std::cout << std::fixed;
	std::cout.precision(1);
	std::cout << "Account Number: " << accountNumber << std::endl << "Balance: " << balance << std::endl;
}
