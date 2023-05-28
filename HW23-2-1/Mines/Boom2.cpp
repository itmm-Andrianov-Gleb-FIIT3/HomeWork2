#include <iostream>
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include "conio.h"
using namespace std;

// Создание игрового поля
void print_field(int** Playing_field, bool** open, const int SIZE)
{
    cout << " ";
    char strLetters[27] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
    cout << "  ";
    for (int i = 0; i < SIZE; i++) {
        cout << " " << strLetters[i];
    }
    cout << endl;

    for (int x = 0; x < SIZE; x++) {
        if (x < 10)
            cout << " " << x << "  ";
        else
            cout << x << "  ";

        for (int y = 0; y < SIZE; y++) {

            if (open[x][y]) {

                switch (Playing_field[x][y]) {

                case -1:
                    cout << "* ";
                    break;

                case 0:
                    cout << "o ";
                    break;

                default:
                    cout << Playing_field[x][y] << " ";
                }
            }
            else {
                cout << "# ";
            }
        }
        cout << endl;
    }
}
// Проверка ячейки на пустоту
bool empty(int** Playing_field, int i, int j, const int SIZE)
{
    if ((i >= 0) && (i < SIZE))
    {
        if ((j >= 0) && (j < SIZE))
        {
            if (Playing_field[i][j] == 0)
                return true;
        }
    }
    return false;
}
// Открытие поля в точке попадания
void clean(int** Playing_field, bool** open, int i, int j, const int SIZE)
{   // проверим на выход за пределы массива
    if ((i >= 0) && (i < SIZE))
    {
        if ((j >= 0) && (j < SIZE))
        {   // Проверим, не было ли открыто поле раньше
            if (!open[i][j])
            {
                open[i][j] = true;  //откроем
                // Если поле пустое (=0), просто открываем всех его соседей
                if (Playing_field[i][j] == 0)
                {
                    clean(Playing_field, open, i - 1, j - 1, SIZE);
                    clean(Playing_field, open, i - 1, j, SIZE);
                    clean(Playing_field, open, i - 1, j + 1, SIZE);
                    clean(Playing_field, open, i, j - 1, SIZE);
                    clean(Playing_field, open, i, j + 1, SIZE);
                    clean(Playing_field, open, i + 1, j - 1, SIZE);
                    clean(Playing_field, open, i + 1, j, SIZE);
                    clean(Playing_field, open, i + 1, j + 1, SIZE);
                }
                // Если не пустое, то открываем только пустых соседей
                else
                {
                    if (empty(Playing_field, i - 1, j - 1, SIZE)) clean(Playing_field, open,
                        i - 1, j - 1, SIZE);
                    if (empty(Playing_field, i - 1, j, SIZE)) clean(Playing_field, open, i - 1, j,
                        SIZE);
                    if (empty(Playing_field, i - 1, j + 1, SIZE)) clean(Playing_field, open, i - 1,
                        j + 1, SIZE);
                    if (empty(Playing_field, i, j - 1, SIZE)) clean(Playing_field, open, i, j - 1,
                        SIZE);
                    if (empty(Playing_field, i, j + 1, SIZE)) clean(Playing_field, open, i, j + 1,
                        SIZE);
                    if (empty(Playing_field, i + 1, j - 1, SIZE)) clean(Playing_field, open, i + 1,
                        j - 1, SIZE);
                    if (empty(Playing_field, i + 1, j, SIZE)) clean(Playing_field, open, i + 1, j,
                        SIZE);
                    if (empty(Playing_field, i + 1, j + 1, SIZE)) clean(Playing_field, open, i + 1,
                        j + 1, SIZE);
                }
            }
        }
    }
}
// Проверка ячейки на мину ; выход за пределы возвращает false
bool mine(int** Playing_field, int i, int j, const int SIZE)
{
    if ((i >= 0) && (i < SIZE))
    {
        if ((j >= 0) && (j < SIZE))
        {
            if (Playing_field[i][j] == -1)
                return true;
        }
    }
    return false;
}

void empty_play_space(int** Playing_field, bool** open, const int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (Playing_field[i][j] == -1)
            {
                open[i][j] = true;
            }
        }
    }
}

bool win_or_lose(int** Playing_field, bool** open, const int SIZE)
{
    for (int x = 0; x < SIZE; x++)
    {
        for (int y = 0; y < SIZE; y++)
        {
            if ((Playing_field[x][y] != -1) && (!open[x][y]))
                return false;
        }
    }
    return true;
}
// В случае проигрыша, открывает все мины
void openmines(int** Playing_field, bool** open, const int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (Playing_field[i][j] == -1) open[i][j] = true;
        }
    }
}
// Финальный результат
void finale(bool loser, int** Playing_field, bool** open, const int SIZE)
{
    system("cls");
    print_field(Playing_field, open, SIZE);
    if (loser)
    {
        cout << endl;
        cout << "Вы проиграли!";
    }
    else
    {
        cout << endl;
        cout << "Вы выиграли!";
    }
    cout << endl;
}
// Ввод размера поля
void inputSIZE(int& size)   //запрос на ввод колиство элементов массива
{

    while (true)
    {
        cout << "ВВЕДИТЕ РАЗМЕР ПОЛЯ (ДО 27) :" << endl << endl;
        cin >> size;
        if (size >= 27)
        {
            cout << "ОШИБКА, ВВЕДИТЕ МЕНЬШЕЕ ЗНАЧЕНИЕ" << endl;
            cin.clear();
            while (cin.get() != '\n');
        }
        else if (size > 0) break;
    }
}


// Правила игры
void rules()
{
    system("cls");
    cout << "\t\t\t\t\t\tСАПЕР: ПРАВИЛА ИГРЫ" << endl << endl <<
        endl << endl;
    cout << " Игровой процесс заключается в открывании ячеек." << endl;
    cout << " Для введения координат удара используйте поле ''Введите координаты:'', указывая сначало букву удара, затем номер." << endl;
    cout << " Если вы хотите ввести число от 0 до 9, вам необходимо поставить  перед ним 0(Ноль) (Пример: f01)."
        << endl;
    cout << " Если в ячейке указано число, оно показывает, сколько мин скрыто в восьми ячейках вокруг онной. Это число помогает понять, где находятся безопасные ячейки."
        << endl;
    cout << " Если рядом с открытой ячейкой есть пустая ячейка, то она откроется автоматически."
        << endl;
    cout << " Если вы открыли ячейку с миной, то игра засчитывает вам проигрыш." << endl;
    cout << " Игра продолжается до тех пор, пока вы не откроете все не заминированные ячейки."
        << endl << endl << endl;

    cout << endl << endl << endl << endl << endl << endl;
}


// Меню
int main()
{
    srand((unsigned int)time(NULL));
    setlocale(LC_ALL, "Russian");

    char choice{};
    while (true)
    {
        system("cls");
        cout << "1 - Играть " << endl;
        cout << "2 - ПРАВИЛА ИГРЫ << САПЕР >> " << endl;
        cout << "0 - ВЫХОД" << endl << endl << endl;
        cout << "ВАШ ВЫБОР:" << endl << endl;
        cin >> choice;
        cout << endl;

        cin.ignore(100, '\n');
        if (choice == '0') break;
        switch (choice)
        {
        case '1':
        {   int SIZE = 0;
        inputSIZE(SIZE);
        int** Playing_field = new int* [SIZE];
        bool** open = new bool* [SIZE];

        for (int i = 0; i < SIZE; i++)
        {
            *(Playing_field + i) = new int[SIZE];
        }
        for (int i = 0; i < SIZE; i++)
        {
            *(open + i) = new bool[SIZE];
        }


        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                Playing_field[i][j] = 0;
                open[i][j] = false;
            }
        }

        int i, j;
        int B_SIZE;
        B_SIZE = (2 * (SIZE - 2));
        // Заполняем массив поля минами
        for (int c = 0; c < B_SIZE; c++)
        {
            do
            {
                i = rand() % SIZE;
                j = rand() % SIZE;
            } while (Playing_field[i][j] != 0);

            Playing_field[i][j] = -1;
        }
        // Заполняем массив поля цифрами
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (Playing_field[i][j] != -1)
                {
                    int quantity{};
                    if (mine(Playing_field, i - 1, j - 1, SIZE)) quantity++;
                    if (mine(Playing_field, i - 1, j, SIZE)) quantity++;
                    if (mine(Playing_field, i - 1, j + 1, SIZE)) quantity++;
                    if (mine(Playing_field, i, j - 1, SIZE)) quantity++;
                    if (mine(Playing_field, i, j + 1, SIZE)) quantity++;
                    if (mine(Playing_field, i + 1, j - 1, SIZE)) quantity++;
                    if (mine(Playing_field, i + 1, j, SIZE)) quantity++;
                    if (mine(Playing_field, i + 1, j + 1, SIZE)) quantity++;
                    Playing_field[i][j] = quantity;
                }
            }
        }
        while (true)
        {
            system("cls");
            cout << endl << endl;
            print_field(Playing_field, open, SIZE);
            cout << endl;


            char input_coordinate[4]{ '\0' };
            cout << " Введите координаты: ";
            cin.clear();
            cin.ignore(100, '\n');
            cin.get(input_coordinate, 4);


            if ((input_coordinate[0] >= 65) && (input_coordinate[0] <= 90))
            {
                j = input_coordinate[0] - 65; // буква в промежутке от A до Z
            }
            else if ((input_coordinate[0] >= 97) && (input_coordinate[0] <= 122))
            {
                j = input_coordinate[0] - 97; // буква в промежутке от a до z
            }
            else
            {
                std::cout << " Неправильный ввод!";
                _getch();
                continue;
            }

            i = (input_coordinate[1] - 48) * 10 + input_coordinate[2] - 48;
            if (i < 0 && SIZE <= i)
            {
                std::cout << " Неправильный ввод!";
                std::cout << i;
                _getch();
                continue;
            }

            //  Проверка всех восьми окрестных полей на пустые клетки
            clean(Playing_field, open, i, j, SIZE);

            if (mine(Playing_field, i, j, SIZE))
            {
                openmines(Playing_field, open, SIZE);
                finale(true, Playing_field, open, SIZE);
                break;
            }
            if (win_or_lose(Playing_field, open, SIZE))
            {
                finale(false, Playing_field, open, SIZE);
                break;
            }
        }

        for (int i = 0; i < SIZE; i++)
        {
            delete[] * (Playing_field + i);
        }
        delete Playing_field;
        for (int i = 0; i < SIZE; i++)
        {
            delete[] * (open + i);
        }
        delete open;
        }
        break;

        case '2':
        {   rules();
        }
        break;
        }
        system("pause");
    }
    return 0;
}