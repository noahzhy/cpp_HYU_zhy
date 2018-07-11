#ifndef __reply_admin__
#define __reply_admin__

#include <iostream>
#include <string>
#include <list>
using namespace std;

#define NUM_OF_CHAT 200

class ReplyAdmin
{
private:
	list<string> chats;

public:
	ReplyAdmin();
	~ReplyAdmin();

	bool addChat(string _chat);
	bool removeChat(int _index);
	bool removeChat(int *_indices, int _count);
	bool removeChat(int _start, int _end);
	void printChat();
};

#endif
