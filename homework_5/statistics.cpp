#include <iostream>
#include <limits>
#include "IStatistics.h"

#include "Min.h"
#include "Max.h"
#include "Mean.h"
#include "Std.h"

int main() {

	const size_t statistics_count = 4;
	IStatistics* statistics[statistics_count];

	statistics[0] = new Min{};
	statistics[1] = new Max{};
	statistics[2] = new Mean{};
	statistics[3] = new Std{};

	std::cout<<"Enter a sequence of numbers.\n"
	<<"After stopping typing, press the keyboard shortcuts Enter and then\n"
	<<"For Windows\tCTRL+Z, ENTER\n"
	<<"For Linux\tCTRL+D\n";

	double val = 0;
	while (std::cin >> val) {
		for (size_t i = 0; i < statistics_count; ++i) {
			statistics[i]->update(val);
		}
	}

	// Handle invalid input data
	if (!std::cin.eof() && !std::cin.good()) {
		std::cerr << "Invalid input data\n";
		return 1;
	}

	// Print results if any
	for (size_t i = 0; i < statistics_count; ++i) {
		std::cout << statistics[i]->name() << " = " << statistics[i]->eval() << std::endl;
	}

	// Clear memory - delete all objects created by new
	for (size_t i = 0; i < statistics_count; ++i) {
		delete statistics[i];
	}

	return 0;

}