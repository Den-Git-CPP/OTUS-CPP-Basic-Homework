// Read files and prints top k word by frequency

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <chrono>

#include<mutex>
#include<future>

const size_t TOPK = 10;
using Counter = std::map<std::string, std::size_t>;
static std::mutex mtx1, mtx2;

std::string tolower(const std::string& str);
void count_words(std::istream& stream, Counter&);
void print_topk(std::ostream& stream, const Counter&, const size_t k);

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cerr << "Usage: topk_words [FILES...]\n";
		return EXIT_FAILURE;
	}
	std::cout << "=========\n";
	std::cout << "Hardware Concurrency: ";
	std::cout << std::thread::hardware_concurrency() << std::endl;//максим количество потоков 
	std::cout << "=========\n";
	std::cout << "Thread \'Main\':\t\t" << std::this_thread::get_id() << std::endl;// поток main
	std::cout << "=========\n";
	Counter freq_dict;

	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 1; i < argc; ++i) {
		std::ifstream input{ argv[i] };
		if (!input.is_open()) {
			std::cerr << "Failed to open file " << argv[i] << '\n';
			return EXIT_FAILURE;
		}
		std::thread thr1{ count_words, std::ref(input), std::ref(freq_dict) };// поток 1
		if (thr1.joinable())
			thr1.join();
	}
	auto f2=std::async(std::launch::async, print_topk, std::ref(std::cout), std::cref(freq_dict), std::cref(TOPK));//2 поток
	f2.get();
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << "Elapsed time is " << elapsed_ms.count() << " us\n";
}
 
std::string tolower(const std::string& str) {
	std::string lower_str;
	std::transform(	std::cbegin(str), std::cend(str),
		std::back_inserter(lower_str),
		[](unsigned char ch) { return std::tolower(ch); });
	return lower_str;
}

void count_words(std::istream& stream, Counter& counter) {
	std::lock_guard<std::mutex> lk(mtx1);
	std::cout << "Thread \'Count_words\':\t\t" << std::this_thread::get_id() << std::endl;// поток Count_words
	std::for_each(
		std::istream_iterator<std::string>(stream),
		std::istream_iterator<std::string>(),
		[&counter](const std::string& s) { ++counter[tolower(s)]; });
}

void print_topk(std::ostream& stream, const Counter& counter, const size_t k) {
	std::cout << "Thread \'Print_topk\':\t\t" << std::this_thread::get_id() << std::endl;// поток Print_topk
	std::lock_guard<std::mutex> lk(mtx2);
	std::vector<Counter::const_iterator> words;
	words.reserve(counter.size());
	
	for (auto it = std::cbegin(counter); it != std::cend(counter); ++it) {
		words.push_back(it);
	}
	
	std::partial_sort(std::begin(words), std::begin(words) + k, std::end(words),
		[](auto lhs, auto& rhs) {return lhs->second > rhs->second; });

	std::for_each(
		std::begin(words), std::begin(words) + k,
		[&stream](const Counter::const_iterator& pair) {
			stream << std::setw(4) << pair->second << " " << pair->first
				<< '\n';
		});
}