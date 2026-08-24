// https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true
// C++23

import morfo;
import std;
using namespace std;

int squares(int start_num, int end_num);

int main()
{
    int n = morfo::read();
    for (int i{}; i < n; ++i) {
        auto [a, b] = morfo::read<int, int>();
        println("{}", squares(a, b));
    }
}

// T: O(1)
// S: O(1) extra space
int squares(int start_num, int end_num)
{
    int max_square = floor(sqrt(end_num));
    int min_square = ceil(sqrt(start_num));
    return max_square - min_square + 1;
}
