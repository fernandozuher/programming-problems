#include <iostream>
#include <fstream> // ifstream
#include <string>
#include <vector>
#include <algorithm> // ranges::sort(), ranges::greater()
#include <sstream> // istringstream

using namespace std;

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

void find_most_calories(vector<string> input) {
	vector<int> calories_of_elves;

	for (int counter {0}, number; string line : input) {
		if (line.length()) {
			istringstream ( line ) >> number;
			counter += number;
		}
		else {
			calories_of_elves.push_back(counter);
			counter = 0;
		}
	}

	ranges::sort(calories_of_elves, ranges::greater());
	int max_calorie {calories_of_elves.front()};
	int sum_most_three_calories {calories_of_elves.at(0) + calories_of_elves.at(1) + calories_of_elves.at(2)};

	cout << "max_calorie: " << max_calorie << "\nsum_most_three_calories: " << sum_most_three_calories << "\n";
}

int main() {
	vector<string> input {read_input_from_file()};
	find_most_calories(input);
	return 0;
}
