// Source: https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Result {

private:
    vector<int> _hurdles_heights;
    int _maximum_height_can_jump;
    int _doses;

    void _hurdle_race() {
        const int highest_hurdle = *ranges::max_element(_hurdles_heights);
        _doses = highest_hurdle > _maximum_height_can_jump ? highest_hurdle - _maximum_height_can_jump : 0;
    }

public:
    Result(const vector<int> hurdles_heights, const int maximum_height_can_jump) {
        _hurdles_heights = hurdles_heights;
        _maximum_height_can_jump = maximum_height_can_jump;
        _doses = 0;

        _hurdle_race();
        print_result();
    }

        void print_result() const {
            cout << _doses << "\n";
        }
};

vector<int> read_line_as_vector_int() {
    vector<int> input_line;
    string line;
    getline(cin, line);
    stringstream ss(line);

    for (int number; ss >> number; input_line.push_back(number));
    return input_line;
}

int main() {
    const vector<int> input_line {read_line_as_vector_int()};
    const int maximum_height_can_jump {input_line.back()};

    const vector<int> hurdles_heights {read_line_as_vector_int()};

    const Result result(hurdles_heights, maximum_height_can_jump);

    return 0;
}
