#include <iostream>
#include <fstream> // ifstream
#include <vector>

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

void choose_x(vector<int> &total_score, char opponent_choice) {
	total_score.at(0) += 1;

	if (opponent_choice == 'A') {
		total_score.at(0) += 3;
		total_score.at(1) += 3;
	}
	else if (opponent_choice == 'B')
		total_score.at(1) += 1;
	else {
		total_score.at(0) += 6;
		total_score.at(1) += 2;
	}
}

void choose_y(vector<int> &total_score, char opponent_choice) {
	total_score.at(0) += 2;
	total_score.at(1) += 3;
	if (opponent_choice == 'A') {
		total_score.at(0) += 6;
		total_score.at(1) += 1;
	}
	else if (opponent_choice == 'B') {
		total_score.at(0) += 3;
		total_score.at(1) += 2;
	}
	else
		total_score.at(1) += 3;
}

void choose_z(vector<int> &total_score, char opponent_choice) {
	total_score.at(0) += 3;
	total_score.at(1) += 6;
	if (opponent_choice == 'A')
		total_score.at(1) += 2;
	else if (opponent_choice == 'B') {
		total_score.at(0) += 6;
		total_score.at(1) += 3;
	}
	else {
		total_score.at(0) += 3;
		total_score.at(1) += 1;
	}
}

void calculate_total_score(vector<string> input) {
	// A, X = Rock; B, Y = Paper; C, Z = Scissor

	vector total_score {0, 0};
	for (auto line : input) {
		char opponent_choice {line.at(0)}, my_choice {line.at(2)};
		if (my_choice == 'X')
			choose_x(total_score, opponent_choice);
		else if (my_choice == 'Y')
			choose_y(total_score, opponent_choice);
		else
			choose_z(total_score, opponent_choice);
	}

	cout << "total_score_1: " << total_score.front() << "\ntotal_score_2: " << total_score.back();
}

int main() {
	vector<string> input {read_input_from_file()};
	calculate_total_score(input);

	return 0;
}
