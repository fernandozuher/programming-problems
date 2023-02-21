// Source: https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int read_a_number();
vector<int> read_test_case();
void print_results(const vector<int> ARRAY);


class Save_The_Prisioner {

private:
    int _prisoners;
    int _sweets;
    int _chair_number_to_begin;
    int _prisoner_chair_number_to_warn;

    int _save_the_prisoner() {
        int prisoner_chair_number_to_warn {_chair_number_to_begin + (_sweets - 1)};

        if (prisoner_chair_number_to_warn > _prisoners) {
            prisoner_chair_number_to_warn %= _prisoners;

            if (prisoner_chair_number_to_warn == 0)
                prisoner_chair_number_to_warn = _prisoners;
        }

        return prisoner_chair_number_to_warn;
    }

public:
    Save_The_Prisioner(const vector<int> TEST_CASE) {
        _prisoners = {TEST_CASE.front()};
        _sweets = {TEST_CASE.at(1)};
        _chair_number_to_begin = {TEST_CASE.back()};

        _prisoner_chair_number_to_warn = {_save_the_prisoner()};
    }

    int get_prisoner_chair_number_to_warn() const {
        return _prisoner_chair_number_to_warn;
    }
};


int main() {
    const int N_TEST_CASES {read_a_number()};
    vector<int> prisoners_chair_number_to_warn(N_TEST_CASES);

    for (auto &prisoner_chair_number_to_warn : prisoners_chair_number_to_warn) {
        const vector<int> TEST_CASE {read_test_case()};
        const Save_The_Prisioner OBJ(TEST_CASE);
        prisoner_chair_number_to_warn = {OBJ.get_prisoner_chair_number_to_warn()};
    }

    print_results(prisoners_chair_number_to_warn);

    return 0;
}

    int read_a_number() {
        int number;
        cin >> number;
        return number;
    }

    vector<int> read_test_case() {
        const int TEST_CASE_SIZE {3};
        vector<int> test_case(TEST_CASE_SIZE);

        for (auto &number : test_case)
            cin >> number;

        return test_case;
    }

    void print_results(const vector<int> ARRAY) {
        ranges::for_each(ARRAY, [](auto element){cout << element << "\n";});
    }
