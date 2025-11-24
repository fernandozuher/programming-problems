// https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true
// C++23

import std;

using namespace std;

int find_digits(int n);

int main()
{
    int n;
    cin >> n;
    for (int i{}, number; i < n && cin >> number; ++i)
        println("{}", find_digits(number));

    return 0;
}

int find_digits(int n)
{
    return ranges::count_if(to_string(n), [n](auto c) {int d{ c - '0' }; return d != 0 && n % d == 0; });
}
