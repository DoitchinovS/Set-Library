#pragma once
#include "Set.h"
#include <functional>
#include <string>
class Filter :public Set {
public:
	virtual bool member(const unsigned int& num)const override;
	virtual void describe(std::ostream& out) const override;
	virtual Set* Clone()const override;
	Filter(Set*const def, std::function<unsigned(bool)>cond, std::string desc):definition_set(def->Clone())
		,Condition_Function(cond),description(desc)
	{
		if (!definition_set) {
			throw std::invalid_argument("Invalid pointer value is passed as a parameter");
		}
	
	}
	Filter(const Filter& other);
	Filter& operator =(const Filter& other);
	~Filter()noexcept;


private:
	Set* definition_set;
	std::function<unsigned(bool)> Condition_Function;
	std::string description;
	void Free()noexcept;// it is important to not throw an exc in a destructor
	void Copy(const Filter& other);
};






