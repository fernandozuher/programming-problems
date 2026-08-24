// https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true
// C++23

import morfo;
import std;
using namespace std;

int sum_stdin();

int main()
{
    morfo::skip_input_ln();
    cout << sum_stdin();
    return 0;
}

// n: number of integers in the input line
// T: O(n)
// S: O(1) extra space
int sum_stdin()
{
    return morfo::sum(morfo::readln<int>());
}
