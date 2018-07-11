#include <iostream>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include "sorted_array.h"

using namespace std;

int main() {
	sorted_array sa;
	string command, var_name, type_name, long_string;
	int numbers;

	while (1) {
		cin >> command;
		if (command == "quit") {
			break;
		} else if (command == "int" || command == "double" || command == "string") {
			cin >> var_name;
			cin >> numbers;
			getline(cin, long_string);
			sa.add(var_name, command, numbers, long_string);

		} else if (command == "list") {
			sa.list();

		} else if (command == "find") {
			string find_var_name;
			cin >> find_var_name;
			map<string, Any>::iterator it = sa.sorted_array_map.find(find_var_name);
			string temp = it->second.type;
			if (temp == "int") {
				int value;
				cin >> value;
				cout << sa.find(find_var_name, value)<<endl;
			}
			if (temp == "double") {
				double value;
				cin >> value;
				cout << sa.find(find_var_name, value)<<endl;
			}
			if (temp == "string") {
				string value;
				cin >> value;
				cout << sa.find(find_var_name, value)<<endl;
			}

		}
	}
	return 0;
}
