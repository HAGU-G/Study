#include <iostream>
#include "..\2024-01-24\Vector2.h"
#include "..\2024-01-24\Vector2.cpp"

int main()
{
    Vector2* vectorPtr1 = new Vector2(10.f, 20.f);
    std::cout << *vectorPtr1 << std::endl;
    std::cout << (*vectorPtr1).GetX() << std::endl;
    std::cout << vectorPtr1->GetX() << std::endl;

    delete vectorPtr1;
    vectorPtr1 = nullptr;

    int input = 0;
    std::cin >> input;

    Vector2* vectorPtrArray1 = new Vector2[input];

    for (int i = 0; i < input; i++)
    {
        std::cout << vectorPtrArray1[i] << std::endl;
    }

    delete[] vectorPtrArray1;
    vectorPtrArray1 = nullptr;





    int* ptr = new int();
    
    int& ref = *ptr;
    
    std::cout << ptr[0] << std::endl;
    *ptr = 20;
    std::cout << ptr[0] << std::endl;
    
    delete ptr;
    ptr = nullptr; 


    int* arrPtr = new int[10] { 0 }; //�迭 ���� �Ҵ�. ����� ������ �� �� �ִ�.

    delete[] arrPtr; //�������� �Ҵ�� �迭 ����
    arrPtr = nullptr;

    return 0;
}