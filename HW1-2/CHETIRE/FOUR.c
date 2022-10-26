#include<stdio.h>
#include<limits.h>
#include<locale.h>
#include<math.h>
int main() {
	setlocale(LC_ALL, "rus");
	int a;
	float V, SB, SP;
	printf("Введите сторону куба:");
	scanf_s("%d", &a);
	if (a > 0) {
		V = ((a) * (a) * (a));
		SB = ((4) * ((a) * (a)));
		SP = ((6) * ((a) * (a)));
		printf("Объём куба V = %.2f\n", V);
		printf("Площадь боковой поверхности куба SB = %.2f\n", SB);
		printf("Площадь полной поверхности куба SP = %.2f\n", SP);
	}
	if (a <= 0) {
		printf("Неправильно введена сторона куба\n");
		system("pause");
		return 0;
	}
}