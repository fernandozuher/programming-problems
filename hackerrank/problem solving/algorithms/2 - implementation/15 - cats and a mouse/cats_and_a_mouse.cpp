// Source: https://www.hackerrank.com/challenges/cats-and-a-mouse/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Result {

private:
    vector<vector<int>> _cats_and_mouse_positions_lines;
    vector<string> _result;

    void _cat_and_mouse() {
        for (const vector<int> cats_and_mouse_positions : _cats_and_mouse_positions_lines)
            _find_nearest_cat_or_not(cats_and_mouse_positions);
    }

        void _find_nearest_cat_or_not(const vector<int> cats_and_mouse_positions) {
            const int cat_a_position = cats_and_mouse_positions.at(0);
            const int cat_b_position = cats_and_mouse_positions.at(1);
            const int mouse_position = cats_and_mouse_positions.at(2);

            const int cat_a_position_difference = abs(cat_a_position - mouse_position);
            const int cat_b_position_difference = abs(cat_b_position - mouse_position);

            _set_string_result(cat_a_position_difference, cat_b_position_difference);
        }

            void _set_string_result(const int cat_a_position_difference, const int cat_b_position_difference) {
                if (cat_a_position_difference < cat_b_position_difference)
                    _result.push_back("Cat A");
                else if (cat_a_position_difference > cat_b_position_difference)
                    _result.push_back("Cat B");
                else
                    _result.push_back("Mouse C");
            }

public:
    Result(const vector<vector<int>> cats_and_mouse_positions_lines) {
        _cats_and_mouse_positions_lines = cats_and_mouse_positions_lines;

        _cat_and_mouse();
        print_result();
    }

        void print_result() const {
            for (string result : _result)
                cout << result << "\n";
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

vector<vector<int>> read_cats_and_mouse_positions_lines(const int n) {
    vector<vector<int>> cats_and_mouse_positions_lines(n);
    string line;

    for (int i {0}; getline(cin, line); i++) {
        stringstream ss(line);
        for (int number; ss >> number; cats_and_mouse_positions_lines.at(i).push_back(number));
    }

    return cats_and_mouse_positions_lines;
}

int main() {
    vector<int> input_line {read_line_as_vector_int()};
    const int n {input_line.front()};

    vector<vector<int>> input_lines {read_cats_and_mouse_positions_lines(n)};

    Result result(input_lines);

    return 0;
}
