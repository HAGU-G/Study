#include <iostream>
#include <iomanip>

class Color
{
private:
	static int idCounter; //스태틱 멤버는 밖에서 초기화해줘야한다.
	int id;

	float r; //최소 0.0 ~ 최대 1.0 → 8비트 색을 사용하면 여기에 2^8을 곱함
	float g;
	float b;
	float a;

	unsigned int color32;
	//보통 사용자와의 상호작용에서는 색을 정수형으로 주고받는다.
	//color32는 투명도를 포함하여 각각 1Byte씩 사용하는 것이다. (8bit 4개 32)

public:

	static unsigned int GetColor32(const Color& color)
	{
		//RGBA값이 unsigned int형 4바이트를 모두 사용하여 표현되도록
		return((unsigned int)(color.r * 255) << 24) 
			| ((unsigned int)(color.g * 255) << 16) 
			| ((unsigned int)(color.b * 255) << 8) 
			| ((unsigned int)(color.a * 255));
	}

	static Color GetColor(unsigned int color32)
	{
		unsigned int r0 = (unsigned int)255 << 24;
		unsigned int g0 = (unsigned int)255 << 16;
		unsigned int b0 = (unsigned int)255 << 8;
		unsigned int a0 = (unsigned int)255 << 0;
		 
		return Color((color32 & r0) >> 24, (color32 & g0) >> 16, (color32 & b0) >> 8, color32 & a0);
	}

	Color() : r(0.0f), g(0.0f), b(0.0f), a(1.0f), id(idCounter++) //0.0뒤에 f를 붙이지 않으면 기본적으로 double형
	{

	}
	Color(float r, float g, float b, float a = 1.0f) : r(r), g(g), b(b), a(a), id(idCounter++)
	{

	}
	~Color()
	{

	}

	float GetR() //멤버는 인스턴스와 스태틱으로 나눌 수 있다. 기본적으로 인스턴스
	{
		return r;
	}
	float GetG()
	{
		return g;
	}
	float GetB()
	{
		return b;
	}

	void Print()
	{
		std::cout << r << " " << g << " " << b << " " << a << std::endl;
	}

	static Color MixColors(const Color& a, const Color& b) //call-by-value를 쓰면 a와 b라는 새로운 인스턴스를 생성하기 때문에 call-by-reference를 사용하는 것이 좋다.
	{
		//스태틱 멤버 안에서는 스태틱 멤버만 접근할 수 있다.
		//idCounter = 3;
		//Color mixed((a.GetR() + b.GetR()) / 2.0f, (a.GetB() + b.GetB()) / 2.0f, (a.GetG() + b.GetG()) / 2.0f);

		Color mixed;
		mixed.r = (a.r + b.r) * 0.5f; //a.r → private 멤버는 클래스 안에서만 사용할 수 있다. 스태틱 멤버 함수도 클래스 내부이기 때문에 사용이 가능하다.
		mixed.g = (a.g + b.g) * 0.5f;
		mixed.b = (a.b + b.b) * 0.5f;

		return mixed;

		//return Color((a.r + b.r) * 0.5f, (a.g + b.g) * 0.5f,(a.b + b.b) * 0.5f); //위와 같은 표현이다. 임시객체를 사용했다. 생성자 호출도 그대로 된다.
	}

};

int Color::idCounter = 0; //정적 변수(스태틱 멤버)를 초기화하는 방법, 앞에 int(자료형)를 붙여줘서 할당이 아닌 초기화임을 표현해야한다.

int main()
{
	Color red(1.0f, 0.0f, 0.0f);
	Color blue(0.0f, 0.0f, 1.0f);
	Color purple = Color::MixColors(red, blue); //스태틱 멤버를 사용할 땐 네임스페이스처럼 "클래스이름::"이 필요하다.

	std::cout << purple.GetR() << std::endl << purple.GetG() << std::endl << purple.GetB() << std::endl;

	purple.Print();

	unsigned int color32 = Color::GetColor32(red);
	std::cout << std::hex << std::setfill('0') << std::setw(8) << color32 << std::endl; //16진수 형태로 나오도록 (FF000000)
	
	Color color = Color::GetColor(color32);
	color.Print();	// (1.0, 0.0, 0.0)


	return 0;
}