#include <iostream>
using namespace std;

int test = 0;

class A {
public:
	virtual int f() { return x; }
	virtual ~A() {}
private:
	int x = 10;
};

class B : public A {
public:
	int f() { return x; }
	virtual int g() { return A::f(); }
private:
	int x = 20;
};

class C : public B {
public:
	int f() { return x; }
	int g() { return B::f(); }
	virtual int h() { return B::g(); }
private:
	int x = 30;
};

int main() {
	A* a = new B;
	A* b = new C;
	B* c = new C;
	C* d = new C;
											//예측
	cout << a->f() << endl;					//10
	cout << static_cast<C*>(a)->g() << endl;//static_cast<B*>→10 : A에는 g()가 없다.
	cout << b->f() << endl;					//10
	cout << static_cast<B*>(b)->g() << endl;//static_cast<B*>→10 or <C*>→20 : A에는 g()가 없다.
	cout << c->f() << endl;					//20
	cout << c->g() << endl;					//10
	cout << d->g() << endl;					//20
	cout << d->h() << endl;					//10

	delete a;
	delete b;
	delete c;
	delete d;
	
	//결과
	//20
	//10
	//30
	//20
	//30
	//20
	//20
	//10

	//틀린 이유 : 가상함수는 자신의 내용을 모두 실행하고 오버라이딩 된 함수를 차례로 호출한다고 생각했다.
	//			→실제 객체의 클래스의 함수를 호출한다.
}