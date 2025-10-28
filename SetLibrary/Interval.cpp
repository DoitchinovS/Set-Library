#include "Interval.h"
#include <cmath>
Interval::Interval(const unsigned down, const unsigned up): lower_bound(std::min(down,up)),upper_bound(std::max(down,up)) {
	//making sure there will be no problem with the bounds
}
unsigned Interval::GetLower()const {
	return this->lower_bound;
}
unsigned Interval::GetUpper()const {
	return this->upper_bound;
}
bool Interval::member(const unsigned int& num)const {
	return (num >= this->lower_bound && num <= this->upper_bound);
}
void Interval::describe(std::ostream& out) const {
	out << "a e " << "[" << this->lower_bound << "," << this->upper_bound<<"]"; //should it be U instead of "and"?
}
Set* Interval::Clone()const {
	return new Interval(*this);
}

