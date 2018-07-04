#include <iostream>
#include <string>
#include <sstream>
#include "2018000337_reply_admin.h"
using namespace std;

int main()
{
	string command;
	ReplyAdmin ra;
	ra.addChat("Hello, Reply Administrator!");
	ra.addChat("I will be a good programmer.");
	ra.addChat("This class is awesome.");
	ra.addChat("Professor Lim is wise.");
	ra.addChat("Two TAs are kind and helpful.");
	ra.addChat("I think male TA looks cool.");

	while (1) {
		string str;
		cin >> command;
		if (command == "#remove") {
			cin >> str;
			int comma = 0, hyphen = 0;
			for (int i = 0; i < 100; i++) {
				if ((((int)str[i] >= 48) && ((int)str[i] <= 57)) || ((str[i] == '-') || (str[i] == ','))) {}
				else {str[i] = ' ';}
				if (str[i] == ',' ) {comma++;}
				if (str[i] == '-') {hyphen++;}
			}
			if (comma > 0 && hyphen > 0) {} else {
				if (hyphen > 0) {
					for (int i = 0; i < 100; i++) {
						if (str[i] == '-' ) {str[i] = ' ';}
					}
					stringstream ss(str);
					int index = 0, ready2move[99];
					while (ss) { ss >> ready2move[index++];}
					if (ra.removeChat(ready2move[0], ready2move[1])) {ra.printChat();}
				}
				if (comma > 0) {
					for (int i = 0; i < 100; i++) {
						if (str[i] == ',' ) {str[i] = ' ';}
					}
					stringstream ss(str);
					int index = 0, ready2move[99];
					while (ss) { ss >> ready2move[index++];}
					if (ra.removeChat(ready2move, --index)) {ra.printChat();}
				}
			} if (comma == 0 && hyphen == 0) {
				stringstream ss(str);
				int index = 0, ready2move[99];
				while (ss) { ss >> ready2move[index++];}
				if (ra.removeChat(ready2move, --index)) {ra.printChat();}
			}
		} else if (command == "#quit") {
			return 0;
		} else {
			if (command[0] != '#') {
				string temp = "";
				getline(cin, temp);
				if (ra.addChat(command + temp)) {ra.printChat();}
			}
		}
	}
	return 0;
}
