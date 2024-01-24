//### 연습문제 2: 은행 계좌 클래스 만들기
//
//- 클래스 이름 : BankAccount
//- 멤버 변수 : accountNumber(계좌 번호, 문자열), balance(잔액, 실수형)
//- 생성자 : 계좌 번호와 초기 잔액을 설정할 수 있는 생성자 작성
//- 멤버 함수 :
//-입금을 처리하는 deposit(double amount) 함수
//- 출금을 처리하는 withdraw(double amount) 함수
//- 계좌 정보를 출력하는 displayAccount() 함수

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