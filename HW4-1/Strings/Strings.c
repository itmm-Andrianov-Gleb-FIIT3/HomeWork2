#include<stdio.h>
#include<locale.h>
#include<malloc.h>
#include<string.h>
#include<ctype.h>

int main() {

	char* str;
	str = (char*)malloc(sizeof(char*) * 100);
	int userInput = 1;
	printf("Введите строку: \n");
	gets(str);

	int len = 0;
	while (str[len] != '\0') {
		len++;
	}
	str[len + 1] = "\0";
	puts(str);
	system("pause");


	while (1)
	{
		system("cls");
		printf("1)Написать новую строку\n2)Обрезать строку\n3)Развернуть строку\n4)Сменить регистр [Таблица ASCII]\n0)Выход\n");
		scanf_s("%d", &userInput);

		if (userInput == 0) {
			break;
		}
		else if (userInput == 1) {
			system("cls");
			printf("print new string\n");
			newString(str);
			printf("new str: ");
			puts(str);
			system("pause");
		}
		else if (userInput == 2) {
			system("cls");
			printf("print last index\n");
			cutString(str);
			puts(str);
			system("pause");
		}
		else if (userInput == 3) {
			system("cls");
			printf("old str: ");
			puts(str);
			reverseString(str);
			printf("new str:");
			puts(str);
			system("pause");
		}

		else if (userInput == 4) {

			int len = 0;
			while (str[len] != '\0') {
				len++;
			}
			int userCaseInput = 1;

			while (1)
			{
				system("cls");
				printf("1)Заменить на заглавные буквы\n2)Заменить на строчные буквы\n3)Заменить строчные на заглавные и наоборот\n0)Назад\n");
				scanf_s("%d", &userCaseInput);

				if (userCaseInput == 0)
				{
					break;
				}
				else if (userCaseInput == 1) {
					changeToUpper(str);
					puts(str);
					system("pause");
				}
				else if (userCaseInput == 2) {
					changeToLower(str);
					puts(str);
					system("pause");
				}
				else if (userCaseInput == 3) {
					reverseCase(str);
					puts(str);
					system("pause");
				}
			}


		}

	}


	free(str);
	system("pause");
	return 0;
}

char newString(char* str) {
	getchar();
	gets(str);
	int len = 0;
	int flag = 0;
	while (str[len] != '\0') {
		len++;
	}
	while (len > 100) {
		printf("Пожжалуйста, попробуйте снова.");
		gets(str);
		while (str[len] != '\0') {
			len++;
		}
	}
	return str;
}

char cutString(char* str) {
	int lastIndex;
	scanf_s("%d", &lastIndex);
	str[lastIndex] = '\0';
	return str;
}

char reverseString(char* str) {
	int len = 0;
	while (str[len] != '\0') {
		len++;
	}

	char* cloneStr;
	cloneStr = (char*)malloc(sizeof(char*) * 100);
	cloneStr[len] = '\0';
	for (int i = len; i > 0; i--) {
		cloneStr[len - i] = str[i - 1];
	}

	for (int i = 0; i < len; i++) {
		str[i] = cloneStr[i];
	}

	return str;
}

char changeToUpper(char* str) {
	int len = 0;
	while (str[len] != '\0') {
		len++;
	}

	for (int i = 0; i < len; i++) {
		str[i] = toupper(str[i]);
	}

	return str;
}

char changeToLower(char* str) {
	int len = 0;
	while (str[len] != '\0') {
		len++;
	}

	for (int i = 0; i < len; i++) {
		str[i] = tolower(str[i]);
	}

	return str;
}

char reverseCase(char* str) {
	int len = 0;
	while (str[len] != '\0') {
		len++;
	}

	for (int i = 0; i < len; i++) {
		if (isupper(str[i])) {
			str[i] = tolower(str[i]);
		}
		else
		{
			str[i] = toupper(str[i]);
		}
	}

	return str;
}