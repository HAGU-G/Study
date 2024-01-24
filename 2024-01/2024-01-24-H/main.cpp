#include <iostream>
#include "Book.h" //연습문제 1번
#include "BankAccount.h" //연습문제 2번
#include "Student.h" //연습문제 3번
#include "Time.h" //연습문제 4번

int main()
{
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