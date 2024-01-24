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
	Color(float r, float g, float b, float a = 1.0f); //기본값은 선언에서만 사용한다.
	~Color();

	float GetR() const;
	float GetG() const;
	float GetB();

	void Print();


	//static은 선언부에서만 사용한다.
	static Color MixColors(const Color& a, const Color& b);

	static unsigned int GetColor32(const Color& color);

	static Color GetColor(unsigned int color32);
};
