#include <iostream>
#include <fstream>
#include <string>

#include "save_table_score.h"

void save_table_score(const std::string& table_path, const std::string& user_name, const int& attempts_count)
{
	// Write new high score to the records table
	{
		// We should open the output file in the append mode - we don't want
		// to erase previous results.
		std::ofstream out_file{ table_path, std::ios_base::app };
		if (!out_file.is_open()) {
			std::cout << "Failed to open file for write: " << table_path << "!" << std::endl;
			exit(1);
		}

		// Append new results to the table:
		out_file << user_name << ' ' << attempts_count;
		out_file << std::endl;
	} // end of score here just to mark end of the logic block of code

}
