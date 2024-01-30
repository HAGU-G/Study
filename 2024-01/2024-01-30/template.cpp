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

//�Ʒ� ��Ȳ���� Sum<std::string>(...)�� �ϰ� �ȴٸ� ��Ÿ�ӿ����� �߻��Ѵ�.
//T sum = 0;���� string�� nullptr�� ���ԵǾ� �߻��� �����̴�.
//���ø� Ư��ȭ�� �ؾ��Ѵ�.
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

//���ø� Ư��ȭ
template<> //���ø� Ű���带 �����ְ�, �Ű�����(����)�� �������� ������ �����ؾ��Ѵ�.
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
	//Print<int>(arrInt, 5); 18���� ���� �κ��� �����Ǿ� �ִ�.
	Print(arrDouble, 5);

	return 0;
}