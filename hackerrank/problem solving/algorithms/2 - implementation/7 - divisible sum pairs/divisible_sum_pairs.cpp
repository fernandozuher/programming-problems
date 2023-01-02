// Source: https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=truehttps://www.hackerrank.com/challenges/the-divisibleSumPairs-bar/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Result {

private:
    vector<int> _numbers;
    int _k;
    int _n_divisible_sum_pairs;

    void _divisible_sum_pairs() {
        int n {static_cast<int>(_numbers.size())};
        for (int i {0}, n1 {n - 1}; i < n1; i++)
            for (int j {i + 1}; j < n; j++)
                if (_numbers[i] <= _numbers[j] && !((_numbers[i] + _numbers[j]) % _k))
                    _n_divisible_sum_pairs++;
    }

public:
    Result(const vector<int> numbers, const int k): _numbers{numbers}, _k(k) {
        _n_divisible_sum_pairs = 0;
        _divisible_sum_pairs();
        print_result();
    }

        void print_result() const {
            cout << _n_divisible_sum_pairs;
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
    vector<int> input1 {read_line_as_vector_int()};
    int k {input1.at(1)};
    vector<int> numbers {read_line_as_vector_int()};

    ranges::sort(numbers);

    Result result(numbers, k);

    return 0;
}
