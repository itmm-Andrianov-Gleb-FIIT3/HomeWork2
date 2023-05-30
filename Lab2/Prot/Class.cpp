#include <iostream>
#include <stdio.h>
#include "conio.h"
#include <time.h>

class FIO {
    std::string firstName;
    std::string secondName;
    std::string lastName;
public:
    FIO(std::string, std::string, std::string);
    FIO(const FIO&);
    ~FIO() {}

    void setLastName(std::string);

    FIO& operator=(const FIO&);

    // для поисков и сортировки в лексикографическом порядке
    bool operator==(const FIO&) const;
    bool operator<(const FIO&) const;
    bool operator>(const FIO&) const;

    friend std::ostream& operator<<(std::ostream&, const FIO&);
    friend std::istream& operator>>(std::istream&, const FIO&);

private:
    void fix(); // приводит к маленьким буквами (иванов, Иванов и ИВАНОВ - одно и то же)
};

class DATE {
    int day;
    int month;
    int year;
public:
    DATE();                   // устанавливает сегодняшнюю дату
    DATE(std::string);
    DATE(int, int, int);
    DATE(const DATE&);
    ~DATE() {}

    DATE& operator=(const DATE&);

    // для поисков
    bool operator==(const DATE&) const;
    bool operator<(const DATE&) const;
    bool operator>(const DATE&) const;

    friend std::ostream& operator<<(std::ostream&, const DATE&);
    friend std::istream& operator>>(std::istream&, const DATE&);

private:
    bool check();   // проверяет корректность введенной даты
};

class Material{
    std::string Mat;
    std::string UM;
    float cost;
public:
    Material(std::string,std::string,float);
    Material(const Material&);
    Material() {}

    void setMatName(std::string);

    Material& operator=(const Material&);

    bool operator==(const Material&) const;
    bool operator<(const Material&) const;
    bool operator>(const Material&) const;

    friend std::ostream& operator<<(std::ostream&, const Material&);
    friend std::istream& operator>>(std::istream&, const Material&);

private:
    void fix();

};

class Phone {
    long int phone;
public:
    Phone();
    Phone(long int);
    Phone(const Phone&);
    ~Phone() {}
  
};

class Person {
protected:
    FIO name;
    DATE birthday;
    Phone number;
public:
    Person(FIO, DATE, Phone);
    Person(const Person&);
    ~Person() {}

    Person& operator=(const Person&);

};

enum District {
    Avtozavodsky, Kanavinsky, Leninsky, Moskovsky,
    Nizhegorodsky, Prioksky, Sovietsky, Sormovsky
};

enum TypeOfWork {
    Walls, Ceiling, Roof, Floor, Windows,
    Wiring, Plumbing, Gas_Distribution, Heating
};


enum Weeksday { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };

enum Shift { First, Second };

class Work {
    std::string W;
    TypeOfWork* WT;
    std::string B;

    Material* mat;
    int count;

    float V;
public:
    Work(std::string, TypeOfWork*);
    Work(const Work&);
    ~Work();

};

class Company {
  
public:

    std::string CName;
    std::string Adress;
    Weeksday worksdays;
    Shift sh;
    District areal;
    Phone phone;

    Company(std::string _CName, std::string _Adress, Weeksday, Weeksday, Shift, District, long long  _phone) {
        CName = _CName;
        Adress = _Adress;
        phone = _phone;
    }
    Company(const Company&);
    ~Company() {
    }

    Company& operator=(const Company&);

    bool operator==(const Company&) const;
    bool operator<(const Company&) const;
    bool operator>(const Company&) const;

    friend std::ostream& operator<<(std::ostream&, const Company&);
    friend std::istream& operator>>(std::istream&, const Company&);
};

class  ClientRequest: Person {

    District Dist;
    Work task;
    DATE DT;
    float budget;

public:
    ClientRequest(District*, std::string, DATE, float);
    ClientRequest(const ClientRequest&);
    ~ClientRequest() {}

    ClientRequest& operator=(const ClientRequest&);
};

class Quest {
    ClientRequest Task;
    Company Owner;
    DATE date;
    bool status;

    std::string* recomends;
    int count;
public:
    Quest();
    Quest(ClientRequest*, Company*, DATE);
    Quest(const Quest&);
    ~Quest() {
        if (recomends != nullptr) delete[] recomends;
    }

    bool operator==(const Quest&) const;
    bool operator<(const Quest&) const;
    bool operator>(const Quest&) const;

};

class Quests {
    Quest** archive;
    int size;
};

int main() {

    int Name;

    while (true) {
        system("cls");
        std::cout << "\n\n\t\t\t\tWELCOME TO BSS";
        _getch();
        system("cls");
        std::cout << "\n\n\t\t\t\t\t MENU\n";
        std::cout << "\n\t\t\t 1)LIST OF COMPANIES\n";
        std::cout << "\t\t\t 2)WRITE YOUR REQUEST\n";
        std::cout << "\t\t\t 3)LOOK AT LIST OF YOUR REQUESTS\n";
        std::cout << "\t\t\t 4)DELETE REQUEST\n";
        std::cout << "\n\t\t\t\t      YOUR GHOICE:";
        std::cin >> Name;

        if (Name != 1 && Name != 2 && Name != 3 && Name != 4)
        {
            system("cls");
            std::cout << "\n\n\n\t\t\t\t  INCORRECT CHOISE\n\t\t\t\t     TRY AGAIN\n\n";
            _getch();
            continue;

        }
        else if (Name == 1) {
            system("cls");
            FIO ARC("ARC", "Zarecnaya 5", "");
        }
    }
}
