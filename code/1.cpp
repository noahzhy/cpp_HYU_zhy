#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
	int age;
	int weight;
public:
	Animal(int age, int weight);
	sleep();
	eat() {};
	speak() {};
	print();
};

Animal::Animal(int age, int weight) {
	this->age = age;
	this->weight = weight;
}

Animal::print() {
	cout << "Age\t:" << age << endl;
	cout << "Weight\t:" << weight << endl;
}

Animal::sleep() {
	cout << "Sleep" << endl;
}


class Dog: public Animal {
protected:
	string breed;
public:
	Dog(int age, int weight, string breed);
	speak();
	print();
};


Dog::Dog(int age, int weight, string breed): Animal(age, weight) {
	this->age = age;
	this->weight = weight;
	this->breed = breed;
}

Dog::speak() {
	cout << "meongmeong" << endl;
}

Dog::print() {
	cout << "Age\t:" << age << endl;
	cout << "Weight\t:" << weight << endl;
	cout << "Breed:\t:" << breed << endl;
}
class Bird: public Animal {

public:
	Bird(int age, int weight);
	speak();
};

Bird::Bird(int age, int weight): Animal(age, weight) {
	this->age = age;
	this->weight = weight;
};
Bird::speak() {
	cout << "jjaekjjaek" << endl;
}

int main() {
	Dog dog(3, 7, "maltijeu");
	dog.print();
	dog.sleep();
	dog.speak();
	cout << "-----------------------\n";
	Bird bird(1, 3);
	bird.print();
	bird.sleep();
	bird.speak();
	return 0;
}
