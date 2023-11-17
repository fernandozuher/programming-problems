// https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

vector<int> read_int_array(const int n);
void plus_minus(const vector<int>& array);

int main()
{
    int n;
    cin >> n;
    vector<int> array {read_int_array(n)};
    plus_minus(array);

    return 0;
}

    vector<int> read_int_array(const int n)
    {
        vector<int> array(n);
        ranges::generate(array, [] {int n; cin >> n; return n;});
        return array;
    }

    void plus_minus(const vector<int>& array)
    {
        int positive_quantity {}, negative_quantity {}, zero_quantity {};

        for (const auto& number : array)
            if (number > 0)
                ++positive_quantity;
            else if (number < 0)
                ++negative_quantity;
            else
                ++zero_quantity;

        int n = array.size();
        double positive_values_proportion {(double) positive_quantity / n};
        double negative_values_proportion {(double) negative_quantity / n};
        double zero_values_proportion {(double) zero_quantity / n};

        cout << setprecision(6) << fixed
             << positive_values_proportion << '\n'
             << negative_values_proportion << '\n'
             << zero_values_proportion;
    }
