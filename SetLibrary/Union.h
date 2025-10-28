#pragma once
#include "Set.h"
class Union : public Set {
public:
	virtual bool member(const unsigned int& num)const override;
	virtual void describe(std::ostream& out) const override;
	virtual Set* Clone()const override;
	Union(const Set*  ptr1, const Set*  ptr2);
	~Union()noexcept;
	Union(const Union& other);
	Union& operator =(const Union& other);


	
	
private:
	void Free()noexcept;
	void Copy(const Union& other);
	Set* First;
	Set* Second;
};




