#include "Empty_Set.h"
bool Empty::member(const unsigned int& num)const {
	return false;
}
void Empty::describe(std::ostream& out) const {
	out << "Empty set" << '\n';
}
Set* Empty::Clone()const {
	return new Empty(*this);
}






