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
	      std::cout << "Введите Фамилию студента";
		  std::cin >> firstName;
		  std::cout << "Введите Имя студента";
		  std::cin >> secondName;
		  std::cout << "Введите Отчество студента";
		  std::cin >> lastName;
       }

	   int Info() {
		   std::cout << "Введите средний балл студента";
		   std::cin >> MM;
		   std::cout << "Является ли бюджетником студент?";
		   std::cin >> Bud;
		   std::cout << "Получает ли степендию студент?";
		   std::cin >> Paid;
	   }

	   int Id() {
		   ID = 11111111;


	   }

};

int main() {
	setlocale(LC_ALL, "rus");
	std::cout << "\n\n\n\t\t\t\t\t\t Добро пожаловать.";

	while (true) {
		int n = 1;
		Student n;
	}
}