#include <stdio.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
int main() {
	setlocale(LC_ALL, "rus");
	int age;
	printf("Введите возраст:");
	scanf_s("%d", &age);
	if (age <= 13 ) {
		printf("Детство\n");
	}
	if (age >= 14 && age < 25) {
		printf("Молодость\n");
	}
	if (25 <= age && age < 60) {
		printf("Зрелость\n");
	}
	if ( age >= 60) {
		printf("Старость\n");
	}
	system("pause");
	return 0;
}