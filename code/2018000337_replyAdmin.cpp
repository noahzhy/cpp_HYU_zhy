#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string textList[20];
int max_lines = 5;

void output() {
	int number = 0;
	max_lines = 0;
	for (int i = 0; i < 21; i++) {
		if (textList[i] != "") {
			cout << number << " " << textList[i] << endl;
			number = number + 1;
			max_lines = number;
		}
	}
}

void removelist(int number) {
	textList[number] = "";
}

void removeFromAtoB(int a, int b) {
	for (int i = a; i <= b; i++) {removelist(i);}
}

void refresh() {
	string temp = "";
	for (int i = 0; i < max_lines; i++) {
		for (int j = 0; j < max_lines - i; j++) {
			if (textList[j] == "") {
				temp = textList[j];
				textList[j] = textList[j + 1];
				textList[j + 1] = temp;
			}
		}
	}
}

int main()
{
	string command;

	textList[0] = "Hello, Reply Administrator!";
	textList[1] = "I will be a good programmer.";
	textList[2] = "This class is awesome.";
	textList[3] = "Professor Lim is wise.";
	textList[4] = "Two TAs are kind and helpful.";
	textList[5] = "I think male TA looks cool.";

	while (1) {
		char str[99];
		cin >> command;
		// cout << command << endl;
		if (command == "#remove") {

			for (int i = 0; i < 100; i++) {str[i] = 0;}

			cin >> str;
			int count = 0;// use to count all the numbers in command number
			for (int i = 0; i < 100; i++) {
				if ((((int)str[i] >= 48) && ((int)str[i] <= 57)) || str[i] == '-') {
					str[i] = str[i];
					count++;
				} else {str[i] = 0;}
			}
			for (int i = 0; i < 100; i++) {
				if (str[i] == '-' ) {removeFromAtoB((int)(str[i - 1] - '0'), (int)(str[i + 1] - '0'));}
			}
			for (int i = 0; i < 100; i++) {
				if (((int)str[i] >= 48) && ((int)str[i] <= 57)) {removelist((int)(str[i]) - '0');}
			}


			if (count > 0) {refresh(); output();}
		} else if (command == "#quit") {
			return 0;
		} else {
			if (command[0] != '#') {
				string temp = "";
				getline(cin, temp);
				textList[max_lines + 1] = command + temp;
				max_lines = max_lines + 1;
				refresh();
				output();
			}
		}
	}
	return 0;
}