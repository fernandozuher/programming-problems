// https://www.hackerrank.com/challenges/30-data-types/problem?isFullScreen=true
// From C++23 onwards

#include <iostream>
#include <iomanip>
#include <print>

using namespace std;

int main()
{
    constexpr int i{4};
    constexpr double d{4.0};
    const auto s{"HackerRank "s};

    int i2;
    double d2;
    string s2;

    cin >> i2 >> d2;
    cin.get();
    getline(cin, s2);

    println("{}", i + i2);
    cout << fixed << setprecision(1) << d + d2 << '\n';
    println("{}{}", s, s2);

    return 0;
}
