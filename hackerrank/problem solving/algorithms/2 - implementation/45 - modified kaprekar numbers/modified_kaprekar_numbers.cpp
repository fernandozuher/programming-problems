// https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true

#include <cmath>
#include <iostream>

using namespace std;

bool is_number_kaprekar(int number);
int number_digits(long n);

int main()
{
    int lower, upper;
    cin >> lower >> upper;
    bool valid_range{};

    for (int number{lower}; number <= upper; ++number)
        if (is_number_kaprekar(number)) {
            cout << number << " ";
            valid_range = true;
        }

    if (!valid_range)
        puts("INVALID RANGE");

    return 0;
}

bool is_number_kaprekar(int number)
{
    auto square_number{pow(number, 2)};
    auto divisor{pow(10, number_digits(number))};
    auto [left_number, right_number]{ldiv(square_number, divisor)};
    return number == left_number + right_number;
}

int number_digits(long n)
{
    return static_cast<int>(log10(n)) + 1;
}
