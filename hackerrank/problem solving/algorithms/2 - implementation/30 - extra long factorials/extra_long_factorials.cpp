// https://www.hackerrank.com/challenges/extra-long-factorials/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

using namespace std;

vector<int> calculate_factorial_of(const int number);
    vector<int> multiply_array_with_number(vector<int>& array, const int number);
        int get_last_digit_of_number(const int number);
        int remove_last_digit_of_number(const int number);
        vector<int> add_remaining_carry_to_array(int carry, vector<int>& array);
void print_factorial(const vector<int>& array);

int main()
{
    int number;
    cin >> number;
    vector<int> factorial {calculate_factorial_of(number)};
    print_factorial(factorial);

    return 0;
}

    vector<int> calculate_factorial_of(const int number)
    {
        vector<int> factorial{1};

        for (int current_number{2}; current_number <= number; ++current_number)
            factorial = multiply_array_with_number(factorial, current_number);

        return factorial;
    }

        vector<int> multiply_array_with_number(vector<int>& array, const int number)
        {
            int carry{};

            for (auto &digit : array) {
                int product {digit * number + carry};
                digit = get_last_digit_of_number(product);
                carry = remove_last_digit_of_number(product);
            }

            array = add_remaining_carry_to_array(carry, array);
            return array;
        }

            int get_last_digit_of_number(const int number)
            {
                return number % 10;
            }

            int remove_last_digit_of_number(const int number)
            {
                return number / 10;
            }

            vector<int> add_remaining_carry_to_array(int carry, vector<int>& array)
            {
                while (carry) {
                    array.push_back(get_last_digit_of_number(carry));
                    carry = remove_last_digit_of_number(carry);
                }
                return array;
            }

    void print_factorial(const vector<int>& array)
    {
        for (const auto digit : views::reverse(array))
            cout << digit;
        cout << '\n';
    }
