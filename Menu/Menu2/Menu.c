#include <math.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>

#include <windows.h>
#include <conio.h>

#define MENU_SIZE 3
#define MENU_SIZE_ALGORITM 3
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

int main() {

    // задаЄм название консольного окна
    system("title Application");

    // устанавливаем взаимодействие с русскими буквами
    SetConsoleCP(1251);         // установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);   // установка кодовой страницы win-cp 1251 в поток вывода

    // получаем дескриптор окна дл¤ обращени¤ к консоли
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    // отключение мигани¤ курсора в консоли (в нашем меню курсор лишний)
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hStdOut, &structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hStdOut, &structCursorInfo);

    // задаЄм серый фон дл¤ окна консоли
    SetConsoleTextAttribute(hStdOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
    // очищаем экран, чтобы настройка цвета применилась

    mainmenu(hStdOut);

    system("cls");

}
int mainmenu(hStdOut) {
    // объ¤вление переменных
    int choose_pos;                    // переменна¤ дл¤ хранени¤ выбранного пункта меню
    int iKey;                          // переменна¤ дл¤ фиксации нажатой клавиши
    int exit_flag;                     // флаг на завершение программы
    COORD cursorPos;                   // управление положением курсора, чтобы мен¤ть выводимый текст

    char* menu[MENU_SIZE] = { "Алгоритмы", "Настройки", "Выход" };

    // инициализаци¤ (заполнение значени¤ми) переменных
    exit_flag = 0;
    choose_pos = 0;

    while (!exit_flag) {
        /* 1. вывод меню с переключением */

        // сброс консоли в стартовое положение
        system("cls");
        iKey = 67;
        cursorPos = (COORD){ 0, 0 };
        SetConsoleCursorPosition(hStdOut, cursorPos);

        // контроль нажати¤ клавиш
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

            // зацикливание перелистывани¤ меню
            if (choose_pos < 0) { choose_pos = MENU_SIZE - 1; }
            if (choose_pos > MENU_SIZE - 1) { choose_pos = 0; }

            for (int i = 0; i < MENU_SIZE; i++) {
                cursorPos = (COORD){ 3, i };
                SetConsoleCursorPosition(hStdOut, cursorPos);
                printf("%s \n", menu[i]);
            }

            // обозначение выбранной позиции
            cursorPos = (COORD){ 0, choose_pos };
            SetConsoleCursorPosition(hStdOut, cursorPos);
            printf("<<", iKey);
            cursorPos = (COORD){ strlen(menu[choose_pos]) + 3 + 1, choose_pos };
            SetConsoleCursorPosition(hStdOut, cursorPos);
            printf(">>");

            // ожидание нового нажати¤ клавиши
            iKey = _getch();
        }

        /* 2. основна¤ часть программы */
        switch (choose_pos) {
        case 0:
            system("cls");
            ALG(hStdOut);
            system("pause");
            break;
        case 1:
            system("cls");
            set(hStdOut);
            system("pause");
            break;
        case 2:
            exit_flag = 1;
            break;
        }
    }

    // вывод результата
    system("cls");
    printf("Goodbay!\n");

    // завершение программы
    system("pause");
    return 0;
}

int ALG(hStdOut) {

    int choose_pos;
    int iKey;
    int back_flag;
    COORD cursorPos;

    char* menu[MENU_SIZE_ALGORITM] = { "Поиск", "Сортировки", "Назад" };

    back_flag = 0;
    choose_pos = 0;

    while (!back_flag) {

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

            if (choose_pos < 0) { choose_pos = MENU_SIZE_ALGORITM - 1; }
            if (choose_pos > MENU_SIZE_ALGORITM - 1) { choose_pos = 0; }

            for (int i = 0; i < MENU_SIZE_ALGORITM; i++) {
                cursorPos = (COORD){ 3, i };
                SetConsoleCursorPosition(hStdOut, cursorPos);
                printf("%s \n", menu[i]);
            }

            cursorPos = (COORD){ 0, choose_pos };
            SetConsoleCursorPosition(hStdOut, cursorPos);
            printf("<<", iKey);
            cursorPos = (COORD){ strlen(menu[choose_pos]) + 3 + 1, choose_pos };
            SetConsoleCursorPosition(hStdOut, cursorPos);
            printf(">>");

            iKey = _getch();
        }

        switch (choose_pos) {
        case 0:
            system("cls");
            Poisk(hStdOut);
            system("pause");
            break;
        case 1:
            system("cls");
            Sort(hStdOut);
            system("pause");
            break;
        case 2:
            system("cls");
            mainmenu(hStdOut);
            system("pause");
            break;
        }
    }
}

int Poisk(hStdOut) {

    int choose_pos;
    int iKey;
    int back_flag;
    COORD cursorPos;

    char* menu[MENU_SIZE_POISK] = { "Наивный поиск", "Бинарный поиск", "Назад" };

    back_flag = 0;
    choose_pos = 0;

    while (!back_flag) {

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

            if (choose_pos < 0) { choose_pos = MENU_SIZE_ALGORITM - 1; }
            if (choose_pos > MENU_SIZE_ALGORITM - 1) { choose_pos = 0; }

            for (int i = 0; i < MENU_SIZE_ALGORITM; i++) {
                cursorPos = (COORD){ 3, i };
                SetConsoleCursorPosition(hStdOut, cursorPos);
                printf("%s \n", menu[i]);
            }

            cursorPos = (COORD){ 0, choose_pos };
            SetConsoleCursorPosition(hStdOut, cursorPos);
            printf("<<", iKey);
            cursorPos = (COORD){ strlen(menu[choose_pos]) + 3 + 1, choose_pos };
            SetConsoleCursorPosition(hStdOut, cursorPos);
            printf(">>");

            iKey = _getch();
        }

        switch (choose_pos) {
        case 0:
            system("cls");
            printf("poisk part in development\n");
            system("pause");
            break;
        case 1:
            system("cls");
            printf("poisk part in development\n");
            system("pause");
            break;
        case 2:
            system("cls");
            ALG(hStdOut);
            system("pause");
            break;
        }
    }
}
int Sort(hStdOut) {
    int choose_pos;
    int iKey;
    int back_flag;
    COORD cursorPos;

    char* menu[MENU_SIZE_SORT] = { "Пузырьковая сортировка", "Назад" };

    back_flag = 0;
    choose_pos = 0;

    while (!back_flag) {

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

            if (choose_pos < 0) { choose_pos = MENU_SIZE_SORT - 1; }
            if (choose_pos > MENU_SIZE_SORT - 1) { choose_pos = 0; }

            for (int i = 0; i < MENU_SIZE_SORT; i++) {
                cursorPos = (COORD){ 3, i };
                SetConsoleCursorPosition(hStdOut, cursorPos);
                printf("%s \n", menu[i]);
            }

            cursorPos = (COORD){ 0, choose_pos };
            SetConsoleCursorPosition(hStdOut, cursorPos);
            printf("<<", iKey);
            cursorPos = (COORD){ strlen(menu[choose_pos]) + 3 + 1, choose_pos };
            SetConsoleCursorPosition(hStdOut, cursorPos);
            printf(">>");

            iKey = _getch();
        }

        switch (choose_pos) {
        case 0:
            system("cls");
            printf("sort part in development\n");
            system("pause");
            break;
        case 1:
            system("cls");
            ALG(hStdOut);
            system("pause");
            break;
        }
    }
}
int set(hStdOut) {
    int choose_pos;
    int iKey;
    int back_flag;
    COORD cursorPos;

    char* menu[MENU_SIZE_ALGORITM] = { "Задать массив", "Посмотреть текущий массив", "Назад" };

    back_flag = 0;
    choose_pos = 0;

    while (!back_flag) {

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

            if (choose_pos < 0) { choose_pos = MENU_SIZE_ALGORITM - 1; }
            if (choose_pos > MENU_SIZE_ALGORITM - 1) { choose_pos = 0; }

            for (int i = 0; i < MENU_SIZE_ALGORITM; i++) {
                cursorPos = (COORD){ 3, i };
                SetConsoleCursorPosition(hStdOut, cursorPos);
                printf("%s \n", menu[i]);
            }

            cursorPos = (COORD){ 0, choose_pos };
            SetConsoleCursorPosition(hStdOut, cursorPos);
            printf("<<", iKey);
            cursorPos = (COORD){ strlen(menu[choose_pos]) + 3 + 1, choose_pos };
            SetConsoleCursorPosition(hStdOut, cursorPos);
            printf(">>");

            iKey = _getch();
        }

        switch (choose_pos) {
        case 0:
            system("cls");
            printf("Part in dev\n");
            system("pause");
            break;
        case 1:
            system("cls");
            printf("Part in dev\n");
            system("pause");
            break;
        case 2:
            system("cls");
            mainmenu(hStdOut);
            system("pause");
            break;
        }
    }
}