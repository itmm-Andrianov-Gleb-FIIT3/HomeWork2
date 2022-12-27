#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<windows.h>

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	int size;
	printf("Введите размер массива: ");
	scanf_s("%d", &size);
	int* arr = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++) {
		arr[i] = -50 + rand() % 151;
		printf("%d ", arr[i]);
	}


	printf("\n");


	sort(arr, size);

	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;

}

void sort(int* arr, int size) {
	for (int i = size; i > 0; i--) {
		swap(arr, i, arr[i], foundMax(arr, i));
	}
}

int foundMax(int* arr, int size) {
	int max = -1000;
	int indmax;
	for (int i = 0; i < size; i++) {
		if (arr[i] > max) {
			max = arr[i];
			indmax = i;
		}
	}
	return indmax;
}

int swap(int* arr, int size, int arri, int indmax) {
	int buff = arr[size - 1];
	arr[size - 1] = arr[indmax];
	arr[indmax] = buff;
}