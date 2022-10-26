#include<stdio.h>
#include<limits.h>
#include<locale.h>
#include<math.h>
int main() {
	setlocale(LC_ALL, "rus");
	int a, b;
	float SUM, RAZ, PRO, CHAS, SCOR, SMOD;
	printf("Введите a:");
	scanf_s("%d", &a);
	printf("Введите b:");
	scanf_s("%d", &b);
	if (a > 0 && b > 0) {
		SUM = ((a)+(b));
		RAZ = ((a)-(b));
		PRO = ((a) * (b));
		CHAS = ((float)(a) / (b));
		SCOR = (((pow(a, 2)) + (pow(b, 2))) / 2);
		SMOD = ((float)((abs(a)) + (abs(b))) / 2);
		printf("Сумма = %.2f\n", SUM);
		printf("Разность = %.2f\n", RAZ);
		printf("Произведение = %.2f\n", PRO);
		printf("Частное = %.2f\n", CHAS);
		printf("Ср. Ар. Корней = %.2f\n", SCOR);
		printf("Ср. Ар. Модулей = %.2f\n", SMOD);
	}
	if ((a < 0 && b < 0) || (a < 0) || (b < 0)) {
		printf("Неправильно введены числа\n");
	}
	system("pause");
	return 0;
}