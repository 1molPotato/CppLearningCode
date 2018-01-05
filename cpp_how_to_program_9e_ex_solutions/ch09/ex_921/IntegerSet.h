#pragma once

#include <vector>
#include <iostream>

class IntegerSet
{
public:
	IntegerSet();//default constructor
	IntegerSet(const int *arr, int size_);
	
	//common set operations
	IntegerSet unionOfSets(IntegerSet &is) const;
	IntegerSet intersectionOfSets(IntegerSet &is) const;
	bool operator==(const IntegerSet &is) const;
	bool operator!=(const IntegerSet &is) const{
		return !operator==(is);
	}
	
	//utility functions
	void insertElement(int k);//insert integer k to this set
	void deleteElement(int k);//delete integer k from this set
	bool elementExists(int k) const;//integer k has existed
	bool isEmpty() const;//is this set empty
	
	friend std::ostream &operator<<(std::ostream &out, IntegerSet &is){
		return is.printSet(out);//inline print function
	}
	
	std::ostream &printSet(std::ostream &out) const;
	
private:
	static const int _limit = 101;
	
	std::vector<bool> _intSet;
	
	void reset();//utility function only used by constructors
};