// https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true
// C++23

import morfo;
import std;
using namespace std;

int find_digits(int num);

int main()
{
    int n = morfo::read();

    for (int i{}; i < n; ++i) {
        int num = morfo::read();
        println("{}", find_digits(num));
    }

    return 0;
}

// k: quantity of digits of num = log num
// 0 < num < 10^9
// T: O(k) = O(9) = O(1)
// S: O(k) = O(9) = O(1) extra space
int find_digits(int num)
{
    return ranges::count_if(to_string(num), [num](auto c) {
        int d{ c - '0' };
        return d != 0 && num % d == 0;
        });
}
