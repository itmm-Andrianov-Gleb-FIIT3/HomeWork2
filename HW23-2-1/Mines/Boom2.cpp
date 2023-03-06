#include <iostream>
#include <windows.h>
#include <time.h>
#include <stdio.h>
using namespace std;
//  1
void show_of_mines()
{
    cout << "* ";
}
void print_array_2D(int** Playing_field, bool** open, const int SIZE)
{
    char strLetters[30] = { "ABCDEFGHFGHIJKLMNOPQRSTUVWXYZ" };
    cout << " ";
    for (int i = 0; i < SIZE; i++){
        cout << " " << strLetters[i];
    }
    cout << endl;

    for (int x = 0; x < SIZE; x++){
        if (x < 10) 
            cout << x << " ";
        else        
            cout << x << "";

        for (int y = 0; y < SIZE; y++){

            if (open[x][y]){

                switch (Playing_field[x][y]){

                case -1:
                    show_of_mines();
                    break;

                case 0:
                    cout << "* ";
                    break;

                default:
                    cout << Playing_field[x][y] << " ";
                }
            }
            else{
                cout << "X ";
            }
        }
        cout << endl;
    }
}

// провер¤ет ¤чейку на пустоту (true), выход за пределы массива возвращает false
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
// открытие поля в точке попадания
void clean(int** Playing_field, bool** open, int i, int j, const int SIZE)
{   // проверим на выход за пределы массива
    if ((i >= 0) && (i < SIZE))
    {
        if ((j >= 0) && (j < SIZE))
        {   // проверим, не было ли открыто поле раньше
            if (!open[i][j])
            {
                open[i][j] = true;  //откроем
                // если поле пустое (=0), просто пооткрываем всех его соседей
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
                // если не пустое (!=0) открываем только пустых (=0) соседей
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

// проверка ячейки на мину ; выход за пределы возвращает false
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

// в случае проигрыша эта функциz откроет все мины
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

void final(bool loser, int** Playing_field, bool** open, const int SIZE)
{
    system("cls");
    print_array_2D(Playing_field, open, SIZE);
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

void inputSize(int& size)   //запрос на ввод колиство элементов массива
{

    while (true)
    {
        cout << "ВВЕДИТЕ РАЗМЕР ПОЛЯ:" << endl << endl;
        cin >> size;
        if (cin.fail())
        {
            cout << "ОШИБКА, ВВЕДИТЕ МЕНЬШЕЕ ЗНАЧЕНИЕ" << endl;
            cin.clear();
            while (cin.get() != '\n');
        }
        else if (size > 0) break;
    }
}

//  2
void rules()
{
    system("cls");
    cout << "\t\t\t\t\t\tСАПЕР: ПРАВИЛА И ОБЩИЕ СВЕДЕНИЯ" << endl << endl <<
        endl << endl;
    cout << " Начните с открытия одной ячейки." << endl;
    cout << " Если в ячейке указано число, оно показывает, сколько мин скрыто в восьми ячейках вокруг данной. Это число помогает понять, где находятся безопасные ячейки."
        << endl;
    cout << " Если рядом с открытой ячейкой есть пустая ячейка, то она откроется автоматически."
        << endl;
    cout << " Если вы открыли ячейку с миной, то игра проиграна." << endl;
    cout << " Игра продолжается до тех пор, пока вы не откроете все не заминированные ячейки."
        << endl << endl << endl;
    cout << endl << endl << endl << endl << endl << endl;
}


#include "conio.h"
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
        inputSize(SIZE);
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
        // заполняем массив поля минами
        for (int c = 0; c < SIZE - 1; c++)
        {
            do
            {
                i = rand() % SIZE;
                j = rand() % SIZE;
            } while (Playing_field[i][j] != 0);

            Playing_field[i][j] = -1;
        }
        // заполняем массив поля цифрами
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
            print_array_2D(Playing_field, open, SIZE);
            cout << endl;


            char input_coordinate[4]{ '\0' };
            cout << "Введите координаты: ";
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
                std::cout << "Неправильный ввод!"; _getch();
                continue;
            }

            i = input_coordinate[1] - 48;
            if (i < 0 && 9 < i)
            {
                std::cout << "Неправильный ввод!";
                std::cout << i;
                _getch();
                continue;
            }

            //  проверка всех восемь окрестных полей на пустые клетки
            clean(Playing_field, open, i, j, SIZE);

            if (mine(Playing_field, i, j, SIZE))
            {
                openmines(Playing_field, open, SIZE);
                final(true, Playing_field, open, SIZE);
                break;
            }
            if (win_or_lose(Playing_field, open, SIZE))
            {
                final(false, Playing_field, open, SIZE);
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

        default:
            cout << "Ошибка, попробуйте еще раз, нажмите кнопку <Enter>, чтобы повторить попытку"
                << endl;
            break;
        }
        system("pause");
    }
    return 0;
}