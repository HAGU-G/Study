#include <iostream>
#include "Vector2.h"
#include "Book.h"
#include "BankAccount.h"
#include "Student.h"
#include "Time.h"

int main()
{
	Vector2 vt1(1.f, 2.f);
	Vector2 vt2(2.f, 3.f);

	std::cout << "> " << (vt1 > vt2) << std::endl;
	std::cout << ">= " << (vt1 >= vt2) << std::endl;
	std::cout << "< " << (vt1 < vt2) << std::endl;
	std::cout << "<= " << (vt1 <= vt2) << std::endl;

	vt1 += vt2;
	std::cout << "+= " << vt1 << std::endl;
	vt1 -= vt2;
	std::cout << "-= " << vt1 << std::endl;
	vt1 += vt2;
	vt1 *= 2;
	std::cout << "*= " << vt1 << std::endl;
	vt1 /= 2;
	std::cout << "/= " << vt1 << std::endl;

	// Book 테스트
	Book myBook("1984", "George Orwell", 328);
	myBook.displayInfo(); // 출력: Book: 1984, Author: George Orwell, Pages: 328

	// BankAccount 테스트
	BankAccount myAccount("123456789", 1000.0);
	myAccount.deposit(500); // 500 입금
	myAccount.withdraw(200); // 200 출금
	myAccount.displayAccount(); // 출력: Account Number: 123456789, Balance: 1300.0

	// Student 테스트
	Student student("Kim", "20240001", "Computer Science");
	student.displayInfo(); // 출력: Student: Kim, ID: 20240001, Major: Computer Science

	// Time 테스트
	Time currentTime(14, 30, 45);
	currentTime.displayTime24(); // 출력: Time: 14:30:45 (24-hour format)
	currentTime.displayTime12(); // 출력: Time: 2:30:45 PM (12-hour format)

	return 0;
}