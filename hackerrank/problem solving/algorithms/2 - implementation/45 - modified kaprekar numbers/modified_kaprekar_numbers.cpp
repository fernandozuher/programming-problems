// https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true

#include <algorithm>
#include <charconv>
#include <cmath>
#include <iostream>
#include <ranges>
#include <string>
#include <string_view>
#include <vector>

using namespace std;

namespace programing_problems {

int calculate_potential_kaprekar_number(int number);
    string_view left_number_in_string(string_view square_number_in_string, size_t length_of_number_in_string);
    string_view right_number_in_string(string_view square_number_in_string, size_t length_of_number_in_string);
    int sum_numbers_in_strings(string_view left_number_in_string, string_view right_number_in_string);


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
            long square_number{static_cast<long>(pow(number, 2))};
            string square_number_in_string{to_string(square_number)};
            size_t length_of_number_in_string{to_string(number).size()};

            return sum_numbers_in_strings(
               left_number_in_string(square_number_in_string, length_of_number_in_string),
               right_number_in_string(square_number_in_string, length_of_number_in_string)
           );
        }

            string_view left_number_in_string(const string_view square_number_in_string,
                                              const size_t length_of_number_in_string)
            {
                size_t digits_to_take{square_number_in_string.size() - length_of_number_in_string};
                return square_number_in_string.substr(0, digits_to_take);
            }

            string_view right_number_in_string(const string_view square_number_in_string,
                                               const size_t length_of_number_in_string)
            {
                size_t digits_to_skip{square_number_in_string.size() - length_of_number_in_string};
                size_t digits_to_take{square_number_in_string.size() - digits_to_skip};
                return square_number_in_string.substr(digits_to_skip, digits_to_take);
            }

            int sum_numbers_in_strings(const string_view left_number_in_string,
                                       const string_view right_number_in_string)
            {
                int n1{}, n2{};
                from_chars(left_number_in_string.begin(), left_number_in_string.end(), n1);
                from_chars(right_number_in_string.begin(), right_number_in_string.end(), n2);
                return n1 + n2;
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
