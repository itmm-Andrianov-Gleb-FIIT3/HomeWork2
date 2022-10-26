#include <stdio.h>;
#include <malloc.h>;
#include <iostream>
#include <algorithm>
#include <math.h>
#include <locale.h>
#include <string.h>
#include <assert.h>
#include <conio.h>
#include <windows.h>


#define MENU_SIZE 5

#define KEY_EXIT 27
#define KEY_ENTER 13
#define ARROW_KEY 224
#define KEY_SPACE 0
#define KEY_BACKSPACE 8

#define KEY_ARROW_RIGHT 77
#define KEY_ARROW_LEFT 75
#define KEY_ARROW_UP 72
#define KEY_ARROW_DOWN 80

int main() {

    system("title Best Menu Ever!");


    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hStdOut, &structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hStdOut, &structCursorInfo);

    menu(hStdOut);

    system("cls");
    return 0;
}
int menu(hStdOut) {
    int a, b;
    int iKey;
    char* str;
    str = (char*)malloc(sizeof(char) * 100);
    system("cls");
    printf("Ввод: ");
    scanf_s("%d", &a);
    choise(hStdOut);
}
int choise(hStdOut) {

    int a, b;
    int choose_pos;
    int iKey;
    int exit_flag;
    int back_flag;
    COORD cursorPos;

    char* choise[MENU_SIZE] = { "1. Заменить строку.", "2. Обрезать строку.", "3. Развернуть строку.","4. Сменить регистр [Таблица ASCII].","0. Выход" };

    exit_flag = 0;
    choose_pos = 0;

    while (!exit_flag) {
        system("cls");
        iKey = 67;
        cursorPos = (COORD){ 0, 0 };
        SetConsoleCursorPosition(hStdOut, cursorPos);

        while (iKey != KEY_EXIT && iKey != KEY_ENTER) {
            switch (iKey) {
            case KEY_ARROW_UP:
                choose_pos--;
                break;
            case KEY_ARROW_DOWN:
                choose_pos++;
                break;
            }

            system("cls");

            if (choose_pos < 0) { choose_pos = MENU_SIZE - 1; }
            if (choose_pos > MENU_SIZE - 1) { choose_pos = 0; }

            for (int i = 0; i < MENU_SIZE; i++) {
                cursorPos = (COORD){ 3, i };
                SetConsoleCursorPosition(hStdOut, cursorPos);
                printf("%s \n", choise[i]);
            }

            cursorPos = (COORD){ 0, choose_pos };
            SetConsoleCursorPosition(hStdOut, cursorPos);
            printf("<<", iKey);
            cursorPos = (COORD){ strlen(choise[choose_pos]) + 3 + 1, choose_pos };
            SetConsoleCursorPosition(hStdOut, cursorPos);
            printf(">>");

            iKey = _getch();
        }

        switch (choose_pos) {
        case 0:
            system("cls");
            menu(hStdOut);
            system("pause");
            break;
        case 1:
            system("cls");
            printf("part in development\n");
            system("pause");
            break;
        case 2:
            system("cls");
            revers(hStdOut);
            system("pause");
            break;
        case 3:
            system("cls");
            printf("part in development\n");
            system("pause");
            break;
        case 4:
            system("cls");
            printf("До свидания!\n");
            system("pause");
            return 0;
            break;
        }
    }
    system("cls");
    printf("Goodbay!\n");

    system("pause");
    return 0;
}
int revers(hStdOut) {
    int a;
    system("cls");
    printf("part in development\n");
    printf("pidor\n");
}