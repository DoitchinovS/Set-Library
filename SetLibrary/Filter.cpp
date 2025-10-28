#include "Filter.h"
bool Filter::member(const unsigned int& num)const {
	return(this->definition_set->member(num) && this->Condition_Function);
}
void Filter::describe(std::ostream& out) const {
	out << "{";
	definition_set->describe(out);
	out << "| "<<this->description<<"}";
}
Set* Filter::Clone()const {
	return new Filter(this->definition_set, this->Condition_Function,this->description);
}
void Filter::Free()noexcept {
	delete this->definition_set;
}
void Filter::Copy(const Filter& other) {
	this->description = other.description;
	this->Condition_Function = other.Condition_Function;
	this->definition_set = other.definition_set->Clone();
}
Filter::Filter(const Filter& other) {
	this->Copy(other);
}
Filter::~Filter()noexcept {
	this->Free();
}
Filter& Filter::operator =(const Filter& other) {
	if (this == &other)
		return *this;
	this->Free();
	this->Copy(other);
	return *this;
}





