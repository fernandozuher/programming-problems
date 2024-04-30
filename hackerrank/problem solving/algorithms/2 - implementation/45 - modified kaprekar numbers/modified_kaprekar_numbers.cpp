// https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true

#include <algorithm>
#include <cmath>
#include <iostream>
#include <ranges>

using namespace std;
using namespace views;

int number_digits(long n);

int main()
{
    int lower_limit, upper_limit;
    cin >> lower_limit >> upper_limit;
    bool valid_range {};

    auto print_if_number_is_kaprekar = [&valid_range](const int x) {
        auto square_number {pow(x, 2)};
        auto divisor {pow(10, number_digits(x))};
        auto [left_number, right_number] {ldiv(square_number, divisor)};
        if (x == left_number + right_number) {
            cout << x << ' ';
            valid_range = true;
        }
    };

    ranges::for_each(iota(lower_limit, upper_limit + 1), print_if_number_is_kaprekar);
    if (!valid_range)
        cout << "INVALID_RANGE\n";

    return 0;
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
