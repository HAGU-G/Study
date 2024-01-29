#include "BankAccount.h"
#include <iostream>

BankAccount::BankAccount(const char* accountNumber, double balance) : accountNumber(nullptr), balance(balance)
{

	if (accountNumber)
	{
		this->accountNumber = new char[strlen(accountNumber) + 1];
		strcpy_s(this->accountNumber, strlen(accountNumber) + 1, accountNumber);
	}
}

BankAccount::BankAccount(const BankAccount& ref)
	:accountNumber(nullptr), balance(ref.balance)
{
	if (ref.accountNumber)
	{
		accountNumber = new char[strlen(ref.accountNumber) + 1];
		strcpy_s(accountNumber, strlen(ref.accountNumber) + 1, ref.accountNumber);
	}
}

BankAccount::BankAccount(BankAccount&& ref) noexcept
	:accountNumber(ref.accountNumber), balance(ref.balance)
{
	ref.accountNumber = nullptr;
}

BankAccount::~BankAccount()
{
	if(accountNumber)
		delete[] accountNumber; //nullptr인 경우가 있을 수 있으므로 널체크를 해주는 것이 좋다.
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

BankAccount& BankAccount::operator=(const BankAccount& ref)
{

	if (ref.accountNumber && accountNumber != ref.accountNumber)
	{
		accountNumber = new char[strlen(ref.accountNumber) + 1];
		strcpy_s(accountNumber, strlen(ref.accountNumber) + 1, ref.accountNumber);
		balance = ref.balance;
		return *this;
	}
}

BankAccount& BankAccount::operator=(BankAccount&& ref) noexcept
{
	accountNumber = ref.accountNumber;
	balance = ref.balance;

	ref.accountNumber = nullptr;
	ref.balance = 0;

	return *this;
}
