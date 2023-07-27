// https://www.hackerrank.com/challenges/30-data-types/problem?isFullScreen=true

#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

int main()
{
    const int i {4};
    const double d {4.0};
    const string s {"HackerRank "};

    int i2;
    double d2;
    string s2;

    cin >> i2 >> d2;
    cin.get();
    getline(cin, s2);

    cout << i + i2 << '\n';
    cout << fixed << setprecision(1) << d + d2 << '\n';
    cout << s << s2 << '\n';

    return 0;
}
