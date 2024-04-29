// https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true

#include <algorithm>
#include <cmath>
#include <iostream>
#include <ranges>
#include <vector>

using namespace std;
using namespace views;

bool is_number_kaprekar(int number);
    int number_digits(long n);
void print_output(const vector<int>& array);

int main()
{
    int lower_limit, upper_limit;
    cin >> lower_limit >> upper_limit;
    vector<int> kaprekar_numbers;
    ranges::copy_if(iota(lower_limit, upper_limit + 1), back_inserter(kaprekar_numbers), is_number_kaprekar);
    print_output(kaprekar_numbers);

    return 0;
}

    bool is_number_kaprekar(const int number)
    {
        auto square_number {pow(number, 2)};
        auto divisor {pow(10, number_digits(number))};
        auto [left_number, right_number] {ldiv(square_number, divisor)};
        return number == left_number + right_number;
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

    void print_output(const vector<int>& array)
    {
        if (!array.empty())
            ranges::for_each(array, [](const auto x) { cout << x << ' '; });
        else
            cout << "INVALID RANGE";
    }
