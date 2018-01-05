#include <iostream>
#include "IntegerSet.h"

using namespace std;

//constructors
IntegerSet::IntegerSet()
{
	reset();
}

IntegerSet::IntegerSet(const int *arr, int size_)
{
	reset();
	
	for(int i = 0; i < size_; ++i){
		if(!elementExists(arr[i]))
			insertElement(arr[i]);
	}	
}

//union operation of 2 setstate
IntegerSet IntegerSet::unionOfSets(IntegerSet &is) const
{
	IntegerSet union_set;
	for(int i = 0; i < _limit; ++i) {
		if(elementExists(i) || is.elementExists(i))
			union_set.insertElement(i);
	}
	return union_set;
}

//intersection operation of 2 sets
IntegerSet IntegerSet::intersectionOfSets(IntegerSet &is) const
{
	IntegerSet intersection_set;
	for(int i = 0; i < _limit; ++i){
		if(elementExists(i) && is.elementExists(i))
			intersection_set.insertElement(i);
	}
	return intersection_set;
}

//override operator ==
bool IntegerSet::operator==(const IntegerSet &is) const
{
	for(int i = 0; i < _limit; ++i){
		if(elementExists(i) != is.elementExists(i))
			return false;
	}
	return true;
}

//print function
ostream &IntegerSet::printSet(ostream &out) const
{
	if(isEmpty())
		out << "---";
	else{
		for(int i = 0; i < _limit; ++i){
			if(elementExists(i))
				out << i << ' ';
		}
	}
	return out;
}

// utility functions
// reset _intSet to default values
void IntegerSet::reset()
{
	for(int i = 0; i < _limit; ++i){
		_intSet.push_back(false);
	}
}

//insert an element
void IntegerSet::insertElement(int k)
{
	if(k < 0 || k > 100)
		throw invalid_argument("element must be 0-100");
	else if(elementExists(k))
		throw invalid_argument("element already exists");
	else
		_intSet[k] = true;
}

//delete an element
void IntegerSet::deleteElement(int k)
{
	if(k < 0 || k > 100)
		throw invalid_argument("element must be 0-100");
	else if(!elementExists(k))
		throw invalid_argument("element doesn't exist");
	else
		_intSet[k] = false;
}

//check element existence
bool IntegerSet::elementExists(int k) const 
{
	return _intSet[k];
}

//check whether this integer set is empty
bool IntegerSet::isEmpty() const
{
	/*for(int i = 0; i < _limit; ++i){
		if(elementExists(i))
			return false;
	}*/
	for(bool item : _intSet){
		if(item)
			return false;
	}
	return true;
}







