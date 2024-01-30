//15�� Shape�� ���� ���� �Լ� GetDiag() �߰�
//28�� Circle�� �������̵� �� �Լ� GetDiag() �߰�
//46�� ~ 48�� Rectangle�� GetDiag()�� �������̵����� ����
//59�� ~ 61�� �밢���� ���� ��� �κ� ����
#include <iostream>
using namespace std;

const double PI = 3.141592653589793;

class Shape {
public:
	virtual ~Shape() {}
	virtual double GetArea() const = 0;
	virtual void Resize(double factor) = 0;
	virtual double GetDiag() const = 0;
};

class Circle : public Shape {
public:
	Circle(double r) : r(r) {}

	double GetArea() const {
		return r * r * PI;
	}
	void Resize(double factor) {
		r *= factor;
	}
	double GetDiag() const override { return 0.0; };

private:
	double r;
};

class Rectangle : public Shape {
public:
	Rectangle(double a, double b) : a(a), b(b) {}

	double GetArea() const {
		return a * b;
	}
	void Resize(double factor) {
		a *= factor;
		b *= factor;
	}

	double GetDiag() const override {
		return sqrt(a * a + b * b);
	}

private:
	double a, b;
};

int main() {
	Shape* shapes[] = { new Circle(1), new Rectangle(1,2) };

	for (Shape* s : shapes) {
		cout << "������ ���� : " << s->GetArea() << endl;
		if (s->GetDiag()) {
			cout << "�밢���� ���� : " << s->GetDiag() << endl;
		}
	}

	for (Shape* s : shapes) {
		delete s;
	}
}