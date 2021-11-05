#include <iostream>
#include <fstream>
#include <string>

void print_table_score(const std::string& table_path)
{
	// Read the high score file and print all results
	{
		std::ifstream in_file{ table_path };
		if (!in_file.is_open()) {
			std::cout << "Failed to open file for read: " << table_path << "!" << std::endl;
			exit(1);
		}

		std::cout << "High scores table:" << std::endl;

		std::string username;
		int high_score = 0;
		while (true) {

			in_file >> username >> high_score;
			// Ignore the end of line symbol
			in_file.ignore();

			if (in_file.fail()) {
				break;
			}

			// Print the information to the screen
			std::cout << username << '\t' << high_score << std::endl;
		}
	}
}