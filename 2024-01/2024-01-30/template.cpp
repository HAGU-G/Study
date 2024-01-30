#include <iostream>

template<typename T1>
class Vector3
{
private:
	T1 x;
	T1 y;
	T1 z;
public:
	Vector3(T1 x, T1 y, T1 z) : x(x), y(y), z(z)
	{
	}
	~Vector3()
	{
	}

	T1 GetX() const { return x; }
	void SetX(T1 x) { this->x = x; }
};

template<typename T>
void Print(T* arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << arr[i] << std::endl;
	}
}

//아래 상황에서 Sum<std::string>(...)을 하게 된다면 런타임에러가 발생한다.
//T sum = 0;에서 string에 nullptr가 들어가게되어 발생한 오류이다.
//템플릿 특수화를 해야한다.
template<typename T>
T Sum(T* arr, int size)
{
	T sum = 0;
	for (int i = 0; i < size; ++i)
	{
		sum += arr[i];
	}
	return sum;
}

//템플릿 특수화
template<> //템플릿 키워드를 적어주고, 매개변수(인자)는 정해졌기 때문에 생략해야한다.
std::string Sum(std::string* arr, int size)
{
	std::string sum = "";
	for (int i = 0; i < size; ++i)
	{
		sum += arr[i];
		sum += " ";
	}
	return sum;
}


int main()
{
	Vector3<float> v1(0.f,1.f,2.f);
	std::cout << v1.GetX() << std::endl;


	int arrInt[] = { 1,2,3,4,5 };
	double arrDouble[] = { 1.0,2.0,3.0,4.0,5.0 };

	Print(arrInt, 5);
	//Print<int>(arrInt, 5); 18행은 꺽쇠 부분이 생략되어 있다.
	Print(arrDouble, 5);

	return 0;
}