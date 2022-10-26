#include<stdio.h>
#include<limits.h>
#include<locale.h>
#include<math.h>
int main() {
	setlocale(LC_ALL, "rus");
	int x1, x2, x3, y1, y2, y3;
	float a, b, c, P, pper, S;
	printf("Введите x1 и y1:");
	scanf_s("%d %d", &x1, &y1);
	printf("Введите x2 и y2:");
	scanf_s("%d %d", &x2, &y2);
	printf("Введите x3 и y3:");
	scanf_s("%d %d", &x3, &y3);
	a = (sqrt((pow(x3 - x2, 2)) + (pow(y3 - y2, 2))));
	b = (sqrt((pow(x3 - x1, 2)) + (pow(y3 - y1, 2))));
	c = (sqrt((pow(x2 - x1, 2)) + (pow(y2 - y1, 2))));
	P = (((a)+(b)+(c)));
	pper = (((a)+(b)+(c)) / 2);
	S = (sqrt((pper) * (pper - a) * (pper - b) * (pper - c)));
	printf("Периметр равен %.2f\n", P);
	printf("Площадь равна %.2f\n", S);
}