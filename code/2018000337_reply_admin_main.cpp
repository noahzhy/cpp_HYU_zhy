#include <iostream>
#include <string>
#include "2018000337_reply_admin.h"

using namespace std;

bool replyOperation(ReplyAdmin *_replay) {
	string str;
	getline(cin, str);

	if (str == "#quit") return false;
	else if (str.find("#remove") != string::npos) {
		str.erase(0, 8);
		int start = -1, end = -1, number = -1, numbers_count = 0;
		int* numbers = new int[NUM_OF_CHAT];
		bool removed = false;
		for (int i = 0; i < str.size(); ++i) {
			char c = str[i];
			if (isdigit(c) == true) {
				int num = (int)c - 0;
				if (number < 0) number = num;
				else number = number * 10 + num;
			} else {
				if (c == ',') numbers[numbers_count++] = number;
				else if (c == '-') start = number;
				number = -1;
			}
		}
		if (start >= 0) end = number;
		if (end >= start && start >= 0) removed = _replay->removeChat(start, end);
		else if (numbers_count > 0) {
			numbers[numbers_count++] = number;
			removed = _replay->removeChat(numbers, numbers_count);
		} else if (number >= 0) removed = _replay->removeChat(number);
		if (removed == true) _replay->printChat();
		delete[] numbers;
	} else if (_replay->addChat(str)) _replay->printChat();
	return true;
}

int main(void) {
	ReplyAdmin *replyAdmin = new ReplyAdmin();
	while (replyOperation(replyAdmin)) {}
	delete replyAdmin;
	return 0;
}
