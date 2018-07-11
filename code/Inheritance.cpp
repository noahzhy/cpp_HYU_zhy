#include <iostream>
#include <string>
using namespace std;

struct StudentInfo
{
public:
	StudentInfo(int _id, string _name, int _score) {
		id = _id;
		name = _name;
		score = _score;
	}
	int ShowInfo()const {
		cout << id << "|" << name << "|" << score << endl;
		return 0;
	}

	int id;
	string name;

protected:
	int score;

};

class StudentInfoEx: public StudentInfo
{
	string GetName();
	int GetScore();

};

string StudentInfoEx::GetName() {
	return name;
}


int StudentInfoEx::GetScore() {
	return score;
}

int main() {
	return 0;
}