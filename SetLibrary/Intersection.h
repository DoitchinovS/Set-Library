#pragma once
#include "Set.h"
class Intersection: public Set {
public:
	virtual bool member(const unsigned int& num)const override;
	virtual void describe(std::ostream& out) const override;
	virtual Set* Clone()const override;
	Intersection( const Set*  ptr1,  const Set*  ptr2);
	~Intersection()noexcept;
	Intersection(const Intersection& other);
	Intersection& operator =(const Intersection& other);


	


private:
	void Free()noexcept;
	void Copy(const Intersection& other);
	 Set*   First;
	 Set*   Second;


};





