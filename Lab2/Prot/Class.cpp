#include <iostream>

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

    // ��� ������� � ���������� � ������������������ �������
    bool operator==(const FIO&) const;
    bool operator<(const FIO&) const;
    bool operator>(const FIO&) const;

    friend std::ostream& operator<<(std::ostream&, const FIO&);
    friend std::istream& operator>>(std::istream&, const FIO&);

private:
    void fix(); // �������� � ��������� ������� (������, ������ � ������ - ���� � �� ��)
};

class Date {
    int day;
    int month;
    int year;
public:
    Date();                   // ������������� ����������� ����
    Date(std::string);
    Date(int, int, int);
    Date(const Date&);
    ~Date() {}

    Date& operator=(const Date&);

    // ��� �������
    bool operator==(const Date&) const;
    bool operator<(const Date&) const;
    bool operator>(const Date&) const;

    friend std::ostream& operator<<(std::ostream&, const Date&);
    friend std::istream& operator>>(std::istream&, const Date&);

private:
    bool check();   // ��������� ������������ ��������� ����
};

class Company {
    std::string CName;
    std::string Adress;
public:
    Company(std::string, std::string);
    Company(const Company&);
    ~Company() {}

    void setLastName(std::string);

    Company& operator=(const Company&);

    // ��� ������� � ���������� � ������������������ �������
    bool operator==(const Company&) const;
    bool operator<(const Company&) const;
    bool operator>(const Company&) const;

    friend std::ostream& operator<<(std::ostream&, const Company&);
    friend std::istream& operator>>(std::istream&, const Company&);

private:
    void fix();
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

    // ��� ������� � ���������� � ������������������ �������
    bool operator==(const Material&) const;
    bool operator<(const Material&) const;
    bool operator>(const Material&) const;

    friend std::ostream& operator<<(std::ostream&, const Material&);
    friend std::istream& operator>>(std::istream&, const Material&);

private:
    void fix();

};

class Phone {
    std::string phone;
    /* ... */
};

class Person {
protected:
    FIO name;
    Date birthday;
    Phone number;
public:
    Person(FIO, Date, Phone);
    Person(const Person&);
    ~Person() {}

    Person& operator=(const Person&);

    /* ... */
    // ����� ������ ����: ���������� ������, �����, �������� �����
};

enum District {
    Avtozavodsky, Kanavinsky, Leninsky, Moskovsky,
    Nizhegorodsky, Prioksky, Sovietsky, Sormovsky
};

class  Owner : Person {
    long int ID;
    District district;
    float founds;         // ������� � ������
    int discount;         // ������ � ���������
public:
    Owner(District, float, int, long int);
    Owner(const Owner&);
    ~Owner() {}

    Owner& operator=(const Owner&);
    /* ... */
    // ����� ������ ����: ���������� ������, �����, �������� ����� ������ �� �����, �������� ������
};

enum TypeOfWork {
    Walls, Ceiling, Roof, Floor, Windows,
    Wiring, Plumbing, Gas_Distribution, Heating
};


enum Weeksday { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };

enum Shift { First, Second }; // 2 �����: � 7:00 �� 15:00, � 15:00 �� 23:00

class  Vet : Person {
    long int ID;
    TypeOfWork* specialty;
    std::pair<Weeksday, Shift>* worksdays;
    Date workSince;
public:
    Vet(TypeOfWork*, std::pair<Weeksday, Shift>*, Date, long int);
    Vet(const Vet&);
    ~Vet() {
        delete[] specialty;
        delete[] worksdays;
    }

    Vet& operator=(const Vet&);
    /* ... */
    // ����� ������ ����: �������, �������� �������������, �������� ������, ������� ������, ��������� ���� ������,
    // ���������� �����, ������
};

enum Kind { Cat, Dog, Rodent, Other };

class Pet {
    std::string name;
    Date birthday;
    float weight;
    Kind kind;
    std::string species;
    Owner* owner;
public:
    Pet(std::string, Date, float, Kind, std::string, Owner*);
    Pet(const Pet&);
    ~Pet() {}

    Pet& operator=(const Pet&);
    /* ... */
    // ����� ������ ����: �������� ������� ���, ��������� ������� ������� (5 �. 8 ���. 3 ���.), ���������� �����, ������
};

class Visit {
    Pet* pet;
    Vet* vet;
    Date date;
    std::string* recomends;
    int count;
    bool status;                 // ����������� ��� ���
public:
    Visit();
    Visit(Pet*, Vet*, Date);
    Visit(const Visit&);
    ~Visit() {
        if (recomends != nullptr) delete[] recomends;
    }
    Visit& operator=(const Visit&);
    // ����� ������ ����:
    // �������,
    // �������� ������ ������� (���),
    // �������� ������������ (���� ����� ������� - ������),
    // �������� ���� (���� ����� ������� - ������),
    // ������� �����
};

class Visits {
    Visit* archive;   // ������ �������
    int count;
    int size;
public:
    Visits() { archive = new Visit[100]; count = 0; size = 100; }
    ~Visits() { delete[] archive; }
    bool add();            // �������� ����� (���� ������ �� ������� - ���������)
    bool del(Visit&);      // ������� �����
    Visit& find(Visit&);   // ����� �� ID ������
    Visit& find(Visit&);   // ����� �� ������� (���� ��������� - ��� ��������� �� ����� (���������� ������� ������),
    // ������������ ������� ������ � �������� � (����� �������), ��� ������������ �� ������)
    void fix(Visit&);      // ������ ������ � ����� (���������� ������� ������ Visit)
};
