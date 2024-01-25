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

	// Book �׽�Ʈ
	Book myBook("1984", "George Orwell", 328);
	myBook.displayInfo(); // ���: Book: 1984, Author: George Orwell, Pages: 328

	// BankAccount �׽�Ʈ
	BankAccount myAccount("123456789", 1000.0);
	myAccount.deposit(500); // 500 �Ա�
	myAccount.withdraw(200); // 200 ���
	myAccount.displayAccount(); // ���: Account Number: 123456789, Balance: 1300.0

	// Student �׽�Ʈ
	Student student("Kim", "20240001", "Computer Science");
	student.displayInfo(); // ���: Student: Kim, ID: 20240001, Major: Computer Science

	// Time �׽�Ʈ
	Time currentTime(14, 30, 45);
	currentTime.displayTime24(); // ���: Time: 14:30:45 (24-hour format)
	currentTime.displayTime12(); // ���: Time: 2:30:45 PM (12-hour format)

	return 0;
}