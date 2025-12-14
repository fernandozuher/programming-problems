// https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true
// C++23

import std;
using namespace std;

bool is_number_kaprekar(int n);
int number_digits(int n);

int main()
{
    int lower, upper;
    cin >> lower >> upper;
    bool valid_range{};

    for (int number{ lower }; number <= upper; ++number)
        if (is_number_kaprekar(number)) {
            cout << number << " ";
            valid_range = true;
        }

    if (!valid_range)
        puts("INVALID RANGE");

    return 0;
}

bool is_number_kaprekar(int n)
{
    auto square_number{ static_cast<long long>(pow(n, 2)) };
    auto divisor{ static_cast<long long>(pow(10, number_digits(n))) };
    auto [left_number, right_number] {lldiv(square_number, divisor)};
    return n == left_number + right_number;
}

int number_digits(int n)
{
    return static_cast<int>(log10(n)) + 1;
}
