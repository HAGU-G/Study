#include <iostream>

class MyClass
{
public:
	MyClass(int n) :x(n)
	{
		std::cout << "MyClass(int n): " << x << std::endl;
	}
	~MyClass()
	{
		std::cout << "~MyClass(int n): " << x << std::endl;
	}

	int GetX() const { return x; }
	void SetX(int n) { x = n; }

	int x;
private:

};

int main()
{
	std::shared_ptr<MyClass> a(new MyClass(5));
	std::cout << a->GetX() << std::endl;
	a->SetX(10);

	std::shared_ptr<MyClass> b = a;

	std::cout << b.use_count() << std::endl; //���� Ƚ��

	std::weak_ptr<MyClass> c =a;
	//c->x;�� �Ұ����ϴ�.
	std::cout << c.lock()->x;

	return 0;
}