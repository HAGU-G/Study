#pragma once
#include <string>
class BankAccount
{
private:
	char* accountNumber;
	double balance;
public:
	BankAccount(const char* accountNumber, double balance = 0.0);

	BankAccount(const BankAccount& ref);
	BankAccount(BankAccount&& ref) noexcept;

	~BankAccount();
	void deposit(double amount);
	void withdraw(double amount);
	void displayAccount() const;

	BankAccount& operator=(const BankAccount& ref);
	BankAccount& operator=(BankAccount&& ref) noexcept;

};