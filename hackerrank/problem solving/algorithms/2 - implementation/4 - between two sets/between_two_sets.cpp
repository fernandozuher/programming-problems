#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <numeric>

using namespace std;

/*
 * Complete the 'get_total_x' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */

class Result {

private:

    vector<int> _potential_factors, _set_a, _set_b;
    int _total_factors;

    void find_factors() {
        find_numbers_divisible_by_set_a();
        find_factors_of_set_b();
        count_factors();
    }

    void find_numbers_divisible_by_set_a() {
        for (int potential_factor {_set_a.back()}; potential_factor <= _set_b.front(); potential_factor += _set_a.back()) {
            bool is_a_real_potential_factor {true};

            for (auto element_a : _set_a)
                if (potential_factor % element_a) {
                    is_a_real_potential_factor = false;
                    break;
                }

            if (is_a_real_potential_factor)
                _potential_factors.push_back(potential_factor);
        }
    }

    void find_factors_of_set_b() {
        for (auto element_b : _set_b)
            for (auto &potential_factor : _potential_factors)
                if (potential_factor && element_b % potential_factor)
                    potential_factor = 0;
    }

    void count_factors() {
        auto lambda_expression = [](int previous_result, int item) {return item ? ++previous_result : previous_result;};
        _total_factors = accumulate(_potential_factors.begin(), _potential_factors.end(), 0, lambda_expression);
    }

public:

    Result(const vector<int> set_a, const vector<int> set_b): _set_a {set_a}, _set_b {set_b} {
        _total_factors = 0;
        find_factors();
        print_result();
    }

    void print_result() const {
        cout << _total_factors;
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
    vector<int> set_a = read_line_as_vector_int();
    vector<int> set_b = read_line_as_vector_int();

    ranges::sort(set_a);
    ranges::sort(set_b);

    Result result(set_a, set_b);

    return 0;
}