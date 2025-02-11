// https://www.hackerrank.com/challenges/30-conditional-statements/problem?isFullScreen=true

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    bool is_weird {n & 1 || n >= 6 && n <= 20};
    cout << (is_weird ? "Weird" : "Not Weird");
    return 0;
}
