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
    for (int i = 0; i < SIZE; i++) {
        cout << " " << strLetters[i];
    }
    cout << endl;

    for (int x = 0; x < SIZE; x++) {
        if (x < 10)
            cout << x << " ";
        else
            cout << x << "";

        for (int y = 0; y < SIZE; y++) {

            if (open[x][y]) {

                switch (Playing_field[x][y]) {

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
            else {
                cout << "X ";
            }
        }
        cout << endl;
    }
}

// ��������� ������ �� ������� (true), ����� �� ������� ������� ���������� false
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
// �������� ���� � ����� ���������
void clean(int** Playing_field, bool** open, int i, int j, const int SIZE)
{   // �������� �� ����� �� ������� �������
    if ((i >= 0) && (i < SIZE))
    {
        if ((j >= 0) && (j < SIZE))
        {   // ��������, �� ���� �� ������� ���� ������
            if (!open[i][j])
            {
                open[i][j] = true;  //�������
                // ���� ���� ������ (=0), ������ ����������� ���� ��� �������
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
                // ���� �� ������ (!=0) ��������� ������ ������ (=0) �������
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

// �������� ������ �� ���� ; ����� �� ������� ���������� false
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
// ��������� ������ ���� ������
void mine_stacker(int** Playing_field, int i, int j, const int SIZE) {
    for (int c = 0; c < SIZE - 1; c++) {
        do {
            i = rand() % SIZE;
            j = rand() % SIZE;
        } while (Playing_field[i][j] != 0);

        Playing_field[i][j] = -1;
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

// � ������ ��������� ��� ������� ������� ��� ����
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
        cout << "�� ���������!";
    }
    else
    {
        cout << endl;
        cout << "�� ��������!";
    }
    cout << endl;
}

void inputSize(int& size)   //������ �� ���� �������� ��������� �������
{

    while (true)
    {
        cout << "������� ������ ����:" << endl << endl;
        cin >> size;
        if (cin.fail())
        {
            cout << "������, ������� ������� ��������" << endl;
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
    cout << "\t\t\t\t\t\t�����: ������� � ����� ��������" << endl << endl <<
        endl << endl;
    cout << " ������� � �������� ����� ������." << endl;
    cout << " ���� � ������ ������� �����, ��� ����������, ������� ��� ������ � ������ ������� ������ ������. ��� ����� �������� ������, ��� ��������� ���������� ������."
        << endl;
    cout << " ���� ����� � �������� ������� ���� ������ ������, �� ��� ��������� �������������."
        << endl;
    cout << " ���� �� ������� ������ � �����, �� ���� ���������." << endl;
    cout << " ���� ������������ �� ��� ���, ���� �� �� �������� ��� �� �������������� ������."
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
        cout << "1 - ������ " << endl;
        cout << "2 - ������� ���� << ����� >> " << endl;
        cout << "0 - �����" << endl << endl << endl;
        cout << "��� �����:" << endl << endl;
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
        // ��������� ������ ���� ������
        mine_stacker(Playing_field, i, j, SIZE);

        // ��������� ������ ���� �������
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
            cout << "������� ����������: ";
            cin.clear();
            cin.ignore(100, '\n');
            cin.get(input_coordinate, 4);


            if ((input_coordinate[0] >= 65) && (input_coordinate[0] <= 90))
            {
                j = input_coordinate[0] - 65; // ����� � ���������� �� A �� Z
            }
            else if ((input_coordinate[0] >= 97) && (input_coordinate[0] <= 122))
            {
                j = input_coordinate[0] - 97; // ����� � ���������� �� a �� z
            }
            else
            {
                std::cout << "������������ ����!"; _getch();
                continue;
            }

            i = input_coordinate[1] - 48;
            if (i < 0 && SIZE <= i)
            {
                std::cout << "������������ ����!";
                std::cout << i;
                _getch();
                continue;
            }

            //  �������� ���� ������ ��������� ����� �� ������ ������
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
            cout << "������, ���������� ��� ���, ������� ������ <Enter>, ����� ��������� �������"
                << endl;
            break;
        }
        system("pause");
    }
    return 0;
}