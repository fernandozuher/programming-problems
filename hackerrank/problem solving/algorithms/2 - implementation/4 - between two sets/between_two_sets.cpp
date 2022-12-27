#include <iostream>
#include <vector>
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
            auto lambda_expression = [](int previous_result, int item) {return item ? ++previous_result: previous_result;};
            _total_factors = accumulate(_potential_factors.begin(), _potential_factors.end(), 0, lambda_expression);
        }

public:

    Result(const vector<int> set_a, const vector<int> set_b): _set_a {set_a}, _set_b {set_b}, _total_factors{0} {
        find_factors();
    }

    int get_total_x() const {
        return _total_factors;
    }
};

void read_input(vector<int> &set_a, vector<int> &set_b) {
    int n1, n2;
    cin >> n1 >> n2;

    set_a.reserve(n1);
    set_b.reserve(n2);

    for (int temp; n1--; set_a.push_back(temp))
        cin >> temp;
    ranges::sort(set_a);

    for (int temp; n2--; set_b.push_back(temp))
        cin >> temp;
    ranges::sort(set_b);
}

int main() {
    vector<int> a, b;
    read_input(a, b);

    Result result(a, b);
    int total {result.get_total_x()};
    cout << total << "\n";

    return 0;
}
