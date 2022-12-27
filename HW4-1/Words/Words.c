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

int len(char* str) {
	int sym = 0;
	while (str[sym] != '\0') {
		sym++;
	}
	return sym;
}

int amountOfSimbols(char* str) {
	
	int sym = len(str);

	int result = 0;
	for (int i = 0; i < sym; i++) {
		if (str[i] != ' ') {
			result++;
		}
	}
	return result;
}

int amountOfLowercase(char* str) {

	int sym = len(str);

	int result = 0;
	for (int i = 0; i < sym; i++) {
		if (islower(str[i])) {
			result++;
		}
	}
	return result;
}

int amountOfUppercase(char* str) {
	
	int sym = len(str);

	int result = 0;
	for (int i = 0; i < sym; i++) {
		if (isupper(str[i])) {
			result++;
		}
	}
	return result;
}

int amountOfWords(char* str) {

	int sym = len(str);

	int result = 0;
	for (int i = 0; i < sym - 2; i++) {
		if ((str[i] != ' ') && (str[i + 1] == ' ')) {
			result++;
		}
	}
	return ++result;
}