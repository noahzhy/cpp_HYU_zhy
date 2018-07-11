#include <iostream>
#include <string>
#include "omok.h"
using namespace std;

int main() {
	int c = 1;
	int x,y;
	bool blackwins = false;
	bool whitewins = false;

	Omok om;
	while(1) {
		if(c>0) {
			cout<<"Black: ";
		} else {
			cout<<"White: ";
		}
		cin>>x>>y;
		om.put(x,y,c)==0?c=c:c= -c;
		if(om.check(-c)!=0) {
			om.check(-c)>0? blackwins = true:whitewins = true;
			break;
		}
	}


	operator<<(cout,om);
	if(blackwins) {
		cout<<"Winner: Black player"<<endl;
	} else if (whitewins) {
		cout<<"Winner: White player"<<endl;
	}

	return 0;
}
