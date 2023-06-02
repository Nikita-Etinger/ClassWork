#include <iostream>
using namespace std;
#define random(a,b) a + rand() % (b - a + 1)

class Student {
    int age;
    int height;
    int* math = nullptr;
public:
    Student() {}

    Student(int age, int height, int* marks) {
        this->age = age;
        this->height = height;
        int size = _msize(marks) / sizeof(marks[0]);
        math = new int[size];
        for (int i = 0; i < size; i++) {
            math[i] = marks[i];
        }
    }

    Student(const Student& st) {
        this->age = st.age;
        this->height = st.height;
        int size = _msize(st.math) / sizeof(st.math[0]);
        math = new int[size];
        for (int i = 0; i < size; i++) {
            math[i] = st.math[i];
        }
    }

    void operator = (const Student& st) {
        this->age = st.age;
        this->height = st.height;
        int size = _msize(st.math) / sizeof(st.math[0]);
        math = new int[size];
        for (int i = 0; i < size; i++) {
            math[i] = st.math[i];
        }
    }



    void setAge(int age) {
        this->age = age;
    }


    void changeMark(int id, int mark) {
        math[id] = mark;
    }

    void showInfo() {
        cout << this << endl;
        cout << age << " : " << height << endl;
        int size = _msize(math) / sizeof(math[0]);
        for (int i = 0; i < size; i++) {
            cout << math[i] << " ";
        }
        cout << endl;
    }


};

class Number {
    int n;
public:
    Number(int n) {
        this->n = n;
    }

    int operator + (Number& n2) {
        return n + n2.n;
    }
};

class Employee {
    string name;
    string phone;
    int* groshi=nullptr;
public:
    Employee() {}
    Employee(string name, string phone,int* mass) {
        this->name = name;
        this->phone = phone;
        int size = _msize(mass) / sizeof(mass[0]);
        groshi = new int[size];
        for (int i = 0; i < size; i++) {
            groshi[i] = mass[i];
        }
    }



    ~Employee() {
        delete[] groshi;
    }
    void operator = (Employee& oldEmployee) {
        this->name = oldEmployee.name;
        this->phone = oldEmployee.phone;
        if (this->groshi != nullptr) delete[] groshi;
        int size = _msize(oldEmployee.groshi) / sizeof(oldEmployee.groshi[0]);
        groshi = new int[size];
        for (int i = 0; i < size; i++) {
            groshi[i] = oldEmployee.groshi[i];
        }

    }

    void showInfo() {
        cout << name << " : " << phone << endl;
    }

};

class Otdel {
    Employee* employees = nullptr;
    int count = 0;
    string cab;
public:
    Otdel(string cab, int count, Employee* emp) {
        this->cab = cab;
        this->count = count;
        employees = new Employee[count];
        for (int i = 0; i < count; i++) {
            employees[i] = emp[i];
        }
    }
    Otdel(const Otdel& otd) {
        this->cab = otd.cab;
        this->count = otd.count;
        employees = new Employee[count];
        for (int i = 0; i < count; i++) {
            employees[i] = otd.employees[i];
        }
    }
    void operator = (const Otdel& otd) {
        if (employees != nullptr)
            delete[] employees;
        this->cab = otd.cab;
        this->count = otd.count;
        employees = new Employee[count];
        for (int i = 0; i < count; i++) {
            employees[i] = otd.employees[i];
        }
    }

    void showInfo() {
        cout << cab << " : " << endl;
        for (int i = 0; i < count; i++) {
            employees[i].showInfo();
        }
    }
    ~Otdel() {
        delete[]employees;
    }

};


//создать класс машина(цвет,гос номер(уникальный),марка)

//создать класс парковка реализовать метод добавления машин и удаления по госномеру


const string carBrands[] = { "Toyota", "Honda", "Ford", "Chevrolet", "Nissan", "BMW", "Mercedes-Benz", "Audi", "Volkswagen", "Hyundai" };
const string carColors[] = { "Red", "Blue", "Green", "Yellow", "Black" };
//ББ"""Б
class Car {
    static string numberC;
    static int counterCar;
    string info;
    string mark;
    string colour;
    string number;
public:
    Car() {
    }
    static void upNumber() {
        if (counterCar != 0) {
            if (numberC[2] == 9 && numberC[2] == 9 && numberC[2] == 9) {
                upAlpha();
            }
            if (numberC[3] < 9)numberC[3]++;
            else if (numberC[3] == 9) {
                numberC[3] == 0;
                numberC[2]++;

            }
            if (numberC[2] < 9)numberC[2]++;
            else if (numberC[2] == 9) {
                numberC[2] == 0;
                numberC[1]++;
            }
        }
        counterCar++;


    }
    static void upAlpha() {
        if (numberC[5] < 'Z')numberC[5]++;
        else if (numberC[5] == 'Z') {
            numberC[5] == 0;
            numberC[1]++;

        }
        if (numberC[1] < 'Z')numberC[1]++;
        else if (numberC[1] == 'Z') {
            numberC[1] == 0;
            numberC[0]++;
        }


    }
    Car(string mark,string colour) {
        this->mark = mark;
        this->colour = colour;
        upNumber();
        this->number = numberC;
    }
    string getNumber() {
        return number;
    }
    Car operator=(Car& oldCar) {
        this->mark = oldCar.mark;
        this->colour = oldCar.colour;
        this->number = oldCar.number;
        this->info = oldCar.info;
        upNumber();
        this->number = numberC;
    }
};
string Car::numberC="AA000A";
int Car::counterCar=0;
class Park {
    Car* cars = nullptr;
    int counterCar = 0;
public:
    void addCar(Car& newCar) {
        Car* buf = new Car[counterCar + 1];
        for (int i = 0; i < counterCar; i++) {
            buf[i] = cars[i];
        }
        buf[counterCar] = newCar;
        counterCar++;
        delete[]cars;
        cars = buf;

    }
    int searchCar(string number) {
        for (int i = 0; i < counterCar; i++) {
            if (number == cars[i].getNumber()) {
                return i;
            }
        }


    }
    void deleteCar(string number) {
        int index = searchCar(number);
        if (index != -1) {
            Car* buf = new Car[counterCar - 1];
            for (int i = 0; i < index; i++) {
                buf[i] = cars[i];
            }
            for (int i = index + 1; i < counterCar; i++) {
                buf[i - 1] = cars[i];
            }
            counterCar--;
            delete[] cars;
            cars = buf;
        }
    }

    ~Park() {
        delete[]cars;
    }





};

int main() {




}