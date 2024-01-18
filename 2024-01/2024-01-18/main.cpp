#include <stdio.h>

int Factorial(int);
int Fibbo(int n);
void printN(int);


int main()
{
	printf("%d\n", Factorial(2));
	for (int i = 1; i <= 10; i++)
	{
		printf("%d ", Fibbo(i));
	}
	printf("\n");
	printN(1111321);


	return 0;
}

int Factorial(int n)
{
	if (n == 0)
	{
		return 1;
	}
	return n *= Factorial(n - 1);
}

int Fibbo(int n)
{
	if (n <= 2)
	{
		return n - 1;
	}
	return Fibbo(n - 1) + Fibbo(n - 2);
}

void printN(int n)
{
	int temp = n;
	int count = 0; //ÀÚ¸´¼ö
	while (temp > 0) //ÀÚ¸´¼ö °è»ê
	{
		temp /= 10;
		count++;
	}
	temp = n;

	for (int i = 1; i < count; i++)
	{
		temp /= 10;
	}
	printf("%d", temp);
	if ((count > 3) && (count % 3 == 1))
		printf(",");

	int ten = 10;
	for (int i = 1; i < count-1; i++)
	{
		ten *= 10;
	}
	if (n >= 10)
		printN(n - temp * ten);
}