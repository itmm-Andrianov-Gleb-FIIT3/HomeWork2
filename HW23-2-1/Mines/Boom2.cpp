#include <iostream>
#include <windows.h>
#include <iomanip>
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
// открытие пол¤ в точке попадани¤
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

// проверка ¤чейки на мину ; выход за пределы возвращает false
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

// в случае проигрыша эта функци¤ откроет все мины
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
        cout << "¬џ ѕ–ќ»–јЋ»!";
        free(Playing_field);
    }
    else
    {
        cout << endl;
        cout << "¬џ ¬џ»√–јЋ»!";
        free(Playing_field);
    }
    cout << endl;
}

void inputSize(int& size)   //запрос на ввод колиство элементов массива
{

    while (true)
    {
        cout << "¬¬≈ƒ»“≈ –ј«ћ≈– ѕќЋя:" << endl << endl;
        cin >> size;
        if (cin.fail())
        {
            cout << "ќЎ»Ѕ ј, ¬¬≈ƒ»“≈ ћ≈Ќ№Ў≈≈ «Ќј„≈Ќ»≈" << endl;
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
    cout << "\t\t\t\t\t\t—јѕ≈–: ѕ–ј¬»Ћј » ќЅў»≈ —¬≈ƒ≈Ќ»я" << endl << endl <<
        endl << endl;
    cout << "  Ќачните с открыти¤ одной ¤чейки." << endl;
    cout << "  „исло в ¤чейке показывает, сколько мин скрыто вокруг данной ¤чейки. Ёто число поможет пон¤ть вам, где наход¤тс¤ безопасные ¤чейки, а где наход¤тс¤ бомбы."
        << endl;
    cout << "  ≈сли р¤дом с открытой ¤чейкой есть пуста¤ ¤чейка, то она откроетс¤ автоматически."
        << endl;
    cout << "  ≈сли вы открыли ¤чейку с миной, то игра проиграна." << endl;
    cout << "  ≈сли в ¤чейке указано число, оно показывает, сколько мин скрыто в восьми ¤чейках вокруг данной. Ёто число помогает пон¤ть, где наход¤тс¤ безопасные ¤чейки."
        << endl;
    cout << "  »гра продолжаетс¤ до тех пор, пока вы не откроете все не заминированные ¤чейки."
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
        cout << "1 - »√–ј“№ " << endl;
        cout << "2 - ѕ–ј¬»Ћј »√–џ << —јѕ≈– >> " << endl;
        cout << "0 - ¬џ’ќƒ" << endl << endl << endl;
        cout << "—ƒ≈Ћј…“≈ ¬јЎ ¬џЅќ–:" << endl << endl;
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
        // заполн¤ем массив пол¤ минами
        for (int c = 0; c < SIZE - 1; c++)
        {
            do
            {
                i = rand() % SIZE;
                j = rand() % SIZE;
            } while (Playing_field[i][j] != 0);

            Playing_field[i][j] = -1;
        }
        // заполн¤ем массив пол¤ цифрами
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
            cout << "¬ведите координаты: ";
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
                std::cout << "Ќеправильный ввод!"; _getch();
                continue;
            }

            i = input_coordinate[1] - 48;
            if (i < 0 && 9 < i)
            {
                std::cout << "Ќеправильный ввод!";
                std::cout << i;
                _getch();
                continue;
            }

            // далее провер¤ем все восемь окрестных полей на пустые клетки показываем некий кусок пол¤
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
            cout << "ќшибка, попробуйте еще раз, нажмите кнопку <Enter>, чтобы повторить попытку"
                << endl;
            break;
        }
        system("pause");
    }
    return 0;
}