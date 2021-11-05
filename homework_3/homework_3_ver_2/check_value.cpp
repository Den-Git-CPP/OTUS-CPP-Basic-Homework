#include <iostream>

int check_value(const int & target_value )
{
	int current_value = 0;
	int attempts_value= 0;
	bool not_win = true;

	std::cout << "Enter your guess:" << std::endl;

	do {
		std::cin >> current_value;
		attempts_value++;

		if (current_value < target_value) {
			std::cout<<"Nice try, but "<<current_value << " is less than Secret number "<< std::endl;
		}
		else if (current_value > target_value) {
			std::cout<<"Nice try, but "<<current_value << " is greater than Secret number  "<< std::endl;
		}
		else {
			std::cout << "You WIN! You attempts= "<<attempts_value<<std::endl;
			break;
		}

	} while(true);
return attempts_value;
};
	
