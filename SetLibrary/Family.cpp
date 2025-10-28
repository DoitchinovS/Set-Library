#include "Family.h"
#include "Intersection.h"
#include "Union.h"
void Family::Free()noexcept {
	for (size_t i = 0; i <size; ++i) {
		delete sets[i];
	}
	delete[] sets;
	sets = nullptr;
}
Family::~Family()noexcept {
	this->Free();
}
void Family::Copy(const Family& other) {
	this->size = other.size;
	this->capacity = other.capacity;
	this->sets = new Set* [this->capacity];
	
	for (size_t i = 0; i < size; ++i) {
		sets[i] = other.sets[i]->Clone();//Making a deep copy of the pointer
	}
	
}
void Family::Resize() {
	Set** anotherSets = new Set * [this->capacity *= 2];
	for (size_t i = 0; i < size; ++i) {
		anotherSets[i] = this->sets[i];
	}
	delete []sets;
	sets = anotherSets;
}
void Family::AddSet(Set*const newSet) {
	if (!newSet) { return; } //could also throw an exception, but this also works out
	if (size == capacity)
		Resize();
	this->sets[size++] = newSet->Clone();
}
bool Family::member(const unsigned int& num)const {
	bool ismem = false;
	for (size_t i = 0; i < size; ++i) {
		if (sets[i]->member(num))
			ismem = true;
		break;
	}
	return ismem;
}
void Family::describe(std::ostream& out) const {
	for (size_t i = 0; i < size; ++i) {
		sets[i]->describe(out);
		if (i < size - 1)
			out << ",";
	}
}
Set* Family::Clone()const {
	return new Family(*this);
}
Family::Family(const Family& other) {
	this->Copy(other);
}
Family& Family::operator+=( Set*const other) {
	this->AddSet(other);
	return *this;
}
Family Family::operator+(Set* const other) const {
	Family result=*this;
	if (result.size == result.capacity)
		result.Resize();
	result.sets[result.size++] = other->Clone();
	return result;
}
Family& Family::operator =(const Family& other) {
	if (this == &other)
		return *this;

	this->Free();
	this->Copy(other);
	return *this;

}
Set* Family::find_total_intersection() {
	Set* intersect = this->sets[0]->Clone();
	for (size_t i = 1; i < size; ++i) {
		Set* temporary = new Intersection(intersect, this->sets[i]);
		delete intersect;
		intersect = temporary; //without clone, because we don't want to waste so much memory
	}
	return intersect;
}

Set* Family::find_total_union() {
	Set* un = this->sets[0]->Clone();
	for (size_t i = 1; i < size; ++i) {
		Set* temporary = new Union(un, this->sets[i]);
		delete un;
		un = temporary;
	}
	return un;
}





