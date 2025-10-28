#include "Interval.h"
#include "Intersection.h"
#include "Union.h"
#include "Family.h"
#include "Series.h"
#include "Filter.h"

#include <iostream>

int main()
{

	Set* even_or_square;
	Set* even_and_square;


	try {
		/*Interval myint(5, 8);
		Interval myint2(6, 9);
		Interval myint3(8, 10);
		Intersection intersec1(&myint, &myint2);
		Union myun1(&myint, &myint2);
		myun1.describe(std::cout);
		std::cout << std::endl;
		intersec1.describe(std::cout);
		std::cout << '\n';*/
		//std::cout << myun1.member(7) << " " << intersec1.member(8);

		//Family myf;
		//myf.AddSet(&myint);
		//myf.AddSet(&myint2);
		//myf.AddSet(&myint3);
		////myf +=& myun1;
		///*myf.describe(std::cout);
		//Set* s = myf.find_total_intersection();
		//std::cout << '\n' << s->member(8) << " " << s->member(7)<<"\n";
		//s->describe(std::cout);*/
		//Interval myint4(13, 18);
		//Family f2;
		//f2 = myf + &myint4;
		//f2.describe(std::cout);
		//Interval int1(2, 10);
		//Interval int2(7, 12);
		//Set* set_1 = int1 && int2;
		//set_1->describe(std::cout);

		//Series ser1(&int1, [](unsigned a) {return a * a; }, "a*a");
		//ser1.describe(std::cout);
		//Filter filt1(&int1, [](unsigned a) {return a % 3 == 0; }, "a is divisible by 3");
		////filt1.describe(std::cout);
		//Set* intter = filt1 && int2;
		//intter->describe(std::cout);
		Interval i(0, 100);
		Interval i2(0, 10);
		Filter f1(&i, [](unsigned a) {return a % 4; }, "a is divisible by 4");
		Series s1(&i2, [](unsigned n) {return n * n; }, "a*a");
		Set* evens = &f1;
		Set* squares = &s1;
		 even_or_square = *evens || *squares;
		 even_and_square = *evens && *squares;
		evens->describe(std::cout);
		std::cout << "\n";
		even_or_square->describe(std::cout);
		std::cout << '\n';
		Family family;
		(family += even_or_square) += even_and_square;
		//family += even_and_square;
		family.describe(std::cout);
		delete even_or_square;
		delete even_and_square;
	}
	catch (std::invalid_argument const& ex) {
		delete even_and_square;
		delete even_or_square;
		
		std::cerr << ex.what() << "\n";
	}
	catch (std::bad_alloc&) {
		delete even_and_square;
		delete even_or_square;
		std::cerr << "Bad alloc!\n";
	}
}


