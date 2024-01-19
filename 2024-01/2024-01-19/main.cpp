#include <stdio.h>
#include <stdlib.h>

struct ProductInfo 
{
	int num = 0;
	char name[100] = "이름";
	int cost = 0;
};

void ProductSwap(ProductInfo* a, ProductInfo* b);

void ProductSwap2(ProductInfo* a, ProductInfo* b);

int main()
{
	ProductInfo myProduct = { 1010, "제주 한라봉", 100000 };
	ProductInfo yourProduct = { 9090, "성주 꿀참외", 990000 };

	ProductSwap(&myProduct, &yourProduct);
	printf("%s\n%s", myProduct.name, yourProduct.name);

}

void ProductSwap(ProductInfo* a, ProductInfo* b)
{
	char temp[100];
	for (int i = 0; a->name[i] != '\0'; i++)
	{
		temp[i] = a->name[i];
		temp[i + 1] = '\0';
		
	}
	for (int i = 0; b->name[i] != '\0'; i++)
	{
		a->name[i] = b->name[i];
		a->name[i + 1] = '\0';
	}
	for (int i = 0; temp[i] != '\0'; i++)
	{
		b->name[i] = temp[i];
		b->name[i + 1] = '\0';
	}
}

void ProductSwap2(ProductInfo* a, ProductInfo* b)
{
	ProductInfo temp = *a;
	*a = *b;
	*b = temp;

}
