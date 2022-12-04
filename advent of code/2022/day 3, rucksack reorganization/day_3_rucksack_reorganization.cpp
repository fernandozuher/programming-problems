#include <iostream>

#include <vector>
#include <unordered_set>

#include <fstream>
#include <algorithm>

using namespace std;

class Rucksack_Reorganization {

private:
	int sum, sum2;

	void find_common_item_types(const vector<string> input) {
		for (int i {0}, index_item_in_group {2}, n {static_cast<int>(input.size())}; i < n; i++, index_item_in_group += 3) {

			this->sum += common_item_in_ruckstack(input.at(i));

			if (int i = index_item_in_group; index_item_in_group < n) {
				vector<string> last_3_rucksacks {input.at(i - 2), input.at(i - 1), input.at(i)};
				this->sum2 += common_item_in_group(i, last_3_rucksacks);
			}
		}
	}

		int common_item_in_ruckstack(const string line) const {
			string first_half_items {line.substr(0, line.length() / 2)};
			string second_half_items {line.substr(line.length() / 2)};

			unordered_set<char> deduplicated_first_half_items(first_half_items.begin(), first_half_items.end());
			unordered_set<char> deduplicated_second_half_items(second_half_items.begin(), second_half_items.end());

			int common_item_value {find_common_item_in_ruckstack(deduplicated_first_half_items, deduplicated_second_half_items)};
			return common_item_value;
		}

			int find_common_item_in_ruckstack(const unordered_set<char> deduplicated_first_half_items, const unordered_set<char> second_half_items) const {
				int common_item_value {0};
				for (auto first_half_item : deduplicated_first_half_items)
					if (second_half_items.find(first_half_item) != second_half_items.end()) {
						common_item_value = convert_item_to_value(first_half_item);
						break;
					}
				return common_item_value;
			}

				int convert_item_to_value(const char item) const {
					return (item >= 65 && item <= 90) ? item - 'A' + 27 : item - 'a' + 1;
				}
		
		int common_item_in_group(const int index, const vector<string> last_3_rucksacks) const {
			sort_vector_based_on_size(last_3_rucksacks);
			int common_item_value {find_common_item_in_group(last_3_rucksacks)};
			return common_item_value;
		}

			void sort_vector_based_on_size(vector<string> input_vector) const {
				auto compare_item_sizes = [] (const std::string & first, const std::string & second) {
					return first.size() < second.size();
				};
				ranges::sort(input_vector, compare_item_sizes);
			}
				
			int find_common_item_in_group(const vector<string> last_3_rucksacks) const {
				string smallest_rucksack {last_3_rucksacks.front()};
				string rucksack2 {last_3_rucksacks.at(1)};
				string rucksack3 {last_3_rucksacks.at(2)};

				int common_item_value {0};
				for (auto item : smallest_rucksack)
					if (rucksack2.contains(item) && rucksack3.contains(item)) {
						common_item_value = convert_item_to_value(item);
						break;
					}
				return common_item_value;
			}

public:
	Rucksack_Reorganization(const vector<string> input): sum(0), sum2(0) {
		find_common_item_types(input);
		print_sums();
	}

	void print_sums() const {
		cout << "sum: " << sum << "\n";
		cout << "sum2: " << sum2 << "\n";
	}
};

vector<string> read_input_from_file() {
	ifstream file("input.txt");

	if (!file.is_open()) {
		cout << "\nError in opening file.\n";
		exit(EXIT_FAILURE);
	}

	vector<string> input;
	for (string line; getline(file, line); input.push_back(line));
	return input;
}

int main() {
	vector<string> input {read_input_from_file()};
	Rucksack_Reorganization reorganization(input);
	return 0;
}
