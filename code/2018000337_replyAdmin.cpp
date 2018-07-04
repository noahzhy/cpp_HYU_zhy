#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string textList[20];
int max_lines = 5;
int remove_count = 0;// use to count all the numbers in command number

void output() {
    int number = 0;
    max_lines = 0;
    for (int i = 0; i < 21; i++) {
        if (textList[i].empty() == false) {
            cout << number << " " << textList[i] << endl;
            number++;
        }
    }
    max_lines = number;
}

void removelist(int number) {
    if (number >= 0 && number <= max_lines) {textList[number] = ""; remove_count++;}
}

void removeFromAtoB(int a, int b) {
    for (int i = a; i <= b; i++) {removelist(i);}
}

void refresh() {
    string temp = "";
    for (int i = 0; i < max_lines; i++) {
        for (int j = 0; j < max_lines - i; j++) {
            if (textList[j].empty() == true) {
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
        string str;
        cin >> command;
        if (command == "#remove") {
            remove_count = 0;
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
                    removeFromAtoB(ready2move[0], ready2move[1]);
                }
                if (comma > 0) {
                    for (int i = 0; i < 100; i++) {
                        if (str[i] == ',' ) {str[i] = ' ';}
                    }
                    stringstream ss(str);
                    int index = 0, ready2move[99];
                    while (ss) { ss >> ready2move[index++];}
                    for (int i = 0; i < index - 1; i++) {removelist(ready2move[i]);}
                }
            } if (comma == 0 && hyphen == 0) {
                stringstream ss(str);
                int index = 0, ready2move[99];
                while (ss) { ss >> ready2move[index++];}
                for (int i = 0; i < --index; i++) {removelist(ready2move[i]);}
            }
            refresh();
            if (remove_count > 0) { output();}
        } else if (command == "#quit") {
            return 0;
        } else {
            if (command[0] != '#') {
                string temp = "";
                getline(cin, temp);
                textList[++max_lines] = command + temp;
                max_lines++;
                refresh();
                output();
            }
        }
    }
    return 0;
}