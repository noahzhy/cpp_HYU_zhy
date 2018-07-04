#include "sorted_array.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main() {
	SortedArray sa;
	string command;
	int c = 0;
	while (1) {
		int numbers[99];
		getline(cin,command);

		if (command == "quit") {
			break;
		} else if (command == "ascend") {
			vector<int> v1 = sa.GetSortedAscending();
			vector<int>::iterator it = v1.begin();
			while (it != v1.end()) {
				cout << *it << " ";
				it++;
			}
			cout << endl;
		} else if (command == "descend") {
			vector<int> v2 = sa.GetSortedDescending();
			vector<int>::iterator it = v2.begin();
			while (it != v2.end()) {
				cout << *it << " ";
				it++;
			}
			cout << endl;
		} else if (command == "max") {
			cout << sa.GetMax() << endl;
		} else if (command == "min") {
			cout << sa.GetMin() << endl;
		}

		else {
			stringstream ss(command);
			c = 0;
			while (ss) {
				ss >> numbers[c++];
			}
			for (int i = 0; i < c-1; i++) {
				sa.AddNumber(numbers[i]);
			}
			vector<int> v0 = sa.GetSortedAscending();
			vector<int>::iterator it = v0.begin();
			while (it != v0.end()) {
				cout << *it << " ";
				it++;
			}
			cout << endl;
		}

	}
	return 0;
}
