#include "Intersection.h"

void Intersection::Free()noexcept {
	delete this->First;
	delete this->Second;
}
void Intersection::Copy(const Intersection& other) {
	this->First = other.First->Clone();
	this->Second = other.Second->Clone();
}
Intersection& Intersection::operator =(const Intersection& other) {
	if (this == &other)
		return *this;
	this->Free();
	this->Copy(other);
	return *this;

}
Intersection::~Intersection() {
	this->Free();
}
Intersection::Intersection(const Set*  ptr1,  const Set*  ptr2) {
	if (!ptr1 || !ptr2) {
		throw std::invalid_argument("Invalid pointer value is passed as a parameter");
	}
	this->First = ptr1->Clone();
	this->Second = ptr2->Clone();
}
Intersection::Intersection(const Intersection& other) {
	this->Copy(other);
}
Set* Intersection::Clone()const {
	return new Intersection(*this);
}
bool Intersection::member(const unsigned int& num)const {
	return (First->member(num) && Second->member(num));
}
void Intersection::describe(std::ostream& out) const {
	out << "{";
	First->describe(out);
	out << "}";
	out << " n ";
	out << "{";
	Second->describe(out);
	out << "}";
}

