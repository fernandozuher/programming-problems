// https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

#include <cmath>
#include <iostream>

using namespace std;

int squares(int start_num, int end_num);

int main()
{
    int n;
    cin >> n;
    for (int i{}; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        cout << squares(a, b) << '\n';
    }
}

int squares(int start_num, int end_num)
{
    int max_square = floor(sqrt(end_num));
    int min_square = ceil(sqrt(start_num));
    return max_square - min_square + 1;
}
