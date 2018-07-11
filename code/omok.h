#pragma once
#include <ostream>

using namespace std;

#define BLACK -1
#define NOBODY 0
#define WHITE 1
#define GROUND_SIZE 19

class Omok {
	private:
		size_t width_, height_;
		int turn_;
		int map[GROUND_SIZE][GROUND_SIZE];
	public:
		Omok(): width_(GROUND_SIZE), height_(GROUND_SIZE), turn_(NOBODY) {
			for (int i = 0; i < GROUND_SIZE; i++) {
				for (int j = 0; j < GROUND_SIZE; j++) {
					map[i][j] = 0;
				}
			}
		};
		int put(int x, int y, int black_or_white);
		int getback(int x, int y);
		int check(int q);

		void IsOmok(int *winner) const;
		int Turn() const {
			return turn_;
		}

};

ostream& operator<<(ostream& os, Omok& omok);
