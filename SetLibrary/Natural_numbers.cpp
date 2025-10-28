#include "Natural_numbers.h"
 bool Natural::member(const unsigned int& num)const {
	 return (num != 0);// 0 is not natural
}
 Set* Natural::Clone()const {
	 return new Natural(*this);
 }
 void Natural::describe(std::ostream& out) const {
	 out << "{a|" << " a e N}" << '\n';
 }






