#include <iostream>
#include "functions.h"

using std::cout, std::cin, std::endl;

int main() {
	// TODO(student): print prompt for input
	std::cout << "Enter numbers 10 <= a <= b < 10000: ";
	int a,b;
	std::cin >> a;
	std::cin >> b;
	
	// TODO(student): read the numbers from standard input
	
	// TODO(student): validate input (and reprompt on invalid input)
	bool val = is_valid_range(a,b);

	while(val == 0){

		std::cout << "Invalid Input" << std::endl;
		std::cout << "Enter numbers 10 <= a <= b < 10000: ";
		std::cin >> a;
		std::cin >> b;

		val = is_valid_range(a,b);
		
	}
	count_valid_mv_numbers(a,b);

	// TODO(student): compute and display solution
	
	return 0;
}