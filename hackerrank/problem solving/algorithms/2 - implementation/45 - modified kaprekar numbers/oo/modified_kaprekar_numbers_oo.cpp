// Source: https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

int read_a_number();
void print_output(const vector<int> array);

class Kaprekar_Numbers
{
private:
    int lower_limit, upper_limit;
    vector<int> kaprekar_numbers;

    void find_kaprekar_numbers_in_range()
    {
        for (int number {lower_limit}; number <= upper_limit; number++)
        {
            const int potential_kaprekar_number {calculate_potential_kaprekar_number(number)};
            if (number == potential_kaprekar_number)
                kaprekar_numbers.push_back(number);
        }
    }

        int calculate_potential_kaprekar_number(const int number) const
        {
            const string square_number_in_string {to_string((unsigned long) pow(number, 2))};
            const int length_of_number_in_string {static_cast<int>(to_string(number).length())};

            const string left_number_in_string {get_left_number_in_string(square_number_in_string, length_of_number_in_string)};
            const string right_number_in_string {get_right_number_in_string(square_number_in_string, length_of_number_in_string)};

            const int potential_kaprekar_number {sum_numbers_in_strings(left_number_in_string, right_number_in_string)};

            return potential_kaprekar_number;
        }

            string get_left_number_in_string(const string square_number_in_string, const int length_of_number_in_string) const
            {
                const int digits_to_skip {0};
                const int digits_to_take {static_cast<int>(square_number_in_string.length()) - length_of_number_in_string};
                if (digits_to_take != 0)
                {
                    const string number_in_string {square_number_in_string.substr(digits_to_skip, digits_to_take)};
                    return number_in_string;
                }
                return "";
            }

            string get_right_number_in_string(const string square_number_in_string, const int length_of_number_in_string) const
            {
                const int digits_to_skip {static_cast<int>(square_number_in_string.length()) - length_of_number_in_string};
                const int digits_to_take {static_cast<int>(square_number_in_string.length()) - digits_to_skip};
                const string number_in_string {square_number_in_string.substr(digits_to_skip, digits_to_take)};
                return number_in_string;
            }

            int sum_numbers_in_strings(const string left_number_in_string, const string right_number_in_string) const
            {
                if (left_number_in_string.length() > 0 && right_number_in_string.length() > 0)
                    return stoi(left_number_in_string) + stoi(right_number_in_string);
                else if (left_number_in_string.length() == 0)
                    return stoi(right_number_in_string);
                else if (right_number_in_string.length() == 0)
                    return stoi(left_number_in_string);
                return 0;
            }

public:
    Kaprekar_Numbers(const int lower_limit, const int upper_limit)
    {
        this->lower_limit = {lower_limit};
        this->upper_limit = {upper_limit};

        find_kaprekar_numbers_in_range();
    }

    vector<int> get_kaprekar_numbers() const
    {
        return kaprekar_numbers;
    }
};

int main()
{
    const int lower_limit {read_a_number()};
    const int upper_limit {read_a_number()};

    const Kaprekar_Numbers obj(lower_limit, upper_limit);
    print_output(obj.get_kaprekar_numbers());

    return 0;
}

    int read_a_number()
    {
        int number;
        cin >> number;
        return number;
    }

    void print_output(const vector<int> array)
    {
        if (!array.empty())
            ranges::for_each(array, [](auto & element) {cout << element << " ";});
        else
            cout << "INVALID RANGE";
    }
