#include "Union.h"
void Union::Free()noexcept {
	delete this->First;
	delete this->Second;
}
void Union::Copy(const Union& other) {
	this->First = other.First->Clone();
	this->Second = other.Second->Clone();
}
Union::Union(const Union& other) {
	this->Copy(other);
}
Union& Union::operator =(const Union& other) {
	if (this == &other)
		return *this;
	this->Free();
	this->Copy(other);
	return *this;

}

Union::~Union()noexcept {
	this->Free();
}
Union::Union(const Set*  ptr1, const Set*  ptr2) {
	if (!ptr1 || !ptr2) {
		throw std::invalid_argument("Invalid pointer value is passed as a parameter");
	}
	this->First = ptr1->Clone();
	this->Second = ptr2->Clone();
}
Set* Union::Clone()const {
	return new Union(*this);
}
bool Union::member(const unsigned int& num)const {
	return(First->member(num) || Second->member(num));
}
void Union::describe(std::ostream& out) const {
	First->describe(out);
	out << " U ";
	Second->describe(out);
}

