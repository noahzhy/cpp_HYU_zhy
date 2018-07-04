#include "2018000337_binary_search.h"

BinarySearch::BinarySearch(int *_array, int _arrayCount) {
	this->mArray = _array;
	this->mArrayCount = _arrayCount;
}

BinarySearch::~BinarySearch() {
	delete this->mArray;
};

int BinarySearch::getIndex(int _element) {
	int head = 0, tail = this->mArrayCount - 1;
	while (head <= tail) {
		int mid = (head + tail) / 2;
		if (this->mArray[mid] == _element) return mid;
		if (this->mArray[mid] > _element) tail = mid - 1;
		else head = mid + 1;
	}
	return -1;
}
