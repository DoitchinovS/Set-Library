#pragma once
#include "Set.h"
#include <functional>
#include<string>
class Series : public Set {
public:
	virtual bool member(const unsigned int& num)const override;
	virtual void describe(std::ostream& out) const override;
	virtual Set* Clone()const override;
	Series(Set* Init, std::function<unsigned(unsigned)> func, std::string descr):Initial_set(Init->Clone()),
		Condition(func),description(descr){
	
		if (!Initial_set) {
			throw std::invalid_argument("Invalid pointer value is passed as a parameter");
		}
	
	}
	~Series()noexcept;
	Series(const Series& other);
	Series& operator =(const Series& other);
private:
	Set* Initial_set;
	std::function<unsigned(unsigned)> Condition;
	std::string description;
	void Copy(const Series& other);
	void Free()noexcept;

};






