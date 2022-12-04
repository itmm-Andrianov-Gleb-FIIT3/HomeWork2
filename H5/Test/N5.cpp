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
