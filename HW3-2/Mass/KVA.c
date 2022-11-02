#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <windows.h>

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int EQ, E, SOS, Pr;
	Pr = 0;
	SOS = 0;

	printf("Количество элементов: ");
	scanf_s("%d", &EQ);

	while (Pr < EQ)
	{
		printf("Вводите элементы: ");
		scanf_s("%d", &E);
		system("cls");
		SOS += pow(E, 2);
		Pr++;
	}

	printf("Сумма квадратов элементов равна = %d\n", SOS);
	system("pause");
	return 0;
}