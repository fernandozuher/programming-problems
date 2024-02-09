// https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Find_Digits {
public:
    Find_Digits(const int number);
    int divisors() const;

private:
    int number;
    int n_divisors;

    void find_number_divisors_quantity();
    int get_last_digit_of_number(const int number) const;
    bool is_number_evenly_divided_by_divisor(const int divisor) const;
    int remove_last_digit_of_number(const int number) const;
};

    Find_Digits::Find_Digits(const int number): number{number}, n_divisors{}
    {
        find_number_divisors_quantity();
    }

        void Find_Digits::find_number_divisors_quantity()
        {
            for (int current_number {number}; current_number != 0; current_number = remove_last_digit_of_number(current_number)) {
                int divisor {get_last_digit_of_number(current_number)};
                if (is_number_evenly_divided_by_divisor(divisor))
                    ++n_divisors;
            }
        }

            int Find_Digits::get_last_digit_of_number(const int number) const
            {
                return number % 10;
            }

            bool Find_Digits::is_number_evenly_divided_by_divisor(const int divisor) const
            {
                return divisor != 0 && number % divisor == 0;
            }

            int Find_Digits::remove_last_digit_of_number(const int number) const
            {
                return number / 10;
            }

    int Find_Digits::divisors() const
    {
        return n_divisors;
    }

//////////////////////////////////////////////////

template<class T = int>
void println_array(const vector<T>& array);

int main()
{
    int n;
    cin >> n;
    vector<int> n_number_divisors(n);

    for (auto& divisors : n_number_divisors) {
        int number;
        cin >> number;
        Find_Digits obj{number};
        divisors = obj.divisors();
    }

    println_array(n_number_divisors);

    return 0;
}

    template<class T = int>
    void println_array(const vector<T>& array)
    {
        auto println = [](const auto x) {cout << x << '\n';};
        ranges::for_each(array, println);
    }
