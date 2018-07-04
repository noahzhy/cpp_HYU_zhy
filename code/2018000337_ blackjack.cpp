#include <iostream>
#include <string>
using namespace std;

int main() {
	char str[99];
	int count = 0, sum = 0;
	while (1) {
		if (getchar() == '\n') {break;}
		cin >> str;
	}
	for (int i = 0; i < count; i++) {
		if (str[count] == 'J' || (str[count] == 'Q' || str[count] == 'K')) {
			cout << str[count] << "<<<<<<<<" << endl;
		}
	}
	return 0;
}