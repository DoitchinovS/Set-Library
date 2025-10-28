#include "Series.h"
#include <iostream>
bool Series::member(const unsigned int& num)const {
	for (size_t i = 0; i < 100; ++i) {
		if (Initial_set->member(i) && num == this->Condition(i)) {
			return true;
		}
	}
	return false;
}
void Series::describe(std::ostream& out) const {
	out << "{" << this->description << " |";
	this->Initial_set->describe(out);
	out << " }";
}
Set* Series::Clone()const {
	return new Series(*this);
}
void Series::Free()noexcept {
	delete this->Initial_set;
}
void Series::Copy(const Series& other) {
	this->Initial_set = other.Initial_set->Clone();
	this->Condition = other.Condition;
	this->description = other.description;
}
Series::Series(const Series& other) {
	this->Copy(other);
}
Series::~Series()noexcept {
	this->Free();
}
Series& Series::operator =(const Series& other) {
	if (this == &other)
		return *this;
	this->Free();
	this->Copy(other);
	return *this;
}




