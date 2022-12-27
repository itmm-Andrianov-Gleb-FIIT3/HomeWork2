#include<iostream>
#include<string>

//                                              Задание 5:

struct Dimension {
	int height;
	int depth;
	int width;
};

void input(struct Dimension* sizes) {
	std::cout << "Input height: ";
	std::cin >> (sizes->height);
	std::cout << "Input depth: ";
	std::cin >> (sizes->depth);
	std::cout << "Input width: ";
	std::cin >> (sizes->width);
}

struct Date {
	int day;
	int month;
	int year;
};

struct Date createDate(int d, int m, int y) {
	struct Date new_date;
	new_date.day = d;
	new_date.month = m;
	new_date.year = y;
	return new_date;
}

struct BookInInt { 
	std::string autors;
	std::string name;
	std::string publisher;
};

void createDate(struct BookInInt* new_date) {
	std::string autors, name, publisher;
	std::cout << "Input autors: ";
	std::cin >> autors;
	std::cout << "Input name: ";
	std::cin >> name;
	std::cout << "Input publisher: ";
	std::cin >> publisher;
	new_date->autors = autors;
	new_date->name = name;
	new_date->publisher = publisher;
}

struct FIO {
	std::string last_name;
	std::string first_name;
	std::string patronymic;
};

struct FIO createDate(struct FIO date) {
	struct FIO new_date;
	new_date.last_name = date.last_name;
	new_date.first_name = date.first_name;
	new_date.patronymic = date.patronymic;
	return new_date;
}
