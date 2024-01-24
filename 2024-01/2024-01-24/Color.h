#pragma once

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


	Color();
	Color(float r, float g, float b, float a = 1.0f); //�⺻���� ���𿡼��� ����Ѵ�.
	~Color();

	float GetR() const;
	float GetG() const;
	float GetB();

	void Print();


	//static�� ����ο����� ����Ѵ�.
	static Color MixColors(const Color& a, const Color& b);

	static unsigned int GetColor32(const Color& color);

	static Color GetColor(unsigned int color32);
};
