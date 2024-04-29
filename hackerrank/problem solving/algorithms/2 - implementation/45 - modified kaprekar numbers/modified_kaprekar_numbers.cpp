// https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true

#include <algorithm>
#include <cmath>
#include <iostream>
#include <ranges>
#include <vector>

using namespace std;

namespace programing_problems {

int calculate_potential_kaprekar_number(int number);
    int number_digits(long n);

class Kaprekar_Numbers {
    int lower_limit, upper_limit;
    vector<int> vec_kaprekar_numbers;

public:
    Kaprekar_Numbers(int lower_limit, int upper_limit);
    [[nodiscard]] vector<int> kaprekar_numbers() const;
    void find_kaprekar_numbers_in_range();
};

    Kaprekar_Numbers::Kaprekar_Numbers(const int lower_limit, const int upper_limit):
        lower_limit{lower_limit}, upper_limit{upper_limit} {}

    [[nodiscard]] vector<int> Kaprekar_Numbers::kaprekar_numbers() const
    {
        return vec_kaprekar_numbers;
    }

    void Kaprekar_Numbers::find_kaprekar_numbers_in_range()
    {
        for (const int number : views::iota(lower_limit, upper_limit + 1))
            if (number == calculate_potential_kaprekar_number(number))
                vec_kaprekar_numbers.push_back(number);
    }

        int calculate_potential_kaprekar_number(const int number)
        {
            auto square_number {pow(number, 2)};
            auto divisor {pow(10, number_digits(number))};
            auto [left_number, right_number] {ldiv(square_number, divisor)};
            return left_number + right_number;
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
}

//////////////////////////////////////////////////

void print_output(const vector<int>& array);

int main()
{
    int lower_limit, upper_limit;
    cin >> lower_limit >> upper_limit;
    programing_problems::Kaprekar_Numbers obj{lower_limit, upper_limit};
    obj.find_kaprekar_numbers_in_range();
    print_output(obj.kaprekar_numbers());

    return 0;
}

    void print_output(const vector<int>& array)
    {
        if (!array.empty())
            ranges::for_each(array, [](const auto x) { cout << x << ' '; });
        else
            cout << "INVALID RANGE";
    }
