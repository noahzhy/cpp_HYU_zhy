#include <iostream>
#include <string>
using namespace std;
class Person {
protected:
	string name;
	int age;
	bool gender;
public:
	Person(string name, int age, bool gender);
	print();
};

Person::Person(string name, int age, bool gender) {
	this->name = name;
	this->age = age;
	this->gender = gender;
}
Person::print() {
	cout << "Name\t:" << name << endl;
	cout << "Age\t:" << age << endl;
	cout << "Gender\t:" << gender << endl;
}


class Employee: public Person {
protected:
	string no;
	int salary;
	string department;
public:
	Employee(string name, int age, bool gender, string no, int salary, string department);
	print();
};

Employee::Employee(string name, int age, bool gender, string no, int salary, string department): Person(name, age, gender) {
	this->name = name;
	this->age = age;
	this->gender = gender;
	this->no = no;
	this->salary = salary;
	this->department = department;
}
Employee::print() {
	cout << "Name\t:" << name << endl;
	cout << "Age\t:" << age << endl;
	cout << "Gender\t:" << gender << endl;
	cout << "No.\t:" << no << endl;
	cout << "Salary\t:" << salary << endl;
	cout << "Department\t:" << department << endl;

}

class Manager: public Employee {
protected:
	int bonus;
public:
	Manager(string name, int age, bool gender, string no, int salary, string department, int bonus);
	print();
};
Manager::Manager(string name, int age, bool gender, string no, int salary, string department, int bonus): Employee(name, age, gender, no, salary, department) {
	this->name = name;
	this->age = age;
	this->gender = gender;
	this->no = no;
	this->salary = salary;
	this->department = department;
	this->bonus = bonus;
}

Manager::print() {
	cout << "Name\t:" << name << endl;
	cout << "Age\t:" << age << endl;
	cout << "Gender\t:" << gender << endl;
	cout << "No.\t:" << no << endl;
	cout << "Salary\t:" << salary << endl;
	cout << "Department\t:" << department << endl;
	cout << "Bonus\t:" << bonus << endl;

}


int main() {
	Manager  manager("name sample",  30,  true,  "101",  5000,  "department sample",  2000);
	manager.print();
	return 0;
}
