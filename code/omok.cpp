#include <ostream>
#include <iostream>
#include "omok.h"
using namespace std;

//Omok(): width_(GROUND_SIZE), height_(GROUND_SIZE), turn_(NOBODY) {}

int Omok::put(int x, int y, int b_or_w) {

	if(this->map[x][y]!=0||(x>=GROUND_SIZE||y>=GROUND_SIZE)) {
		cout<<"Can not be placed there."<<endl;
		return 0;
	} else {
		this->map[x][y] = b_or_w;
		return b_or_w;
	}
}

void Omok::IsOmok(int *winner) const {

}

int Omok::check(int q) {
	bool blackwins = false;
	bool whitewins = false;

	if(q==1) {
		for(int i=0; i <GROUND_SIZE; i++) {
			for(int j=0; j <GROUND_SIZE; j++) {
				if((q==this->map[i][j]&&q==this->map[i+1][j]&&q==this->map[i+2][j]&&q==this->map[i+3][j]&&q==this->map[i+4][j])
				        ||(q==this->map[i][j]&&q==this->map[i][j+1]&&q==this->map[i][j+2]&&q==this->map[i][j+3]&&q==this->map[i][j+4])
				        ||(q==this->map[i][j]&&q==this->map[i+1][j+1]&&q==this->map[i+2][j+2]&&q==this->map[i+3][j+3]&&q==this->map[i+4][j+4])) {
					blackwins = true;
				}
			}
		}
	}

	if(q==-1) {
		for(int i=0; i <GROUND_SIZE; i++) {
			for(int j=0; j <GROUND_SIZE; j++) {
				if((q==this->map[i][j]&&q==this->map[i+1][j]&&q==this->map[i+2][j]&&q==this->map[i+3][j]&&q==this->map[i+4][j])
				        ||(q==this->map[i][j]&&q==this->map[i][j+1]&&q==this->map[i][j+2]&&q==this->map[i][j+3]&&q==this->map[i][j+4])
				        ||(q==this->map[i][j]&&q==this->map[i+1][j+1]&&q==this->map[i+2][j+2]&&q==this->map[i+3][j+3]&&q==this->map[i+4][j+4])) {
					whitewins = true;
				}
			}
		}
	}

	if(blackwins) {
		return 1;
	} else if(whitewins) {
		return -1;
	} else return 0;



}

int Omok::getback(int x,int y) {
	return this->map[x][y];

}

ostream& operator<<(ostream& os, Omok& omok) {
	for (int i = 0; i < GROUND_SIZE; i++) {
		for (int j = 0; j < GROUND_SIZE; j++) {

			switch (omok.getback(i,j)) {
				case 0: {
					os << ". ";
					break;
				}
				case 1: {
					os << "o ";
					break;
				}
				case -1: {
					os << "x ";
					break;
				}
			}
		}
		os << endl;
	}
}
