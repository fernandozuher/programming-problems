// https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true

#include <iomanip>
#include <iostream>

using namespace std;

tuple<double, double, double> plus_minus(const int n);

int main()
{
    int n;
    cin >> n;
    const auto [positive_proportion, negative_proportion, zero_proportion]{plus_minus(n)};
    cout << setprecision(6) << fixed << positive_proportion << '\n' << negative_proportion << '\n' << zero_proportion;
    return 0;
}

    tuple<double, double, double> plus_minus(const int n)
    {
        int positive{}, negative{}, zero{};

        for (int i{}, x; i < n && cin >> x; ++i)
            if (x > 0)
                ++positive;
            else if (x < 0)
                ++negative;
            else
                ++zero;

        double cast_n = n;
        double positive_proportion {positive / cast_n};
        double negative_proportion {negative / cast_n};
        double zero_proportion {zero / cast_n};

        return {positive_proportion, negative_proportion, zero_proportion};
    }
