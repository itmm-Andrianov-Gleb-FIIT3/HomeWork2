#include<iostream>
#include<string>
#include<windows.h>


//                                  Задание 1:
// 
//                                   1 часть
// 
//Габариты(мебели, например, шкафа) – это 3 целых числа(высота, глубина, ширина).
// 
//Книга в интернет магазине – это 3 строки(автор(ы), название, издательство), 3 целых числа(год издания, количество страниц, артикул).
// 
//БЖУК – это 3 целых числа(белки, жиры, углеводы), вещественное число(калории).
// 
//ФИО – это 3 строки(фамилия, имя, отчество).
// 
//Тетрадь – это 1 целое число(кол-во страниц), 2 строки(вид страниц(в клетку или линейку),формат страниц(A5,A4 и т.д.)).
// 
//Время – это 3 целых числа(часы, минуты, секунды).
// 
//Джинсы – это 1 целое число (размер джинс) и 2 строки (страна производитель, марка).
// 
//Телевизор – это 3 строки(название, производитель, страна производителя), 3 целых числа(диагональ экрана в дюймах, разрешение экрана,яркость экрана в кд/м2).
// 
//Параметры тела – это 2 целых числа(рост в сантиметрах, масса в килограммах).
// 
//                                   2 часть
// 
//Работник – это ФИО (фамилия, имя и отчество работника, описанные через структуру уже реализованную нами - ФИО), дата(дата рождения), вещественное число(оклад),
//        целое число(уникальный номер / номер личного дела), строка(должность).
// 
//Блюдо(кулинарное) – это БЖУК(белки, жиры, углеводы и калории, описанные через структуру уже реализованную нами - БЖУК), N строк(ингридиенты), N целых чисел(граммовки под каждой строкой).
// 
//Студент – это ФИО (фамилия, имя и отчество работника, описанные через структуру уже реализованную нами - ФИО), дата 1(дата рождения), дата 2(дата поступления),
//        5 строк(Учебное подразделение, Направление подготовки, Квалификация, Форма обучения, Группа), 2 целых числа(курс, уникальный номер / номер личного дела).
// 
//Пациент – это ФИО (фамилия, имя и отчество работника, описанные через структуру уже реализованную нами - ФИО), дата 1(дата рождения), дата 2(дата поступления),
//	      Параметры тела(рост в сантиметрах, масса в килограммах, описанные через структуру уже реализованную нами - Параметры тела), целое число(возраст), строка(диагноз).




//                                 Задание 2: 
// 
//                                  1 часть
	
	struct Data  {     //Дата
		int day;
		int month;
		int year;
	};
	
	struct Dimension { //Габариты
		int height;
		int depth;
		int width;
	};

	struct BookInInt { //Книга в интернет магазине
		std::string autors;
		std::string name;
		std::string publisher;
	};

	struct PFCC {     //БЖУК
		int proteins;
		int fats;
		int carbohydrates;
		float calories;
	};

	struct FIO {      //ФИО
		std::string last_name;
		std::string first_name;
		std::string patronymic;
	};

	struct Notebook { //Тетрадь
		int pages;
		std::string type;
		std::string A_kind;
	};

	struct Time {    //Время
		int hours;
		int minutes;
		int seconds;
	};

	struct Jeans {  //Джинсы
		int waist;
		std::string country;
		std::string brand;
	};

	struct TV {   //Телевизор
		std::string name;
		std::string maker;
		std::string coutry;
		int diagonal;
		int resolution;
		int bright;
	};

	struct Body { //Параметры тела
		int height;
		int weight;
	};

	
	//                              2 часть
	
	
	struct Worker {  //Работник
		struct FIO name;
		struct Data B_day;
		float salary;
		int ID;
		std::string post;
	};

	struct Food {  //Блюдо(кулинарное)
		struct PFCC nutritional_value;
		std::string ingr;
		int gramm;
	};

	struct Student {
		struct FIO name;
		struct Data B_day;
		struct Data E_day;
		std::string Training_unit;
		std::string Direction_of_training;
		std::string Qualification;
		std::string Form_of_training;
		std::string Class;
		int Course;
		int ID;
	};

	struct Patient {
		struct FIO name;
		struct Data B_day;
		struct Data E_day;
		struct Body size;
		int age;
		std::string diagnosis;
	};
