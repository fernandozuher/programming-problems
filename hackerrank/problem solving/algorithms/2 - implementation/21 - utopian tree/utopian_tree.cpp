// Source: https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;


class Result {

private:
    vector<int> _n_test_cases_cycles;
    vector<int> _trees_heights;

    void _utopian_tree() {
        int i {0};
        auto lambda_expression = [&i, this]() {return _calculate_height(_n_test_cases_cycles.at(i++));};
        generate(_trees_heights.begin(), _trees_heights.end(), lambda_expression);
    }

        int _calculate_height(const int cycles) const {
            int height {1};

            for (int cycle {1}; cycle <= cycles; cycle++)
                height = _is_cycle_happening_during_spring(cycle) ? height * 2 : height + 1;

            return height;
        }

            bool _is_cycle_happening_during_spring(const int cycle) const {
                return cycle & 1;
            }

public:
    Result(const vector<int> n_test_cases_cycles) {
        _n_test_cases_cycles = n_test_cases_cycles;
        _trees_heights.resize(_n_test_cases_cycles.size());

        _utopian_tree();
        print_trees_heights();
    }

        void print_trees_heights() const {
            for (int height : _trees_heights)
                cout << height << "\n";
        }
};

int read_line_as_int() {
    int number;
    cin >> number;
    return number;
}

vector<int> read_n_test_cases_cycles(const int n_test_cases) {
    vector<int> n_test_cases_cycles(n_test_cases);
    generate(n_test_cases_cycles.begin(), n_test_cases_cycles.end(), read_line_as_int);
    return n_test_cases_cycles;
}

int main() {
    const int n_test_cases {read_line_as_int()};
    const vector<int> n_test_cases_cycles {read_n_test_cases_cycles(n_test_cases)};

    const Result result(n_test_cases_cycles);

    return 0;
}
