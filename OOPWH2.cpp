#include <iostream>
#include <string>
#include <fstream>
using namespace std;

using namespace std;
class Point {
private:

	int x = 0;
	int y = 0;
	int z = 0;
public:
	void setY(int y) {
		this->y = y;
	}
	void setX(int x) {
		this->x = x;
	}
	void setZ(int z) {
		this->z = z;
	}
	int getY(int y) {
		return y;
	}
	int getX(int x) {
		return x;
	}
	int getZ(int z) {
		return z;
	}

};



class Drob {
private:
	int numerator;   // числитель
	int denominator; // знаменатель


public:
	Drob() {
		numerator = 0;
		denominator = 1;
	}
	Drob(int numerator, int denominator) {
		this->numerator = numerator;
		this->denominator = denominator;
	}
	void input(int numerator, int denominator) {
		this->numerator = numerator;
		this->denominator = denominator;

	}

	int getNumerator() {
		return numerator;
	}
	int getDenominator() {
		return denominator;
	}



};

class Mathem {
private:

public:


	// сложение
	Drob* add(Drob*& onesDrob, Drob*& secondDrob) {
		int resultNum = onesDrob->getNumerator() * secondDrob->getNumerator() + secondDrob->getNumerator() * onesDrob->getDenominator();
		int resultDenom = onesDrob->getDenominator() * onesDrob->getDenominator();
		Drob* dr = new Drob(resultNum, resultDenom);
		return dr;
	}

};

class JournaL {
private:
	string teacher = " ";


public:


};

class Dist {
private:


public:




};
class Discipline {
private:
	string name = " ";
	int* marks = nullptr;
	int counter = 0;
public:
	Discipline() {}
	Discipline(string name) {
		this->name = name;
	}
	void addMarks(int newMark) {
		int* buf = new int[counter + 1];
		for (int i = 0; i < counter; i++) {
			buf[i] = marks[i];
		}
		buf[counter++] = newMark;
		delete[] marks;
		marks = buf;
	}
	string getName() {
		return name;
	}
	void show() {
		cout << "Discipline: " << name << endl;
		for (int i = 0; i < counter; i++) {
			cout << marks[i] << " ";
		}
		cout << endl;
	}

};
class Student {
private:
	string name;
	int id;
	string numTel;
	float mark = 0;
	int raitingGroup = 0;
	int raitingFlow = 0;
	int counterDiscipline = 0;

	Discipline* disciplines = nullptr;
public:
	void addDiscipline(string newDiscipline) {
		Discipline* buf = new Discipline[counterDiscipline + 1];
		for (int i = 0; i < counterDiscipline; i++) {
			buf[i] = disciplines[i];
		}
		buf[counterDiscipline++] = newDiscipline;
		delete[] disciplines;
		disciplines = buf;
	}

	void addMarks(string discipline, int mark) {
		Discipline* dis = searchDiscipline(discipline);
		if (dis != nullptr) {
			dis->addMarks(mark);
		}
	}

	Discipline* searchDiscipline(string name) {
		for (int i = 0; i < counterDiscipline; i++) {
			if (name == disciplines[i].getName()) {
				return &disciplines[i];

			}
		}
		return nullptr;
	}

	Student() {

	}
	Student(string name, int id, string numTel) {
		this->name = name;
		this->id = id;
		this->numTel;
	}
	string getName() {
		return name;
	}
	int getId() {
		return id;
	}
	string getNumTel() {
		return numTel;
	}
	float getMark() {
		return mark;
	}
	int getRaitingGroup() {
		return raitingGroup;
	}
	int getRaitingFlow() {
		return raitingFlow;
	}
	void setMark(int mark) {
		this->mark = mark;
	}
	void setNumTel(string numTel) {
		this->numTel = numTel;
	}
	void setRaitingGroup(int raitingGroup) {
		this->raitingGroup = raitingGroup;
	}
	void setaRaitingFlow(int raitingFlow) {
		this->raitingFlow = raitingFlow;
	}
	void show() {
		cout << "Name: " + name + " ID: " + to_string(id) + " number: " + numTel + " mark: " + to_string(mark) + " raitingGroup: " + to_string(raitingGroup) + " raitingFlow: " + to_string(raitingFlow) + '\n';
		for (int i = 0; i < counterDiscipline; i++) {
			disciplines[i].show();
		}
	}


};
class Group {
private:
	string name = "No name";
	Student* students = nullptr;
	int countStudent = 0;
public:
	Group() {};
	Group(string name) {
		this->name = name;
	}
	void addStudent(Student& newStudent) {
		Student* buf = new Student[countStudent + 1];
		for (int i = 0; i < countStudent; i++) {
			buf[i] = students[i];
		}
		buf[countStudent++] = newStudent;
		countStudent;
		delete[] students;
		students = buf;

	}
	void removeStudent(int id) {
		Student* searchSt = searchStudent(id);
		if (searchSt != nullptr) {
			int n = 0;
			if (countStudent == 1) {
				delete[]students;
				students = nullptr;
			}
			else {
				for (int i = 0; i < countStudent; i++) {
					if (searchSt == &students[i]) n = i;
				}
				Student* buf = new Student[countStudent - 1];
				for (int i = n; i < n; i++) {
					buf[i] = students[i];
				}
				for (int i = n + 1; i < countStudent; i++) {
					buf[i - 1] = students[i];
				}
				delete[] students;
				students = buf;
			}
			countStudent--;
		}
	}
	void showAllStudents() {
		cout << name << endl;
		for (int i = 0; i < countStudent; i++) {
			students[i].show();
		}
	}

	Student* searchStudent(int id) {
		for (int i = 0; i < countStudent; i++) {
			if (id == students[i].getId()) {
				return &students[i];

			}
		}
		return nullptr;



	}

	void addMarks(int idStudent, string discipline, int mark) {
		Student* searchSt = searchStudent(idStudent);
		if (searchSt != nullptr) {
			Discipline* dis = searchSt->searchDiscipline(discipline);
			if (dis != nullptr) {
				dis->addMarks(mark);
			}
		}
	}
	void addDiscipline(int idStudent, string discipline) {
		Student* searchSt = searchStudent(idStudent);
		if (searchSt != nullptr) {
			searchSt->addDiscipline(discipline);
		}
	}


};
int main()
{

	setlocale(LC_ALL, "Russian");
	Group* group1 = new Group[1];

	Student st1("asasas", 1, "121212121");
	Student st2("1wqe3", 2, "121121");
	Student st3("aqwe3", 3, "121121");
	Student st4("ry453", 4, "121121");
	Student st5("acb453", 5, "121121");
	Student st6("ary653", 6, "121121");
	group1->addStudent(st1);
	group1->addStudent(st2);
	group1->addDiscipline(2, "MATH");
	group1->addDiscipline(2, "GEO");
	group1->addMarks(2, "MATH", 5);
	group1->addMarks(2, "MATH", 5);
	group1->addMarks(2, "GEO", 5);
	group1->addMarks(2, "GEO", 3);
	group1->showAllStudents();






}