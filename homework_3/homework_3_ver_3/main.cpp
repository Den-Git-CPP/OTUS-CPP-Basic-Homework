#define  DEFAULT_MAX_VALUE 100

#include <iostream>
#include <fstream>
#include <string>

#include <cstdlib>
#include <ctime>

#include "check_value.h"
#include "print_table_score.h"
#include "save_table_score.h"



int main(int argc, char** argv)
{
	// Arguments
	int parameter_value = 0;
	const std::string high_scores_filename = "high_scores.txt";


	if (argc <= 1) {
		std::cout << std::endl;
		std::cout << "If you want to set the MAX number, start the program with the parameter" << std::endl;
		std::cout << "Example '-max 42' " << std::endl;
		std::cout << "At this launch, the program will create its own secret number " << std::endl;
		std::cout << std::endl;

	}
	if (argc >= 2) {
		std::string arg1_value{ argv[1] };
		if (arg1_value == "-max") 
		{
			// We've detected the '-parameter' argument. And we extect that after this argument there is a value:
			if (argc < 3) {
				std::cout << "Wrong usage! The argument '-max' requires some value!" << std::endl;
				return -1;
			}

			// We need to parse the string to the int value
			parameter_value = std::stoi(argv[2]);
			std::cout << ">guess_the_number -max " << parameter_value << std::endl;
			std::cout << std::endl;

		}
		
		if (arg1_value == "-table")
		{
			std::cout << ">guess_the_number -table" << std::endl;
			std::cout << std::endl;

			print_table_score(high_scores_filename);// Read the high score file and print all results
			exit(1);
		}

	}

	
	// Ask about name
	std::cout << "Hi! Enter your name, please:" << std::endl;
	std::string user_name;
	std::cin >> user_name;

	int max_value = DEFAULT_MAX_VALUE;

	if(parameter_value!=0) max_value =parameter_value;

	srand(static_cast<int>(time(NULL)));
	const int random_value = std::rand() % max_value;
	std::cout << ">guess_the_number " << random_value << std::endl;


	std::cout << "Hi "
		<< user_name
		<< ";) Secret number is selected in range (1,"
		<< max_value
		<< ")"
		<< std::endl;

	int attempts_count{ 0 };
	attempts_count = check_value(random_value);

	// Write new high score to the records table
	save_table_score(high_scores_filename, user_name, attempts_count);

	// Read the high score file and print all results
	print_table_score(high_scores_filename);


	return 0;
}