// https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true
// C++23

import morfo;
import std;
using namespace std;

long long a_very_big_sum(const vector<long long>& arr);

int main()
{
    morfo::skip_input_ln();
    vector<long long> arr = morfo::readln();
    cout << a_very_big_sum(arr);
    return 0;
}

// n: length of arr
// T: O(n)
// S: O(1) extra space
long long a_very_big_sum(const vector<long long>& arr)
{
    return morfo::sum(arr);
}
