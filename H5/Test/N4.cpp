#include<iostream>
#include<string>

//                                                    Задание 4:
struct Time {    //Время приёма пищи.
	int hours;
	int minutes;
	int seconds;
};
struct FIO {      //ФИО членов семьи.
	std::string last_name;
	std::string first_name;
	std::string patronymic;
};

int main() {
	struct Time* meals;
	struct Time breakfast = { 7, 30, 00 }, lunch = { 12, 45, 00 }, dinner = { 18, 00, 00 };

	meals = new struct Time[3];

	meals[0].hours = breakfast.hours;
	meals[0].minutes = breakfast.minutes;
	meals[0].seconds = breakfast.seconds;

	meals[1].hours = lunch.hours;
	meals[1].minutes = lunch.minutes;
	meals[1].seconds = lunch.seconds;

	meals[2].hours = dinner.hours;
	meals[2].minutes = dinner.minutes;
	meals[2].seconds = dinner.seconds;

	struct FIO* family;
	struct FIO  mother = { "Ivanova", "Ekaterina", "Albertovna" }, father = { "Ivanov", "Andrey", "Poncratovich" }, 
				brother = { "Ivanov", "Artem", "Andreyevich" }, myself = { "Ivanov","Ivan","Ivanovich" };

	family = new struct FIO[4];

	family[0].last_name = mother.last_name;
	family[0].first_name = mother.first_name;
	family[0].patronymic = mother.patronymic;

	family[1].last_name = father.last_name;
	family[1].first_name = father.first_name;
	family[1].patronymic = father.patronymic;

	family[2].last_name = brother.last_name;
	family[2].first_name = brother.first_name;
	family[2].patronymic = brother.patronymic;

	family[3].last_name = myself.last_name;
	family[3].first_name = myself.first_name;
	family[3].patronymic = myself.patronymic;

	return 0;
}