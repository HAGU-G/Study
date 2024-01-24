//### �������� 2: ���� ���� Ŭ���� �����
//
//- Ŭ���� �̸� : BankAccount
//- ��� ���� : accountNumber(���� ��ȣ, ���ڿ�), balance(�ܾ�, �Ǽ���)
//- ������ : ���� ��ȣ�� �ʱ� �ܾ��� ������ �� �ִ� ������ �ۼ�
//- ��� �Լ� :
//-�Ա��� ó���ϴ� deposit(double amount) �Լ�
//- ����� ó���ϴ� withdraw(double amount) �Լ�
//- ���� ������ ����ϴ� displayAccount() �Լ�

#pragma once
#include <string>
class BankAccount
{
private:
	std::string accountNumber;
	double balance;
public:
	BankAccount(std::string accountNumber, double balance = 0.0);
	void deposit(double amount);
	void withdraw(double amount);
	void displayAccount();

};