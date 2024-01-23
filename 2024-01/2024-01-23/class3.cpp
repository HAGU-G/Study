#include <iostream>
#include <string>


class Complex
{
private:
	double real;
	double image;

public:
	Complex(double r = 0.0, double i = 0.0) : real(r), image(i)
	{
		std::cout << "Complex() : " << real << " " << image << std::endl;
	}
	~Complex()
	{
		std::cout << "~Complex() : " << real << " " << image << std::endl;
	}

	void Print()
	{
		std::cout << real << "+" << image << "i" << std::endl;
	}

	double GetReal()
	{
		return real;
	}
	void SetReal(double r)
	{
		real = r;
	}

	double GetImage()
	{
		return image;
	}
	void SetImage(double i)
	{
		image = i;
	}

	void Set(double r, double i)
	{
		real = r;
		image = i;
	}

};

int main()
{
	Complex c1;
	Complex c2(1.0);
	Complex c3(3.0, 4.0);

	//Complex c4 = 1.5; 컴파일에러가 나지 않는다.
	//int a = 0;
	//int a(0);		→ c++에서 둘이 같다.
	


	c1.Print();
	c2.Print();
	c3.Print();

	return 0;
}