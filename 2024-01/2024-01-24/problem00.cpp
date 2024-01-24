#include <iostream>
#include <iomanip>

class Color
{
private:
	static int idCounter; //����ƽ ����� �ۿ��� �ʱ�ȭ������Ѵ�.
	int id;

	float r; //�ּ� 0.0 ~ �ִ� 1.0 �� 8��Ʈ ���� ����ϸ� ���⿡ 2^8�� ����
	float g;
	float b;
	float a;

	unsigned int color32;
	//���� ����ڿ��� ��ȣ�ۿ뿡���� ���� ���������� �ְ�޴´�.
	//color32�� ������ �����Ͽ� ���� 1Byte�� ����ϴ� ���̴�. (8bit 4�� 32)

public:

	static unsigned int GetColor32(const Color& color)
	{
		//RGBA���� unsigned int�� 4����Ʈ�� ��� ����Ͽ� ǥ���ǵ���
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

	Color() : r(0.0f), g(0.0f), b(0.0f), a(1.0f), id(idCounter++) //0.0�ڿ� f�� ������ ������ �⺻������ double��
	{

	}
	Color(float r, float g, float b, float a = 1.0f) : r(r), g(g), b(b), a(a), id(idCounter++)
	{

	}
	~Color()
	{

	}

	float GetR() //����� �ν��Ͻ��� ����ƽ���� ���� �� �ִ�. �⺻������ �ν��Ͻ�
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

	static Color MixColors(const Color& a, const Color& b) //call-by-value�� ���� a�� b��� ���ο� �ν��Ͻ��� �����ϱ� ������ call-by-reference�� ����ϴ� ���� ����.
	{
		//����ƽ ��� �ȿ����� ����ƽ ����� ������ �� �ִ�.
		//idCounter = 3;
		//Color mixed((a.GetR() + b.GetR()) / 2.0f, (a.GetB() + b.GetB()) / 2.0f, (a.GetG() + b.GetG()) / 2.0f);

		Color mixed;
		mixed.r = (a.r + b.r) * 0.5f; //a.r �� private ����� Ŭ���� �ȿ����� ����� �� �ִ�. ����ƽ ��� �Լ��� Ŭ���� �����̱� ������ ����� �����ϴ�.
		mixed.g = (a.g + b.g) * 0.5f;
		mixed.b = (a.b + b.b) * 0.5f;

		return mixed;

		//return Color((a.r + b.r) * 0.5f, (a.g + b.g) * 0.5f,(a.b + b.b) * 0.5f); //���� ���� ǥ���̴�. �ӽð�ü�� ����ߴ�. ������ ȣ�⵵ �״�� �ȴ�.
	}

};

int Color::idCounter = 0; //���� ����(����ƽ ���)�� �ʱ�ȭ�ϴ� ���, �տ� int(�ڷ���)�� �ٿ��༭ �Ҵ��� �ƴ� �ʱ�ȭ���� ǥ���ؾ��Ѵ�.

int main()
{
	Color red(1.0f, 0.0f, 0.0f);
	Color blue(0.0f, 0.0f, 1.0f);
	Color purple = Color::MixColors(red, blue); //����ƽ ����� ����� �� ���ӽ����̽�ó�� "Ŭ�����̸�::"�� �ʿ��ϴ�.

	std::cout << purple.GetR() << std::endl << purple.GetG() << std::endl << purple.GetB() << std::endl;

	purple.Print();

	unsigned int color32 = Color::GetColor32(red);
	std::cout << std::hex << std::setfill('0') << std::setw(8) << color32 << std::endl; //16���� ���·� �������� (FF000000)
	
	Color color = Color::GetColor(color32);
	color.Print();	// (1.0, 0.0, 0.0)


	return 0;
}