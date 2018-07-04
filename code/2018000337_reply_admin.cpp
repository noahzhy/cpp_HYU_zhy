#include <iostream>
#include <string>
#include "2018000337_reply_admin.h"
using namespace std;

ReplyAdmin::ReplyAdmin() {
	this->chats = this->chatslist;
	this->NUM_OF_CHAT = 0;
}
ReplyAdmin::~ReplyAdmin() {
	delete this->chats;
}

int ReplyAdmin::getChatCount() {
	this->NUM_OF_CHAT = -1;
	for (int i = 0; i < 21; i++) {
		string ss = this->chats[i];
		if (ss.empty() == true) {
			break;
		}
		this->NUM_OF_CHAT++;
	}
	return this->NUM_OF_CHAT;
}

bool ReplyAdmin::addChat(string _chat) {
	this->NUM_OF_CHAT = this->NUM_OF_CHAT+1;
	this->chats[this->NUM_OF_CHAT] = _chat;
	return true;
}

bool ReplyAdmin::removeChat(int _index) {
	refresh();
	if ((_index <= this->getChatCount()) && (_index >= 0)) {
		this->chatslist[_index] = this->emptystr;
		return true;
	} else {
		return false;
	}
}

bool ReplyAdmin::removeChat(int *_indices, int _count) {
	bool removeSuccess = false;
	for (int i = 0; i < _count; i++) {
		if (removeChat(_indices[i])) {
			removeSuccess = true;
		}
	}
	if (removeSuccess) {
		return true;
	} else {
		return false;
	}
}

bool ReplyAdmin::removeChat(int _start, int _end) {
	bool removeSuccess = false;
	for (int i = _start; i <= _end; i++) {
		if (removeChat(i)) {
			removeSuccess = true;
		}
	}
	if (removeSuccess) {
		return true;
	} else {
		return false;
	}
}

void ReplyAdmin::refresh() {
	string temp = "";
	for (int i = 0; i < this->NUM_OF_CHAT; i++) {
		for (int j = 0; j < this->NUM_OF_CHAT - i; j++) {
			string s = this->chats[j];
			if (s.empty() == true) {
				temp = this->chats[j];
				this->chats[j] = this->chats[j + 1];
				this->chats[j + 1] = temp;
			}
		}
	}
}

void ReplyAdmin::printChat() {
	refresh();
	int number = 0;
	for (int i = 0; i < 21; i++) {
		string s = this->chats[i];
		if (s.empty() == false) {
			cout << number << " " << s << endl;
			number++;
		}
	}
}
