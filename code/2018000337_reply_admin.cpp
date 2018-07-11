#include <iostream>
#include <string>
#include <list>
#include "2018000337_reply_admin.h"
bool ReplyAdmin::addChat(string _chat) {
	int i = chats.size();
	if (!_chat.empty()) {
		chats.push_back(_chat);
		return true;
	} else
		return false;
}
bool ReplyAdmin::removeChat(int _index) {
	int num = chats.size();
	list<int>::iterator itList = chats.begin();
	if (_index < num && _index >= 0) {
		for (int i = 0; i < _index; i++) {
			itList++;
			chats.erase(itList);
			return true;
		}
	}
	else return false;
}
bool ReplyAdmin::removeChat(int *_indices, int _count) {
	removeChat(_indices[0]);
	for (int i = 1; i <= _count; i++) {
		if (_indices[i] > _indices[i - 1]) {removeChat(_indices[i] - 1);}
		else removeChat(_indices[i]);
	}
	return true;
}

bool ReplyAdmin::removeChat(int _start, int _end) {
	int i = chats.size();
	if (_start >= i || _end <= 0)return false;
	for (; _start < _end; _start++) {removeChat(_start);}
	return true;
}

void ReplyAdmin::printChat() {
	list<string>::iterator it = chats.size();
	int index = 0;
	for (it; it != chats.end(); it++) {
		cout << index << " " << *it << endl;
		index++;
	}
}

ReplyAdmin::ReplyAdmin() {
	// chats(NUM_OF_CHAT);
	addChat("Hello, Reply Administrator!");
	addChat("I will be a good programmer.");
	addChat("This class is awesome.");
	addChat("Professor Lim is wise.");
	addChat("Two TAs are kind and helpful.");
	addChat("I think male TA looks cool.");
}

ReplyAdmin::~ReplyAdmin() {}
