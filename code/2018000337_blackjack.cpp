#include <iostream>
#include <string>
#include <sstream>
using namespace std;

bool SUM(int sum) {
	if (sum < 21) {return false;}
	else if (sum == 21) {return true;}
	else {return false;}
}

int main() {
	string str, cardP[20], card_num;
	while (1) {
		int count = 0, sum = 0, card_count = 0, card_number = 0;
		bool findA = false;
		cin >> card_num;
		if (card_num == "q") {break;}
		getline(cin, str);
		stringstream ss(str);
		sum = 0;
		while (ss) {
			card_count++;
			ss >> cardP[card_count];
		}
		for (int i = 0; i < card_count; i++) {
			if (cardP[i][0] == 'J' || cardP[i][0] == 'Q' || cardP[i][0] == 'K') {sum = sum + 10;}
			if (atoi(cardP[i].c_str()) > 0 && atoi(cardP[i].c_str()) < 11) {sum = sum + atoi(cardP[i].c_str());}
			if (cardP[i][0] == 'A') {
				findA = true;
				sum = sum + 1;
			}
		}
		if (findA) {if (SUM(sum + 10)) {sum = sum + 10;}}
		if (sum < 21) {cout << sum << endl;}
		else if (sum == 21) {cout << "BlackJack" << endl;}
		else {cout << "Exceed" << endl;}
	}
	return 0;
}