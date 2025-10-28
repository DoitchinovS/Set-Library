#pragma once
#include "Set.h"
class Interval : public Set {
public:
	virtual bool member(const unsigned int& num)const override;
	virtual void describe(std::ostream& out) const override;
	virtual Set* Clone()const override;
	unsigned GetLower()const;
	unsigned GetUpper()const;
	Interval(const unsigned down, const unsigned up);
	
private:
	const unsigned int upper_bound;
	const unsigned int lower_bound;
};





