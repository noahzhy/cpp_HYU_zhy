#ifndef __reply_admin__
#define __reply_admin__

#include <iostream>
#include <string>
using namespace std;

class ReplyAdmin {
	private:
		string *chats;
		string chatslist[20];
		string emptystr = "";
		int NUM_OF_CHAT;

	public:
		ReplyAdmin();
		~ReplyAdmin();

		int getChatCount();

		bool addChat(string _chat);

		bool removeChat(int _index);

		bool removeChat(int *_indices, int _count);

		bool removeChat(int _start, int _end);

		void refresh();

		void printChat();
};

#endif
