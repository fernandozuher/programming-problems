// Source: https://www.hackerrank.com/challenges/extra-long-factorials/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>

using namespace std;

int read_a_number();
vector<int> calculate_factorial_of(const int NUMBER);
    vector<int> multiply_result_with_number(vector<int> result, const int NUMBER);
        int get_last_digit_of_number(const int NUMBER);
        int remove_last_digit_of_number(const int NUMBER);
        vector<int> add_remaining_carry_to_result(int carry, vector<int> result);
void print_factorial(const vector<int> ARRAY);


int main() {
    const int NUMBER {read_a_number()};
    const vector<int> FACTORIAL {calculate_factorial_of(NUMBER)};
    print_factorial(FACTORIAL);

    return 0;
}

    int read_a_number() {
        int number;
        cin >> number;
        return number;
    }

    vector<int> calculate_factorial_of(const int NUMBER) {
        vector<int> factorial {1};

        for (int number {2}; number <= NUMBER; number++)
            factorial = {multiply_result_with_number(factorial, number)};

        return factorial;
    }

        vector<int> multiply_result_with_number(vector<int> result, const int NUMBER) {
            int carry {0};

            for (auto &digit : result) {
                const int PRODUCT = digit * NUMBER + carry;
                digit = get_last_digit_of_number(PRODUCT);
                carry = remove_last_digit_of_number(PRODUCT);
            }

            result = add_remaining_carry_to_result(carry, result);
            return result;
        }

            int get_last_digit_of_number(const int NUMBER) {
                return NUMBER % 10;
            }

            int remove_last_digit_of_number(const int NUMBER) {
                return NUMBER / 10;
            }

            vector<int> add_remaining_carry_to_result(int carry, vector<int> result) {
                while (carry != 0) {
                    result.push_back(get_last_digit_of_number(carry));
                    carry = remove_last_digit_of_number(carry);
                }
                return result;
            }

    void print_factorial(const vector<int> ARRAY) {
        for (auto &digit : views::reverse(ARRAY))
            cout << digit;
        cout << "\n";
    }
