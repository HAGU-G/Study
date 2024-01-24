#include <iostream>
#include "Book.h" //�������� 1��
#include "BankAccount.h" //�������� 2��
#include "Student.h" //�������� 3��
#include "Time.h" //�������� 4��

int main()
{
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