#include <iostream>
#include <iomanip>

class Color
{
private:
	static int idCounter;
	int id;

	float r; //최소 0.0 ~ 최대 1.0 → 8비트 색을 사용하면 여기에 2^8을 곱함
	float g;
	float b;
	float a;

	unsigned int color32;
	//보통 사용자와의 상호작용에서는 색을 정수형으로 주고받는다.
	//color32는 투명도를 포함하여 각각 1Byte씩 사용하는 것이다. (8bit 4개 32)

public:


	Color() : r(0.0f), g(0.0f), b(0.0f), a(1.0f), id(idCounter++) //0.0뒤에 f를 붙이지 않으면 기본적으로 double형
	{

	}
	Color(float r, float g, float b, float a = 1.0f) : r(r), g(g), b(b), a(a), id(idCounter++)
	{

	}
	~Color()
	{

	}

	float GetR()
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
		//RGBA값이 unsigned int형 4바이트를 모두 사용하여 표현되도록
		return((unsigned int)(color.r * 255) << 24)
			| ((unsigned int)(color.g * 255) << 16)
			| ((unsigned int)(color.b * 255) << 8)
			| ((unsigned int)(color.a * 255));
	}

	static Color GetColor(unsigned int color32)
	{
		/*unsigned int r0 = (unsigned int)255 << 24;
		unsigned int g0 = (unsigned int)255 << 16;
		unsigned int b0 = (unsigned int)255 << 8;
		unsigned int a0 = (unsigned int)255;

		return Color(((color32 & r0) >> 24)/255.0f, ((color32 & g0) >> 16)/255.0f, ((color32 & b0) >> 8)/255.0f, (color32 & a0)/255.0f);*/

		//다른 방법
		//(color32 >> 24) & (255)
		std::cout << ((color32 >> 24) & 0x000000FF) / 255.0f << std::endl;
		return Color( ((color32 >> 24) & 0x000000FF)/255.0f, ((color32 >> 16) & 0x000000FF) / 255.0f, ((color32 >> 8) & 0x000000FF) / 255.0f, (color32 & 0x000000FF) / 255.0f );
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