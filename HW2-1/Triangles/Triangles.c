#include <stdio.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
int main() {
	setlocale(LC_ALL, "rus");
	int a, b, c;
	printf("Введите стороны треугольника(Через пробел):");
	scanf_s("%d %d %d", &a, &b, &c);
	if (a == b && b == c && a == c) {
		printf("Равносторонний треугольник\n");
	}
	else if (a == b || b == c || a == c) {
		printf("Равнобедренный треугольник\n");
	}
	else if ((a) * (a) == ((b) * (b)) + ((c) * (c)) || (b) * (b) == ((a) * (a)) + ((c) * (c)) || (c) * (c) == ((a) * (a)) + ((b) * (b))) {
		printf("Прямоугольный треугольник\n");
	}
	else if ((a)+(b) < (c) || (c)+(b) < (a) || (a)+(c) < (b)) {
		printf("Не является треугольником\n");
	}
	else {
		printf("Произвольный треугольник\n");
	}
	system("pause");
	return 0;
}