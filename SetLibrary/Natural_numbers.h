#pragma once
#include "Set.h"
class Natural : public Set {
public:
	virtual bool member(const unsigned int& num)const override;
	virtual void describe(std::ostream& out) const override;
	virtual Set* Clone()const override;
	virtual ~Natural() = default;
private:



};




