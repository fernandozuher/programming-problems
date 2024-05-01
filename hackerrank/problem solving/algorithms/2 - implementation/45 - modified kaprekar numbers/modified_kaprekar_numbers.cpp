// https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true

#include <algorithm>
#include <cmath>
#include <iostream>
#include <ranges>

using namespace std;
using namespace views;

void print_if_number_is_kaprekar(int number, bool& valid_range);
    int number_digits(long n);

int main()
{
    int lower_limit, upper_limit;
    cin >> lower_limit >> upper_limit;
    bool valid_range {};
    auto print_kaprekar_numbers = [&valid_range](const int x){print_if_number_is_kaprekar(x, valid_range);};

    ranges::for_each(iota(lower_limit, upper_limit + 1), print_kaprekar_numbers);
    if (!valid_range)
        cout << "INVALID_RANGE\n";

    return 0;
}

    void print_if_number_is_kaprekar(const int number, bool& valid_range)
    {
        auto square_number {pow(number, 2)};
        auto divisor {pow(10, number_digits(number))};
        auto [left_number, right_number] {ldiv(square_number, divisor)};
        if (number == left_number + right_number) {
            cout << number << ' ';
            valid_range = true;
        }
    }

        int number_digits(const long n)
        {
            if (n < 10) return 1;
            if (n < 100) return 2;
            if (n < 1000) return 3;
            if (n < 10000) return 4;
            if (n < 100000) return 5;
            if (n < 1000000) return 6;
            if (n < 10000000) return 7;
            return 8;
        }
