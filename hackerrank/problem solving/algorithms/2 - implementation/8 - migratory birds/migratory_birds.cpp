// Source: https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=truehttps://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Result {

private:
	vector<int> _bird_sightings;
	int _most_spotted_bird;

	void migratory_birds() {
		_most_spotted_bird = _bird_sightings.front();
        int count_most_spotted_bird {1};
        int temp_count_most_spotted_bird {1};

        for (int i {1}, n {static_cast<int>(_bird_sightings.size())}; i < n; i++)

            if (_bird_sightings.at(i) == _bird_sightings.at(i - 1))
                temp_count_most_spotted_bird++;

            else if (temp_count_most_spotted_bird > count_most_spotted_bird) {
                _most_spotted_bird = _bird_sightings.at(i - 1);
                count_most_spotted_bird = temp_count_most_spotted_bird;
                temp_count_most_spotted_bird = 1;
            }

        if (temp_count_most_spotted_bird > count_most_spotted_bird)
            _most_spotted_bird = _bird_sightings.back();
	}

public:
	Result(const vector<int> _bird_sightings): _bird_sightings{_bird_sightings} {
		migratory_birds();
		print_result();
	}

		void print_result() const {
			cout << _most_spotted_bird;
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
	vector<int> bird_sightings {read_line_as_vector_int()};

	ranges::sort(bird_sightings);

	Result result(bird_sightings);

	return 0;
}
