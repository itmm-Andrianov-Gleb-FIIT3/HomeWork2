#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<windows.h>

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	int mass;
	printf("Введите размер массива: ");
	scanf_s("%d", &mass);
	int* arr = (int*)malloc(sizeof(int) * mass);
	for (int i = 0; i < mass; i++) {
		arr[i] = 1 + rand() % 100;
		printf("%d ", arr[i]);
	}


	printf("\n");


	sort(arr, mass);

	for (int i = 0; i < mass; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;

}

int sort(int* arr, int mass) {
	for (int i = mass; i > 0; i--) {
		swap(arr, i, arr[i], foundMax(arr, i));
	}
}

int foundMax(int* arr, int mass) {
	int max = 0;
	for (int i = 0; i < mass; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}

int swap(int* arr, int mass, int arri, int max) {
	int buff = arr[mass - 1];
	arr[mass - 1] = max;
	for (int i = 0; i < mass - 1; i++) {
		if (arr[i] == max) {
			arr[i] = buff;
		}
	}
}