#include<iostream>
#include<string>
#include<windows.h>

//                                    Задание 3:

//                                    1 часть


//Номер 1
struct Date {
	int day;
	int month;
	int year;
};
int main() {
	struct Data B_day = { 9, 9, 1984 };
	return 0;
}

//Номер 2
struct FIO {   
	std::string last_name;
	std::string first_name;
	std::string patronymic;
};
int main() {
	struct FIO Ivan2 = { "Ivanov","Ivan","Ivanovich"};
	return 0;
}

//Номер 3

struct Body { 
	int height;
	int weight;
};

int main() {
	struct Body IG = { 200, 85 };
	return 0;
}


//                                2 часть
struct Patient {
	struct FIO name;
	struct Data B_day;
	struct Data E_day;
	struct Body size;
	int age;
	std::string diagnosis;
};

struct Data {
	int day;
	int month;
	int year;
};

struct Body {
	int height;
	int weight;
};

int main() {
	struct FIO name = { "Ivanov","Ivan","Ivanovich" };
	struct Data B_day = { 9, 9, 1984 };
	struct Data E_day = { 16, 7, 2021 };
	struct Body size = { 200, 85 };
	int age = 37;
	std::string diagnosis = "Covid-19";
	return 0;
}