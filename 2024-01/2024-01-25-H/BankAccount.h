#pragma once
#include <string>
class BankAccount
{
private:
	char* accountNumber;
	double balance;
public:
	BankAccount(const char* accountNumber, double balance = 0.0);
	~BankAccount();
	void deposit(double amount);
	void withdraw(double amount);
	void displayAccount() const;

};