#pragma once
#include "Set.h"
class Family : public Set {
public:
	virtual bool member(const unsigned int& num)const override;
	virtual void describe(std::ostream& out) const override;
	virtual Set* Clone()const override;
	Family() :capacity(10), size(0), sets(new Set* [capacity]) {}
	Family(const Family& other);
	~Family()noexcept;
	Family& operator =(const Family& other);
	
	Family& operator +=( Set* const newSet);
	Family operator +( Set* const newSet)const;

	Set* find_total_intersection();
	Set* find_total_union();


	void AddSet(Set* const newSet);
private:
	size_t capacity;
	size_t size; // if we want to use initializing list, sets should be declared last
	Set** sets;
	void Free()noexcept;
	void Copy(const Family &other);
	void Resize();
};





