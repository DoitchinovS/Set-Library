#pragma once
#include "Set.h"
class Empty :public Set {
public:
	virtual bool member(const unsigned int& num)const override;
	virtual void describe(std::ostream& out) const override;
	virtual Set* Clone()const override;
	virtual ~Empty() = default;
private:
	// no data members

};





