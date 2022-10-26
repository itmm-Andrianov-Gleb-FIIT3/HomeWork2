#include<stdio.h>
#include<limits.h>
#include<locale.h>
#include<math.h>
int main() {
	setlocale(LC_ALL, "rus");
	int n;
	float a, b, c;
	printf("Ввод:");
	scanf_s("%d", &n);
	a = n;
	b = n + 1;
	c = n + 2;
	printf("1: %.2f\n", a);
	printf("2: %.2f\n", b);
	printf("2: %.2f\n", c);
	system("pause");
	return 0;
}