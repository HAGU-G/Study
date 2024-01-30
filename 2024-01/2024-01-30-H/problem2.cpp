//15행 Shape에 순수 가상 함수 GetDiag() 추가
//28행 Circle에 오버라이딩 빈 함수 GetDiag() 추가
//46행 ~ 48행 Rectangle의 GetDiag()를 오버라이딩으로 수정
//59행 ~ 61행 대각선의 길이 출력 부분 수정
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
		cout << "도형의 넓이 : " << s->GetArea() << endl;
		if (s->GetDiag()) {
			cout << "대각선의 길이 : " << s->GetDiag() << endl;
		}
	}

	for (Shape* s : shapes) {
		delete s;
	}
}