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
	else if (balance < amount)
	{
		std::cout << "�ܾ��� �����մϴ�." << std::endl;
		return;
	}
	balance -= amount;
	std::cout << amount << " ���" << std::endl;
}

void BankAccount::displayAccount() const
{
	std::cout << std::fixed;
	std::cout.precision(1);
	std::cout << "Account Number: " << accountNumber << std::endl << "Balance: " << balance << std::endl;
}
