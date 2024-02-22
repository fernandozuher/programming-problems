// https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Sherlock_And_Squares {
public:
    Sherlock_And_Squares(const int begin, const int end);
    int square_integers() const;

private:
    int begin;
    int end;
    int n_square_integers;

    void calculate_quantity_of_square_integers_in_range();
    int find_first_square_integer() const;
    bool is_power_of_2_less_than_or_equal_to_limit(const int x) const;
};

    Sherlock_And_Squares::Sherlock_And_Squares(const int begin, const int end): begin{begin}, end{end}, n_square_integers{}
    {
        calculate_quantity_of_square_integers_in_range();
    }

        void Sherlock_And_Squares::calculate_quantity_of_square_integers_in_range()
        {
            for (int number {find_first_square_integer()}; is_power_of_2_less_than_or_equal_to_limit(number); ++number)
                ++n_square_integers;
        }

            int Sherlock_And_Squares::find_first_square_integer() const
            {
                double square_root {sqrt(begin)};
                const double integer_part {trunc(square_root)};
                return square_root == integer_part ? integer_part : integer_part + 1;
            }

            bool Sherlock_And_Squares::is_power_of_2_less_than_or_equal_to_limit(const int x) const
            {
                return pow(x, 2) <= end;
            }

    int Sherlock_And_Squares::square_integers() const
    {
        return n_square_integers;
    }

//////////////////////////////////////////////////

template<class T = int>
void print_array(const vector<T>& array);

int main()
{
    int n;
    cin >> n;
    vector<int> number_of_square_integers(n);

    for (auto& element : number_of_square_integers) {
        int begin, end;
        cin >> begin >> end;
        Sherlock_And_Squares obj{begin, end};
        element = obj.square_integers();
    }

    print_array(number_of_square_integers);

    return 0;
}

    template<class T = int>
    void print_array(const vector<T>& array)
    {
        for (const auto x : array)
            cout << x << '\n';
    }
