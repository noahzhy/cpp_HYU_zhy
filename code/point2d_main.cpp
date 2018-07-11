#include <iostream>
#include <map>
#include <string>
#include "point2d.h"
using namespace std;

int main() {
	string command;

	map<char, Point*> c_p_map;

	while (1) {
		cin >> command;
		int size = 0;
		if (command == "set") {

			char name_of_p;
			int p_x , p_y;
			cin >> name_of_p >> p_x >> p_y;
			Point *p = new Point(p_x,p_y);
			c_p_map[name_of_p]=p;

		} else if (command == "eval") {
			bool input_error = false;
			map<char, Point*>::iterator it;
			Point *temp_it_left;
			Point *temp_it_right;
			char left, mini_command, right;
			cin >> left>>mini_command>>right;


			if (((int)left>=48&&(int)left<=57)&&((int)right>=48&&(int)right<=57)) {
				
				temp_it_left = new Point(left-'0',left-'0');
				temp_it_right = new Point(right-'0',right-'0');
				
			} else if((int)left>=48&&(int)left<=57) {
				it = c_p_map.find(right);
				if (it == c_p_map.end()) {
					cout << "input error"<<endl;
					input_error = true;
				} else {
					temp_it_right = it->second;
				}
				temp_it_left = new Point(left-'0',left-'0');

			} else if((int)right>=48&&(int)right<=57) {
				it = c_p_map.find(left);
				if (it == c_p_map.end()) {
					cout << "input error"<<endl;
					input_error = true;
				} else {
					temp_it_left = it->second;
				}
				temp_it_right = new Point(right-'0',right-'0');

			} else if (((int)left<=48||(int)left>=57)&&((int)right<=48||(int)right>=57)) {
				it = c_p_map.find(left);

				if (it == c_p_map.end()) {
					cout << "input error"<<endl;
					input_error = true;
				} else {
					temp_it_left = it->second;
				}

				it = c_p_map.find(right);

				if (it == c_p_map.end()) {
					cout << "input error"<<endl;
					input_error = true;
				} else {
					temp_it_right = it->second;
				}
			}
			if(!input_error) {

				if(mini_command=='+') {
					operator+(*temp_it_left,*temp_it_right);
				}

				if(mini_command=='-') {
					operator-(*temp_it_left,*temp_it_right);
				}

				if(mini_command=='*') {
					operator*(*temp_it_left,*temp_it_right);
				}
			}

		} else if (command == "quit") {
			break;
		}

	}
	return 0;
}
