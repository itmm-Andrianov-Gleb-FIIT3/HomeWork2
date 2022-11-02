#include <stdio.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <malloc.h>
int main() {
	setlocale(LC_ALL, "rus");

	int* mass;
	int size;

	printf("Введите количество элементов: ");
	scanf_s("%d", &size);
	mass = (int*)malloc(sizeof(int) * size);


	printf("Вводите элементы: ");
	for (int i = 0; i < size; i++) {
		scanf_s("%d", &mass[i]);
	}

	printf("\n");
	for (int g = 0; g < size; g++) {
		printf("%d ", mass[g]);
	}

	printf("\n");
	for (int y = 0; y < size; y++) {
		mass[y] = pow(mass[y], 2);
		printf("%d ", mass[y]);
	}

	printf("\n");
	for (int f = 0; f < size - (size - 1); f++) {
		mass[f] = mass[f] + mass[f + 1];
		printf("Сумма квадратов элементов равна [ %d ]\n", mass[f]);
	}
	free(mass);
	system("pause");
	return 0;
}