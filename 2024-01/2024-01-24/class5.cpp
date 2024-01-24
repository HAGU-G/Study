//상수형 멤버 함수

#include <iostream>
#include <iomanip>

class Color
{
private:
	static int idCounter;
	int id;

	float r;
	float g;
	float b;
	float a;

	unsigned int color32;

public:


	Color() : r(0.0f), g(0.0f), b(0.0f), a(1.0f), id(idCounter++)
	{

	}
	Color(float r, float g, float b, float a = 1.0f) : r(r), g(g), b(b), a(a), id(idCounter++)
	{

	}
	~Color()
	{

	}

	//상수형 함수 : 함수를 통해 인스턴스의 멤버의 데이터가 변경되지 않는다.
	//상수형 멤버 함수 안에서는 상수형 멤버만 호출할 수 있다.
	float GetR() const 
	{
		return r;
	}
	float GetG() const
	{
		return g;
	}
	float GetB()
	{
		return b;
	}

	void Print()
	{
		std::cout << "(" << r << ", " << g << ", " << b << ", " << a << ")" << std::endl;
	}

	static Color MixColors(const Color& a, const Color& b)
	{
		Color mixed;
		mixed.r = (a.r + b.r) * 0.5f;
		mixed.g = (a.g + b.g) * 0.5f;
		mixed.b = (a.b + b.b) * 0.5f;

		return mixed;

	}

	static unsigned int GetColor32(const Color& color)
	{
		return((unsigned int)(color.r * 255) << 24)
			| ((unsigned int)(color.g * 255) << 16)
			| ((unsigned int)(color.b * 255) << 8)
			| ((unsigned int)(color.a * 255));
	}

	static Color GetColor(unsigned int color32)
	{
		return Color(((color32 >> 24) & 0x000000FF) / 255.0f, ((color32 >> 16) & 0x000000FF) / 255.0f, ((color32 >> 8) & 0x000000FF) / 255.0f, (color32 & 0x000000FF) / 255.0f);
	}
};

int Color::idCounter = 0;

int main()
{
	Color red(1.0f, 0.0f, 0.0f);
	Color blue(0.0f, 0.0f, 1.0f);
	Color purple = Color::MixColors(red, blue);

	unsigned int color32 = Color::GetColor32(purple);
	std::cout << std::hex << std::setfill('0') << std::setw(8) << color32 << std::endl; //16진수 형태로 나오도록 (FF000000)

	Color color = Color::GetColor(color32);
	color.Print();	// (1.0, 0.0, 0.0)


	return 0;
}