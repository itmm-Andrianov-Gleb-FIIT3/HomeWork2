#include <math.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "sys/stat.h"
#include <windows.h>
#include <conio.h>

#define MAIN_MENU_SIZE 4

//Подменю Режим эксперимента
#define EXPERIMENT_MENU_SIZE 3 
#define EFFICIENCY_MENU_SIZE 6

//Подменю Алгоритмы
#define ALGORITHMS_MENU_SIZE 3
#define SEARHC_MENU_SIZE 3
#define SORT_MENU_SIZE 5

//Подменю Настройки
#define SETTINGS_MENU_SIZE 4
#define SET_ARRAY_MENU_SIZE 4

// основные ключи, которые могут пригодитьс¤
#define KEY_EXIT 27
#define KEY_ENTER 13
#define ARROW_KEY 224
#define KEY_SPACE 0
#define KEY_BACKSPACE 8

#define KEY_ARROW_RIGHT 77
#define KEY_ARROW_LEFT 75
#define KEY_ARROW_UP 72
#define KEY_ARROW_DOWN 80

void random_generate_mass(int max_value, int min_value, int len, int* mass) {

    for (int i = 0; i < len; i++) {
        mass[i] = min_value + rand() % (max_value - min_value + 1);
    }

    return;
}

void manually_generaye_mass(int len, int* mass) {
    printf("Введите числа: ");
    for (int i = 0; i < len; i++) {
        scanf_s("%d", &mass[i]);
    }

    return;
}

void print_mass(int* mass, int len) {

    for (int i = 0; i < len; i++) {
        printf("%d ", mass[i]);
    }
    printf("\n");
    return;
}
//Наивный поиск
void naive_search(int desired_value, int* mass, int len) {
    system("cls");
    int index_of_desired_value = -1;
    for (int i = 0; i < len; i++) {
        if (mass[i] == desired_value) {
            int index_of_desired_value = i;
            printf("Индекс желаемого значения = %d\n", index_of_desired_value);
            return;
        }
    }

    if (index_of_desired_value == -1) {
        printf("Такого элемента в массиве нет.\n");
    }

    return;

}
//Бинарный поиск
void binary_search(int* mass, int len) {

    system("cls");

    for (int i = 0; i < len - 1; i++) {
        if (mass[i] > mass[i + 1]) {
            printf("Невозможно применить бинарный поиск к неотсортированному массиву.\n");
            return;
        }
    }

    int index_of_desired_value = -1;

    printf("Введите желаемое значение: ");
    int desired_value;
    scanf_s("%d", &desired_value);

    int left_border = 0;
    int right_border = len - 1;
    int midle = -1;

    while (left_border < right_border) {

        midle = (left_border + right_border);

        if (mass[midle] < desired_value) {
            left_border = midle + 1;
        }
        else if (mass[midle] > desired_value) {
            right_border = midle - 1;
        }
        else if (mass[midle] == desired_value) {
            index_of_desired_value = midle;
            printf("Индекс желаемого значения: = %d\n", index_of_desired_value);
            break;
        }

    }

    if (index_of_desired_value == -1) {
        printf("Такого элемента в массиве нет.\n");
    }

    return;
}

void swap(int* a, int* b) {

    int tmp = *a;
    *a = *b;
    *b = tmp;

}
//Сортировка пузырьком
void bub_sort(int* mass, int len) {
    for (int i = len; i > 0; i--) {
        swap_bub(mass, i, mass[i], foundMax(mass, i));
    }
}
int foundMax(int* mass, int len) {
    int max = -1000000;
    int indmax;
    for (int i = 0; i < len; i++) {
        if (mass[i] > max) {
            max = mass[i];
            indmax = i;
        }
    }
    return indmax;
}

int swap_bub(int* mass, int len, int massi, int indmax) {
    int buff = mass[len - 1];
    mass[len - 1] = mass[indmax];
    mass[indmax] = buff;

}
//Сортировка Хоара

void fast_sort(int* mass, int left, int right)
{
    int pivot; // разрешающий элемент
    int l_hold = left; //левая граница
    int r_hold = right; // правая граница
    pivot = mass[left];
    while (left < right) // пока границы не сомкнутся
    {
        while ((mass[right] >= pivot) && (left < right))
            right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
        if (left != right) // если границы не сомкнулись
        {
            mass[left] = mass[right]; // перемещаем элемент [right] на место разрешающего
            left++; // сдвигаем левую границу вправо
        }
        while ((mass[left] <= pivot) && (left < right))
            left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
        if (left != right) // если границы не сомкнулись
        {
            mass[right] = mass[left]; // перемещаем элемент [left] на место [right]
            right--; // сдвигаем правую границу влево
        }
    }
    mass[left] = pivot; // ставим разрешающий элемент на место
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
        fast_sort(mass, left, pivot - 1);
    if (right > pivot)
        fast_sort(mass, pivot + 1, right);
}

//Сортировка Шелла
void shell_sort(int* mass, int len)
{
    int i, j, step;
    int tmp;
    for (int step = len / 2; step > 0; step /= 2)
        for (i = step; i < len; i++)
        {
            tmp = mass[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < mass[j - step])
                    mass[j] = mass[j - step];
                else
                    break;
            }
            mass[j] = tmp;
        }
}

//Сортировка Шейкера
void sheker_sort(int* mass, int len)
{
    int left = 0, right = len - 1; // левая и правая границы сортируемой области массива
    int flagSH = 1;  // флаг наличия перемещений
    // Выполнение цикла пока левая граница не сомкнётся с правой
    // и пока в массиве имеются перемещения
    while ((left < right) && flagSH > 0)
    {
        flagSH = 0;
        for (int i = left; i < right; i++)  //двигаемся слева направо
        {
            if (mass[i] > mass[i + 1]) // если следующий элемент меньше текущего,
            {             // меняем их местами
                double t = mass[i];
                mass[i] = mass[i + 1];
                mass[i + 1] = t;
                flagSH = 1;      // перемещения в этом цикле были
            }
        }
        right--; // сдвигаем правую границу на предыдущий элемент
        for (int i = right; i > left; i--)  //двигаемся справа налево
        {
            if (mass[i - 1] > mass[i]) // если предыдущий элемент больше текущего,
            {            // меняем их местами
                double t = mass[i];
                mass[i] = mass[i - 1];
                mass[i - 1] = t;
                flagSH = 1;    // перемещения в этом цикле были
            }
        }
        left++; // сдвигаем левую границу на следующий элемент
    }
}

int main() {

    system("title M.U.D.A.");

    srand(time(0));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hStdOut, &structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hStdOut, &structCursorInfo);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
    system("cls");

    int choose_pos;
    int iKey;
    int exit_flag;
    COORD cursorPos;

    char* main_menu[MAIN_MENU_SIZE] = { "Режим эксперимента","Алгоритмы", "Настройки", "Выход" };

    char* experiment_menu[EXPERIMENT_MENU_SIZE] = { "Сравнение сортировок","Эффективность", "Назад" };
    char* efficiency_menu[EFFICIENCY_MENU_SIZE] = { "Сортировка пузырьком","Сортировка Хоара", "Сортировка Шелла", "Шейкерная сортировка", "Задать массив", "Назад" };

    char* algorithms_menu[ALGORITHMS_MENU_SIZE] = { "Поиск", "Сортировка", "Назад" };
    char* search_menu[SEARHC_MENU_SIZE] = { "Наивный поиск", "Бинарный поиск", "Назад" };
    char* sort_menu[SORT_MENU_SIZE] = { "Сортировка пузырьком","Сортировка Хоара", "Сортировка Шелла", "Шейкерная сортировка", "Назад" };

    char* settings_menu[SETTINGS_MENU_SIZE] = { "Задать массив", "Показать текущий массив", "Изменить путь до рабочей директории", "Назад" };
    char* set_array_menu[SET_ARRAY_MENU_SIZE] = { "Задать вручную", "Сгенерировать случайно", "Прочитать из файла", "Назад" };

    int* mass;
    int len = 20;
    int max_value, min_value;
    mass = (int*)malloc(sizeof(int) * len);
    random_generate_mass(100, 1, 20, mass);

    exit_flag = 0;
    choose_pos = 0;

    char fold[100] = "C:\\Users\\Пользователи\\User\\sourse\\repos\\";
    char filename[100] = "input.txt";
    char filepath[200];

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

            if (choose_pos < 0) { choose_pos = MAIN_MENU_SIZE - 1; }
            if (choose_pos > MAIN_MENU_SIZE - 1) { choose_pos = 0; }

            for (int i = 0; i < MAIN_MENU_SIZE; i++) {
                cursorPos = (COORD){ 4, i };
                SetConsoleCursorPosition(hStdOut, cursorPos);
                printf("%s \n", main_menu[i]);
            }

            cursorPos = (COORD){ 0, choose_pos };
            SetConsoleCursorPosition(hStdOut, cursorPos);
            printf("<<", iKey);
            cursorPos = (COORD){ strlen(main_menu[choose_pos]) + 4 + 1, choose_pos };
            SetConsoleCursorPosition(hStdOut, cursorPos);
            printf(">>");

            iKey = _getch();
        }
        //Experiment Mode
        if (choose_pos == 0) {
            system("cls");
            int choose_pos;
            int iKey;
            int sub_exit_flag;
            COORD cursorPos;

            sub_exit_flag = 0;
            choose_pos = 0;

            while (!sub_exit_flag) {
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

                    if (choose_pos < 0) { choose_pos = EXPERIMENT_MENU_SIZE - 1; }
                    if (choose_pos > EXPERIMENT_MENU_SIZE - 1) { choose_pos = 0; }

                    for (int i = 0; i < EXPERIMENT_MENU_SIZE; i++) {
                        cursorPos = (COORD){ 3, i };
                        SetConsoleCursorPosition(hStdOut, cursorPos);
                        printf("%s \n", experiment_menu[i]);
                    }

                    cursorPos = (COORD){ 0, choose_pos };
                    SetConsoleCursorPosition(hStdOut, cursorPos);
                    printf("<<", iKey);
                    cursorPos = (COORD){ strlen(experiment_menu[choose_pos]) + 3 + 1, choose_pos };
                    SetConsoleCursorPosition(hStdOut, cursorPos);
                    printf(">>");

                    iKey = _getch();
                }
   //Сравнение сортировок
                if (choose_pos == 0) {
                    system("cls");
                    printf("in development\n");
                    system("pause");
                }
   //Эффективность
                else if (choose_pos == 1) {
                    system("cls");

                    int choose_pos;
                    int iKey;
                    int sub_sub_exit_flag;
                    COORD cursorPos;

                    sub_sub_exit_flag = 0;
                    choose_pos = 0;

                    while (!sub_sub_exit_flag) {
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

                            if (choose_pos < 0) { choose_pos = EFFICIENCY_MENU_SIZE - 1; }
                            if (choose_pos > EFFICIENCY_MENU_SIZE - 1) { choose_pos = 0; }

                            for (int i = 0; i < EFFICIENCY_MENU_SIZE; i++) {
                                cursorPos = (COORD){ 3, i };
                                SetConsoleCursorPosition(hStdOut, cursorPos);
                                printf("%s \n", efficiency_menu[i]);
                            }

                            cursorPos = (COORD){ 0, choose_pos };
                            SetConsoleCursorPosition(hStdOut, cursorPos);
                            printf("<<", iKey);
                            cursorPos = (COORD){ strlen(efficiency_menu[choose_pos]) + 3 + 1, choose_pos };
                            SetConsoleCursorPosition(hStdOut, cursorPos);
                            printf(">>");

                            iKey = _getch();
                        }
                        if (choose_pos == 0) {
                            system("cls");


                            system("pause");
                        }
                        else if (choose_pos == 1) {
                            system("cls");

                            printf("in development\n");

                            system("pause");
                        }
                        else if (choose_pos == 2) {
                            system("cls");

                            printf("in development\n");

                            system("pause");
                        }
                        else if (choose_pos == 3) {
                            system("cls");

                            printf("in development\n");

                            system("pause");
                        }
                        else if (choose_pos == 4) {
                            system("cls");
                            printf("Enter size of array");
                            scanf_s("%d", &len);

                            system("pause");
                        }
                        else if (choose_pos == 5) {
                            sub_sub_exit_flag = 1;
                        }
                    }
                }
                else if (choose_pos == 2) {
                    sub_exit_flag = 1;
                }
            }
        }
    //Алгоритмы
        else if (choose_pos == 1) {
            system("cls");
            int choose_pos;
            int iKey;
            int sub_exit_flag;
            COORD cursorPos;

            sub_exit_flag = 0;
            choose_pos = 0;

            while (!sub_exit_flag) {
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

                    if (choose_pos < 0) { choose_pos = ALGORITHMS_MENU_SIZE - 1; }
                    if (choose_pos > ALGORITHMS_MENU_SIZE - 1) { choose_pos = 0; }

                    for (int i = 0; i < ALGORITHMS_MENU_SIZE; i++) {
                        cursorPos = (COORD){ 3, i };
                        SetConsoleCursorPosition(hStdOut, cursorPos);
                        printf("%s \n", algorithms_menu[i]);
                    }

                    cursorPos = (COORD){ 0, choose_pos };
                    SetConsoleCursorPosition(hStdOut, cursorPos);
                    printf("<<", iKey);
                    cursorPos = (COORD){ strlen(algorithms_menu[choose_pos]) + 3 + 1, choose_pos };
                    SetConsoleCursorPosition(hStdOut, cursorPos);
                    printf(">>");

                    iKey = _getch();
                }
    //Поиск
                if (choose_pos == 0) {
                    system("cls");

                    int choose_pos;
                    int iKey;
                    int sub_sub_exit_flag;
                    COORD cursorPos;

                    sub_sub_exit_flag = 0;
                    choose_pos = 0;

                    while (!sub_sub_exit_flag) {
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

                            if (choose_pos < 0) { choose_pos = SEARHC_MENU_SIZE - 1; }
                            if (choose_pos > SEARHC_MENU_SIZE - 1) { choose_pos = 0; }

                            for (int i = 0; i < SEARHC_MENU_SIZE; i++) {
                                cursorPos = (COORD){ 3, i };
                                SetConsoleCursorPosition(hStdOut, cursorPos);
                                printf("%s \n", search_menu[i]);
                            }

                            cursorPos = (COORD){ 0, choose_pos };
                            SetConsoleCursorPosition(hStdOut, cursorPos);
                            printf("<<", iKey);
                            cursorPos = (COORD){ strlen(search_menu[choose_pos]) + 3 + 1, choose_pos };
                            SetConsoleCursorPosition(hStdOut, cursorPos);
                            printf(">>");

                            iKey = _getch();
                        }
                        if (choose_pos == 0) {
                            system("cls");
                            int desired_value;
                            printf("Введите желаемое значение: ");
                            scanf_s("%d", &desired_value);
                            naive_search(desired_value, mass, len);
                            system("pause");
                        }
                        else if (choose_pos == 1) {
                            system("cls");

                            binary_search(mass, len);

                            system("pause");
                        }
                        else if (choose_pos == 2) {
                            sub_sub_exit_flag = 1;
                        }
                    }
                }
    //Сортировка
                else if (choose_pos == 1) {
                    system("cls");

                    int choose_pos;
                    int iKey;
                    int sub_sub_exit_flag;
                    COORD cursorPos;

                    sub_sub_exit_flag = 0;
                    choose_pos = 0;

                    while (!sub_sub_exit_flag) {
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

                            if (choose_pos < 0) { choose_pos = SORT_MENU_SIZE - 1; }
                            if (choose_pos > SORT_MENU_SIZE - 1) { choose_pos = 0; }

                            for (int i = 0; i < SORT_MENU_SIZE; i++) {
                                cursorPos = (COORD){ 3, i };
                                SetConsoleCursorPosition(hStdOut, cursorPos);
                                printf("%s \n", sort_menu[i]);
                            }

                            cursorPos = (COORD){ 0, choose_pos };
                            SetConsoleCursorPosition(hStdOut, cursorPos);
                            printf("<<", iKey);
                            cursorPos = (COORD){ strlen(sort_menu[choose_pos]) + 3 + 1, choose_pos };
                            SetConsoleCursorPosition(hStdOut, cursorPos);
                            printf(">>");

                            iKey = _getch();
                        }
                         if (choose_pos == 0) {
                        system("cls");

                        bub_sort(mass, len);

                        system("pause");
                        }
                        else if (choose_pos == 1) {
                            system("cls");
                           
                            fast_sort(mass, 0, len-1);
                           
                            system("pause");
                        }
                        else if (choose_pos == 2) {
                            system("cls");

                            shell_sort(mass, len);

                            system("pause");
                        }
                        else if (choose_pos == 3) {
                            system("cls");

                            sheker_sort(mass, len);

                            system("pause");
                        }
                        else if (choose_pos == 4) {
                            sub_sub_exit_flag = 1;
                        }
                    }
                }
                else if (choose_pos == 2) {
                    sub_exit_flag = 1;
                }
            }
        }
    //Настройки
        else if (choose_pos == 2) {
            system("cls");
            int choose_pos;
            int iKey;
            int sub_exit_flag;
            COORD cursorPos;

            sub_exit_flag = 0;
            choose_pos = 0;

            while (!sub_exit_flag) {
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

                    if (choose_pos < 0) { choose_pos = SETTINGS_MENU_SIZE - 1; }
                    if (choose_pos > SETTINGS_MENU_SIZE - 1) { choose_pos = 0; }

                    for (int i = 0; i < SETTINGS_MENU_SIZE; i++) {
                        cursorPos = (COORD){ 3, i };
                        SetConsoleCursorPosition(hStdOut, cursorPos);
                        printf("%s \n", settings_menu[i]);
                    }

                    cursorPos = (COORD){ 0, choose_pos };
                    SetConsoleCursorPosition(hStdOut, cursorPos);
                    printf("<<", iKey);
                    cursorPos = (COORD){ strlen(settings_menu[choose_pos]) + 3 + 1, choose_pos };
                    SetConsoleCursorPosition(hStdOut, cursorPos);
                    printf(">>");

                    iKey = _getch();
                }
    //Задать массив
                if (choose_pos == 0) {
                    system("cls");

                    int choose_pos;
                    int iKey;
                    int sub_sub_exit_flag;
                    COORD cursorPos;

                    sub_sub_exit_flag = 0;
                    choose_pos = 0;

                    while (!sub_sub_exit_flag) {
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

                            if (choose_pos < 0) { choose_pos = SET_ARRAY_MENU_SIZE - 1; }
                            if (choose_pos > SET_ARRAY_MENU_SIZE - 1) { choose_pos = 0; }

                            for (int i = 0; i < SET_ARRAY_MENU_SIZE; i++) {
                                cursorPos = (COORD){ 3, i };
                                SetConsoleCursorPosition(hStdOut, cursorPos);
                                printf("%s \n", set_array_menu[i]);
                            }

                            cursorPos = (COORD){ 0, choose_pos };
                            SetConsoleCursorPosition(hStdOut, cursorPos);
                            printf("<<", iKey);
                            cursorPos = (COORD){ strlen(set_array_menu[choose_pos]) + 3 + 1, choose_pos };
                            SetConsoleCursorPosition(hStdOut, cursorPos);
                            printf(">>");

                            iKey = _getch();
                        }
                        if (choose_pos == 0) {
                            system("cls");
                            printf("Введите длину массива: ");
                            scanf_s("%d", &len);
                            system("cls");
                            manually_generaye_mass(len, mass);
                            system("pause");
                        }
                        else if (choose_pos == 1) {
                            system("cls");

                            printf("Введите максимальное значение, минимальное значение, кол-во элементов массива: ");
                            scanf_s("%d %d %d", &max_value, &min_value, &len);
                            mass = (int*)malloc(sizeof(int) * len);
                            random_generate_mass(max_value, min_value, len, mass);
                            system("pause");
                        }
                        else if (choose_pos == 2) {
                            system("cls");
                            strcpy_s(filepath, sizeof filepath, fold);
                            strncat_s(filepath, 100, filename, 100);
                            FILE* input_file = NULL;
                            errno_t error;
                            int size;
                            error = fopen_s(&input_file, filepath, "r+"); // r – read, w - write
                            if (input_file == NULL) {
                                printf("Error in input file. Error %d\n", error);
                            }
                            else {
                                // для ввода использовали бы fprintf(input_file, "0");

                                if (fscanf_s(input_file, "%d", &size) != 1) {
                                    printf("Error\n");
                                    return 0;
                                }
                                len = size;
                                mass = (int*)malloc(sizeof(int) * size);
                                for (int i = 0; i < size; i++) {
                                    if (fscanf_s(input_file, "%d", &mass[i]) != 1) {
                                        printf("Error\n");
                                        return 0;
                                    }
                                }
                                fclose(input_file);
                            }

                            system("pause");


                        }
                        else if (choose_pos == 3) {
                            sub_sub_exit_flag = 1;
                        }
                    }
                }
    //Показать текущий массив
                else if (choose_pos == 1) {
                    system("cls");
                    print_mass(mass, len);
                    system("pause");
                }
    //Изменить путь до рабочей директории
                else if (choose_pos == 2) {
                    system("cls");
                    printf("Введите новую директорию: ");
                    gets(fold);
                    system("pause");
                }
                else if (choose_pos == 3) {
                    sub_exit_flag = 1;
                }
            }
        }
        else if (choose_pos == 3) {
            exit_flag = 1;
        }

        system("cls");
    }
    system("pause");
    return 0;
}