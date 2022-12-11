#include<stdio.h>
#include<locale.h>
#include<malloc.h>
#include<string.h>
#include<ctype.h>
#include<locale.h>

int main() {

	setlocale(LC_ALL, "rus");

	printf("Введите строку:  ");

	char* str;
	str = (char*)malloc(sizeof(char*) * 100);
	gets(str);


	puts(str);
	printf("Количество значимых знаков %d\n", amountOfSimbols(str));
	printf("Количество строчных букв %d\n", amountOfLowercase(str));
	printf("Количество заглавных букв %d\n", amountOfUppercase(str));
	printf("Количество слов %d\n", amountOfWords(str));
	system("pause");
	return 0;
}

int amountOfSimbols(char* str) {
	int sim = 0;
	while (str[sim] != '\0') {
		sim++;
	}
	int result = 0;
	for (int i = 0; i < sim; i++) {
		if (str[i] != ' ') {
			result++;
		}
	}
	return result;
}

int amountOfLowercase(char* str) {
	int low = 0;
	while (str[low] != '\0') {
		low++;
	}
	int result = 0;
	for (int i = 0; i < low; i++) {
		if (!(isupper(str[i])) && str[i] != ' ') {
			result++;
		}
	}
	return result;
}

int amountOfUppercase(char* str) {
	int Up = 0;
	while (str[Up] != '\0') {
		Up++;
	}
	int result = 0;
	for (int i = 0; i < Up; i++) {
		if (isupper(str[i])) {
			result++;
		}
	}
	return result;
}

int amountOfWords(char* str) {
	int word = 0;
	while (str[word] != '\0') {
		word++;
	}
	int result = 0;
	for (int i = 0; i < word - 2; i++) {
		if ((str[i] != ' ') && (str[i + 1] == ' ') && (str[i + 2] != ' ')) {
			result++;
		}
	}
	return ++result;
}