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

    for (int num{ lower }; num <= upper; ++num)
        if (is_number_kaprekar(num)) {
            cout << num << " ";
            valid_range = true;
        }

    if (!valid_range)
        puts("INVALID RANGE");

    return 0;
}

// log n: for calculating number of digits
// T: O(log n)
// S: O(1) extra space
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
