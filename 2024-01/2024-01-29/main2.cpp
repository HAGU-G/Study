#include <iostream>

struct Animal
{
	float xpos = 1;
	float ypos = 2;
};

struct FlyingAnimal : public Animal
{
	float zpos = 3;
};

void printfAnimals(Animal** a, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << "(" << a[i]->xpos << ", " << a[i]->ypos << ")" << std::endl;
	}
}

int main()
{
	Animal** arr = new Animal* [5];
	for (int i = 0; i < 5; i++)
	{
		if (i % 2 == 0)
			arr[i] = new FlyingAnimal;
		else
			arr[i] = new Animal;
	}
	printfAnimals(arr, 5);

	for (int i = 0; i < 5; i++)
	{
		delete arr[i];
	}
		delete[] arr;

	return 0;
}