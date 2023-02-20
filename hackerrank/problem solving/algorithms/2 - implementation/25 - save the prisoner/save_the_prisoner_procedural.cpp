// Source: https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

#include <iostream>
#include <vector>

using namespace std;

int read_a_number();

vector<int> read_test_cases_and_save_the_prisoners(const int N_TEST_CASES);
    vector<int> read_test_case();
    int save_the_prisoner(vector<int> test_case);

void print_results(const vector<int> ARRAY);


int main() {
    const int N_TEST_CASES {read_a_number()};
    const vector<int> PRISONERS_CHAIR_NUMBER_TO_WARN {read_test_cases_and_save_the_prisoners(N_TEST_CASES)};
    print_results(PRISONERS_CHAIR_NUMBER_TO_WARN);

    return 0;
}

    int read_a_number() {
        int number;
        cin >> number;
        return number;
    }

    vector<int> read_test_cases_and_save_the_prisoners(const int N_TEST_CASES) {
        vector<int> prisoners_chair_number_to_warn(N_TEST_CASES);

        for (int &prisoner_chair_number : prisoners_chair_number_to_warn) {
            vector<int> test_case {read_test_case()};
            prisoner_chair_number = {save_the_prisoner(test_case)};
        }

        return prisoners_chair_number_to_warn;
    }

        vector<int> read_test_case() {
            const int TEST_CASE_SIZE {3};
            vector<int> test_case(TEST_CASE_SIZE);

            for (auto &number : test_case)
                cin >> number;

            return test_case;
        }

        int save_the_prisoner(const vector<int> TEST_CASE) {
            const int PRISONERS {TEST_CASE.front()};
            const int SWEETS {TEST_CASE.at(1)};
            const int CHAIR_NUMBER_TO_BEGIN {TEST_CASE.back()};
            int prisoner_chair_number_to_warn {CHAIR_NUMBER_TO_BEGIN + (SWEETS - 1)};

            if (prisoner_chair_number_to_warn > PRISONERS) {
                prisoner_chair_number_to_warn %= PRISONERS;

                if (prisoner_chair_number_to_warn == 0)
                    prisoner_chair_number_to_warn = PRISONERS;
            }

            return prisoner_chair_number_to_warn;
        }

    void print_results(const vector<int> ARRAY) {
        for (auto element : ARRAY)
            cout << element << "\n";
    }
