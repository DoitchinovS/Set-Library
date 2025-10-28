#pragma once
#include <iostream>
//class Intersection;
//class Union;
class Set {
public:
	virtual bool member(const unsigned int& num)const=0;
	virtual void describe(std::ostream& out) const=0;
	virtual Set* Clone()const = 0;
	virtual ~Set() {};

	friend Set* operator&& (const  Set& first, const Set& second);
		
	
	friend Set* operator ||(const  Set& first,  const Set& second);

private:
	// we don't have any data members in the base class,
	//because each set has its unique members

};
 








