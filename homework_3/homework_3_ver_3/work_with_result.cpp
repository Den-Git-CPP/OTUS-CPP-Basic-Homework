#include <iostream>
#include <fstream>
#include <string>

#include <algorithm>
#include <vector>

#include "work_with_result.h"

std::vector<std::pair<std::string, int>> Best_result(const std::string& table_path, const std::string& user_name,const int& attempts_count)
{  
     
       
	   //  file
		std::ifstream in_file{ table_path,std::ios_base::app };
		if (!in_file.is_open()) {
			std::cout << "Failed to open file for read: " << table_path << "!" << std::endl;
			exit(1);
		}
	
        //temp table
		   
    	std::string username_table;
		int high_score_table = 0;

		std::vector<std::pair<std::string, int>> table_tmp;
		table_tmp.reserve(5);
		while (true) {

			in_file >> username_table >> high_score_table;
			in_file.ignore();// Ignore the end of line symbol
			
            auto it = std::find_if(table_tmp.begin(), table_tmp.end(),
                                [&](const auto& item) {
					            return std::get<0>(item) == user_name;
				});
			if (it != table_tmp.end()){
				// found username!
				//best  attempt? save it with change
				if (std::get<1>(*it) > attempts_count){
					table_tmp.erase(it);
					table_tmp.push_back(make_pair(user_name, attempts_count));
				};
			}
			else {
                // first game or username not found
				////not best? ok save old result
				table_tmp.push_back(make_pair(user_name, attempts_count));
			}

			if (in_file.fail()) {
				break;
			};

		};

	

 return table_tmp;
}