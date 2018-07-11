#ifndef __sorted_array__
#define __sorted_array__
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <sstream>

using namespace std;

struct Any {
	string type;
	set<int> set_int;
	set<double> set_double;
	set<string> set_string;
};


class sorted_array
{
public:
	int find(string find_var_name, int find_var_value) {
		map<string, Any>::iterator it = sorted_array_map.find(find_var_name);
		int count = 0;
		for (set<int>::iterator it_int = it->second.set_int.begin() ; it_int != it->second.set_int.end(); it_int++) {
			if (*it_int == find_var_value) {break;}
			count++;
			if (count > it->second.set_int.size() - 1) {count = -1;}
		}
		return count;
	}

	int find(string find_var_name, double find_var_value) {
		map<string, Any>::iterator it = sorted_array_map.find(find_var_name);
		int count = 0;
		for (set<double>::iterator it_double = it->second.set_double.begin() ; it_double != it->second.set_double.end(); it_double++) {
			if (*it_double == find_var_value) {break;}
			count++;
			if (count > it->second.set_double.size() - 1) {count = -1;}
		}
		return count;
	}

	int find(string find_var_name, string find_var_value) {
		map<string, Any>::iterator it = sorted_array_map.find(find_var_name);
		int count = 0;
		for (set<string>::iterator it_string = it->second.set_string.begin() ; it_string != it->second.set_string.end(); it_string++) {
			if (*it_string == find_var_value) {break;}
			count++;
			if (count > it->second.set_string.size() - 1) {count = -1;}
		}
		return count;
	}

	void list() {
		map<string, Any>::iterator it = sorted_array_map.begin();
		while (it != sorted_array_map.end()) {
			string temp = it->second.type;
			cout << temp << " " << it->first << " :";
			if (temp == "int") {
				for (set<int>::iterator it_int = it->second.set_int.begin() ; it_int != it->second.set_int.end(); it_int++) {
					cout << " " << *it_int;
				}
				cout << endl;
			}
			else if (it->second.type == "double") {
				for (set<double>::iterator it_double = it->second.set_double.begin() ; it_double != it->second.set_double.end(); it_double++) {
					cout << " " << *it_double;
				}
				cout << endl;
			}
			else if (it->second.type == "string") {
				for (set<string>::iterator it_string = it->second.set_string.begin() ; it_string != it->second.set_string.end(); it_string++) {
					cout << " " << *it_string;
				}
				cout << endl;
			}
			it++;
		}
	}

	void add(string var_name, string type, int numbers, string ss_value) {
		int int_temp;
		Any any;
		double double_temp;
		string string_temp;
		any.type = type;
		cout << var_name << " :";
		stringstream ss(ss_value);
		for (int i = 0; i < numbers; i++) {
			if (type == "int") {
				ss >> int_temp;
				any.set_int.insert(int_temp);
			}
			if (type == "double") {
				ss >> double_temp;
				any.set_double.insert(double_temp);
			}
			if (type == "string") {
				ss >> string_temp;
				any.set_string.insert(string_temp);
			}
		}

		if (type == "int") {
			for (set<int>::iterator it_int = any.set_int.begin() ; it_int != any.set_int.end(); it_int++) {
				cout << " " << *it_int;
			}
			cout << endl;
		}
		if (type == "double") {
			for (set<double>::iterator it_double = any.set_double.begin() ; it_double != any.set_double.end(); it_double++) {
				cout << " " << *it_double;
			}
			cout << endl;
		}
		if (type == "string") {
			for (set<string>::iterator it_string = any.set_string.begin() ; it_string != any.set_string.end(); it_string++) {
				cout << " " << *it_string;
			}
			cout << endl;
		}

		sorted_array_map[var_name] = any;

	}
public:
	map<string, Any> sorted_array_map;

};

#endif
