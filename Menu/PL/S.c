#include <math.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>

#include <windows.h>
#include <conio.h>

#define MAIN_MENU_SIZE 3
#define ALG_MENU_SIZE 3
#define MENU_SIZE_SET 3
#define MENU_SIZE_POISK 3
#define MENU_SIZE_SORT 2

#define KEY_EXIT 27
#define KEY_ENTER 13
#define ARROW_KEY 224
#define KEY_SPACE 0
#define KEY_BACKSPACE 8

#define KEY_ARROW_RIGHT 77
#define KEY_ARROW_LEFT 75
#define KEY_ARROW_UP 72
#define KEY_ARROW_DOWN 80

void constractMenu(HANDLE hStdOut, char** menu_names, int menu_size, int* choose_pos) {
	// объявление переменных
	int iKey; // переменная для фиксации нажатой клавиши
	COORD cursorPos; // управление положением курсора, чтобы менять выводимый текст
	// инициализация (заполнение значениями) переменных
	*choose_pos = 0;
	/* 1. вывод меню с переключением */
	// сброс консоли в стартовое положение
	system("cls");
	iKey = 67;
	cursorPos = (COORD){ 0, 0 };
	SetConsoleCursorPosition(hStdOut, cursorPos);
	// контроль нажатия клавиш
	while (iKey != KEY_EXIT && iKey != KEY_ENTER) {
		switch (iKey) {
		case KEY_ARROW_UP:
			(*choose_pos)--;
			break;
		case KEY_ARROW_DOWN:
			(*choose_pos)++;
			break;
		}
		system("cls");
		// зацикливание перелистывания меню
		if (*choose_pos < 0) { *choose_pos = menu_size - 1; }
		if (*choose_pos > menu_size - 1) { *choose_pos = 0; }
		for (int i = 0; i < menu_size; i++) {
			cursorPos = (COORD){ 3, i };
			SetConsoleCursorPosition(hStdOut, cursorPos);
			printf("%s \n", menu_names[i]);
		}
		// обозначение выбранной позиции
		cursorPos = (COORD){ 0, *choose_pos };
		SetConsoleCursorPosition(hStdOut, cursorPos);
		printf("<<", iKey);
		cursorPos = (COORD){ strlen(menu_names[*choose_pos]) + 3 + 1, *choose_pos };
		SetConsoleCursorPosition(hStdOut, cursorPos);
		printf(">>");
		// ожидание нового нажатия клавиши
		iKey = _getch();
	}
}
// т.е.основная мысль : в функцию нужно вынести только то, что печатает и листает меню.
//Тогда в main() можно добавить подобные конструкции :
char* menu_main[MAIN_MENU_SIZE] = { "Algorithms", "Settings", "Exit" };
char* menu_alg[ALG_MENU_SIZE] = { "Search", "Sorting", "Back" };
while (!exit_flag) {
	// конструируется ГЛАВНОЕ МЕНЮ, пользователь подтверждает выбранную позицию
	constractMenu(hStdOut, menu_main, MAIN_MENU_SIZE, &choose_pos);
	if (choose_pos == 0) {
		// если выбрано алгоритмы (пункт номер 0), то отрисовываем меню алгоритмов
		system("cls");
		while (!back_flag) {
			// конструируется МЕНЮ АЛГОРИТМОВ, пользователь подтверждает позицию
			constractMenu(hStdOut, menu_alg, ALG_MENU_SIZE, &choose_pos);
			if (choose_pos == 0) {
				// конструируется МЕНЮ АЛГОРИТМОВ, пользователь подтверждает
				// позицию
			// и так хоть до бесконечности можно делать вложенные меню
					//без дублирования кода
			}
		}
	}
}
//Соответственно в самом «вложенном» меню пользователь уже выбирает конкретные действия :
while (!back_flag) {
	// настройки не ветвится, там только действия
	constractMenu(hStdOut, menu_props, PROPS_MENU_SIZE, &choose_pos);
	if (choose_pos == 0) {
		// если пользователь выбрал заполнение массива
		system("cls");
		if (mass != NULL) free(mass);
		mass = inputMass(&size);
		system("pause");
	}
	else if (choose_pos == 1) {
		// если пользователь выбрал вывести на экран
		system("cls");
		printMass(size, mass);
		system("pause");
	}
	else {
		// если пользователь выбрал вернуться
		back_flag = 1;
	}
}
back_flag = 0;