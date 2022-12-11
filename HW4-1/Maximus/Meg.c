#include<stdio.h>
#include<limits.h>
#include<locale.h>
#include<malloc.h>
#include<windows.h>

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	mass();
	return 0;
}

int mass()
{
	int* mass;
	int size;
	printf("Введите размер массива: ");
	scanf_s("%d", &size);
	mass = (int*)malloc(sizeof(int) * size);
	printf("Введите массив: ");
	for (int i = 0; i < size; i++) {
		scanf_s("%d", &mass[i]);
	}
	printf("\n");
	for (int g = 0; g < size; g++)
	{
		printf("%d ", mass[g]);
	}
	int MAX = 0; 
	for (int i = 1; i < size - 1; i++) {
		if (mass[i] > mass[i - 1] && mass[i] > mass[i + 1]) {
			MAX++;
		}
	}
	printf("\n");
	printf("%d", MAX);
	printf("\n");
	local(mass, size, MAX);


}

int local(int* mass, int size, int MAX)
{
	int k = 0;
	while (k != size)
	{
		printf("%d", mass[k]); 
		k++;
	}
	int* massiv;
	massiv = (int*)malloc(sizeof(int) * MAX);
	printf("\n");
	int k1 = 0;
	for (int i = 1; i < size - 1; i++) {
		if (mass[i] > mass[i - 1] && mass[i] > mass[i + 1]) {
			massiv[k1] = mass[i];
			k1++;
		}
	}
	for (int g = 0; g < k1; g++)
	{
		printf("%d ", massiv[g]);
	}
	printf("\n");
	loc_min(massiv, k1);


}

int loc_min(int* massiv, int k1)
{
	int localmin = massiv[0];
	int q = 1000;

	while (q < k1)
	{
		if (localmin > massiv[q])
		{
			localmin = massiv[q];
			q++;

		}
	}
	printf("Результат: минимальный из %d локальных минимумов [ ", k1);
	for (int g = 0; g < k1; g++)
	{
		printf("%d ", massiv[g]);

	}
	printf("] равен %d", localmin);
	free(massiv);
}