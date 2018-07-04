#include <iostream>
#include <algorithm>
#include <vector>
#include "sorted_array.h"
using namespace std;

SortedArray::SortedArray(){};
SortedArray::~SortedArray(){
this->numbers_.clear();};

void SortedArray::AddNumber(int num) {
	this->numbers_.push_back(num);
};

vector<int> SortedArray::GetSortedAscending()const {
	vector<int> v0 = this->numbers_;
	sort(v0.begin(), v0.end());
	return v0;
};
vector<int> SortedArray::GetSortedDescending()const {
	vector<int> v1 = this->numbers_;
	sort(v1.rbegin(), v1.rend());
	return v1;
};

int SortedArray::GetMax() const {
	
	vector<int> v3 = this->numbers_;
vector<int>::iterator biggest = max_element(v3.begin(), v3.end());
	return *biggest;
};
int SortedArray::GetMin() const {
	vector<int> v4 = this->numbers_;
	vector<int>::iterator smallest = min_element(v4.begin(), v4.end());
	return *smallest;
};
