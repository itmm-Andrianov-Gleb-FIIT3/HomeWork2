#include<stdio.h>
#include<limits.h>
#include<locale.h>
#include<malloc.h>
#include<windows.h>

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int* mass;
	int size;
	printf("Введите размер массива: ");
	scanf_s("%d", &size);
	mass = (int*)malloc(sizeof(int) * size);
	printf("Введите массив: ");
	for (int i = 0; i < size; i++) {
		scanf_s("%d", &mass[i]);
	}

	LocMax(mass, size);
	return 0;

}

int LocMax(int* mass, int size) {

	int MAX = 0;
	for (int i = 1; i < size - 1; i++) {
		if (mass[i] > mass[i - 1] && mass[i] > mass[i + 1]) {
			MAX++;
		}
	}
	MaxQ(mass, size, MAX);
}

int MaxQ(int* mass, int size, int MAX)
{
	int k = 0;
	int* massiv;

	massiv = (int*)malloc(sizeof(int) * MAX);

	int k1 = 0;
	for (int i = 1; i < size - 1; i++) {
		if (mass[i] > mass[i - 1] && mass[i] > mass[i + 1]) {
			massiv[k1] = mass[i];
			k1++;
		}
	}
	loc_min(massiv, k1, MAX);
}

int loc_min(int* massiv, int k1, int MAX)
{
	int localmin = massiv[0];

	for (int i = 0; i < k1; i++) {
		if (localmin > massiv[i]) {
			localmin = massiv[i];
			i++;
		}
	}

	printf("Результат: минимальный из %d локальных минимумов [ ", k1);
	for (int g = 0; g < k1; g++)
	{
		printf("%d ", massiv[g]);

	}
	printf("] равен %d\n", localmin);
	free(massiv);
}