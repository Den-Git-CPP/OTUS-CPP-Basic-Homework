#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "save_table_score.h"

void save_table_score(const std::string& table_path, std::vector<std::pair<std::string, int>> table)
{
		// We should open the output file in the append mode - we don't want
		// to erase previous results.
		std::ofstream out_file{ table_path, std::ios_base::app };
		if (!out_file.is_open()) {
			std::cout << "Failed to open file for write: " << table_path << "!" << std::endl;
			exit(1);
		}

		for (auto elem:table )
		// Append new results to the table:
		{
		out_file << elem.first << ' ' << elem.second;
		out_file << std::endl;
		}
		
	

}
