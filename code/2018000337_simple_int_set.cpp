#include <iostream>
#include <set>
#include "2018000337_simple_int_set.h"
using namespace std;

//SimpleIntSet::SimpleIntSet() {
//	this->mElements = _elements[99];
//	this->mElementCount = _count;
//}

SimpleIntSet::~SimpleIntSet() {
	delete mElements;
}

SimpleIntSet::SimpleIntSet(int *_elements, int _count) {
	this->mElements = _elements;
	this->mElementCount = _count;
}

int* SimpleIntSet::elements() const {
	return this->mElements;
} // return sorted array
int SimpleIntSet::elementCount() const {
	return this->mElementCount;
}

SimpleIntSet* SimpleIntSet::unionSet(SimpleIntSet & _operand) {
	set<int> A(this->elements(), this->elements() + this->elementCount());
	set<int> B(_operand.elements(), _operand.elements() + _operand.elementCount());
	set<int>::iterator it;
	set<int> result;
	it = A.begin();
	while(it != A.end()) {
		result.insert(*it);
		it++;
	}

	it = B.begin();
	while(it != B.end()) {
		result.insert(*it);
		it++;
	}
	it = result.begin();
	this->mElementCount = 0;
	while(it != result.end()) {
		this->mElements[this->mElementCount] = *it;
		it++;
		this->mElementCount++;
	}
}

SimpleIntSet* SimpleIntSet::differenceSet(SimpleIntSet & _operand) {
	set<int> A(this->elements(), this->elements() + this->elementCount());
	set<int> B(_operand.elements(), _operand.elements() + _operand.elementCount());
	set<int>::iterator it;
	set<int> result;

	it = A.begin();
	while(it != A.end()) {
		if(B.find(*it) == B.end()) result.insert(*it);
		it++;
	}
	it = result.begin();
	this->mElementCount = 0;
	while(it != result.end()) {
		this->mElements[this->mElementCount] = *it;
		it++;
		this->mElementCount++;
	}

}


SimpleIntSet* SimpleIntSet::intersectSet(SimpleIntSet & _operand) {
	set<int> A(this->elements(), this->elements() + this->elementCount());
	set<int> B(_operand.elements(), _operand.elements() + _operand.elementCount());
	set<int>::iterator it;
	set<int> result;
	it = A.begin();
	while(it != A.end()) {
		result.insert(*it);
		it++;
	}

	it = B.begin();
	while(it != B.end()) {
		result.insert(*it);
		it++;
	}

	it = result.begin();
	this->mElementCount = 0;
	while(it != result.end()) {
		this->mElements[this->mElementCount] = *it;
		it++;
		this->mElementCount++;
	}

}


void SimpleIntSet::printSet() {
	cout << "{ ";
	int *a = this->elements();
	for(int i = 0; i < this->elementCount(); i++) {
		cout << a[i]<<" ";
	}
	cout << "}"<<endl;
}

