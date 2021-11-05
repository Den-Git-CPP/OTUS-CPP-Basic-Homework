#include <iostream>
#include <fstream>
#include <string>

#include <algorithm>
#include <vector>

#include "print_table_score.h"

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
		std::vector<std::pair<std::string, int>> table;

		table.reserve(5);

		while (true) {

			in_file >> username >> high_score;
			// Ignore the end of line symbol
			in_file.ignore();


			auto it = std::find_if(table.begin(), table.end(),
				[&](const auto& item) {
					return std::get<0>(item) == username;
				});

			if (it != table.end()) {
				// found username!
				
				if (std::get<1>(*it) > high_score)
				{
					table.erase(it);
					table.push_back(make_pair(username, high_score));
					
				};
			}
			else {
				//pair not found
				table.push_back(make_pair(username, high_score));

			}



			if (in_file.fail()) {
				break;
			};

		};


		for (auto elem : table) {
			std::cout << elem.first << " " << elem.second << std::endl;
		}

	}
}