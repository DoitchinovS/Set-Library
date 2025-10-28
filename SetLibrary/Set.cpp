#include "Set.h"
#include"Union.h"
#include "Intersection.h"

Set* operator&& (const Set& first, const Set& second) {
	return new Intersection(&first, &second);
}
Set* operator || ( const Set&  first, const Set& second) {
	return new Union(&first, &second);
}




