#include <iostream>
using namespace std;
int main() {
	int a = 1, b = 1, c[100] , count = 0;
	cin >> count;
	c[1] = 1;
	c[2] = 1;
	for (int i = 1; i < count; i++) {
		c[i + 2] = c[i] + c[i + 1];
	}
	for (int i = 1; i < count + 1; i++) {
		cout << c[i] << " ";
	}
	cout << endl;
	return 0;
}