#include <iostream>
#include <stdio.h>
#include <locale.h>
#include "conio.h"
#include <time.h>


class Student {


public:

	std::string firstName;
	std::string secondName;
	std::string lastName;

	int ID;

	float MM;

	std::string Bud;

	std::string Paid;


	   int FIO() {
	      std::cout << "������� ������� ��������";
		  std::cin >> firstName;
		  std::cout << "������� ��� ��������";
		  std::cin >> secondName;
		  std::cout << "������� �������� ��������";
		  std::cin >> lastName;
       }

	   int Info() {
		   std::cout << "������� ������� ���� ��������";
		   std::cin >> MM;
		   std::cout << "�������� �� ����������� �������?";
		   std::cin >> Bud;
		   std::cout << "�������� �� ��������� �������?";
		   std::cin >> Paid;
	   }

	   int Id() {
		   ID = 11111111;


	   }

};

int main() {
	setlocale(LC_ALL, "rus");
	std::cout << "\n\n\n\t\t\t\t\t\t ����� ����������.";

	while (true) {
		int n = 1;
		Student n;
	}
}