// Source: https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Result {

private:
	vector<int> _chocolate_squares;
	int _day, _month;
	int _ways_bar_can_be_divided;

	void birthday() {
		for (int i {0}, n1 {static_cast<int>(_chocolate_squares.size()) - _month + 1}; i < n1; i++) {
			int sum {0};
			for (int j {i}, n2 {i + _month}; j < n2; sum += _chocolate_squares[j++]);
			if (sum == _day)
				_ways_bar_can_be_divided++;
		}
	}

public:
	Result(const vector<int> chocolate_squares, const vector<int> day_month) {
		_chocolate_squares = chocolate_squares;
		_day = day_month.at(0);
		_month = day_month.at(1);
		_ways_bar_can_be_divided = 0;

		birthday();
		print_result();
	}

		void print_result() const {
			cout << _ways_bar_can_be_divided;
		}
};

vector<int> read_line_as_vector_int() {
	vector<int> numbers;
	string line;
	getline(cin, line);
	stringstream ss(line);

	for (int number; ss >> number; numbers.push_back(number));
	return numbers;
}

int main() {
	read_line_as_vector_int();
	vector<int> chocolate_squares {read_line_as_vector_int()};
	vector<int> day_month {read_line_as_vector_int()};

	Result result(chocolate_squares, day_month);

	return 0;
}
