// Source: https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int read_a_number();
int find_number_divisors_quantity();
    bool is_number_evenly_divided_by_divisor(const int NUMBER, const int DIVISOR);
void print_output(const vector<int> ARRAY);


int main() {
    const int N_TEST_CASES {read_a_number()};
    vector<int> output(N_TEST_CASES);

    ranges::generate(output, find_number_divisors_quantity);
    print_output(output);

    return 0;
}

    int read_a_number() {
        int number;
        cin >> number;
        return number;
    }

    int find_number_divisors_quantity() {
        const int NUMBER {read_a_number()};
        int divisors {0};

        for (int number {NUMBER}; number != 0; number /= 10) {
            const int POTENTIAL_DIVISOR {number % 10};
            if (is_number_evenly_divided_by_divisor(NUMBER, POTENTIAL_DIVISOR))
                divisors++;
        }

        return divisors;
    }

        bool is_number_evenly_divided_by_divisor(const int NUMBER, const int DIVISOR) {
            return DIVISOR != 0 && NUMBER % DIVISOR == 0;
        }

    void print_output(const vector<int> ARRAY) {
        for (int number : ARRAY)
            cout << number << "\n";
    }
