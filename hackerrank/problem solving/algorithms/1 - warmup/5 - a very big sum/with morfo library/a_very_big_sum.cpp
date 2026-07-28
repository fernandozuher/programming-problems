// https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true
// C++23

import morfo;
import std;
using namespace std;

long long a_very_big_sum(const vector<int>& arr);

int main()
{
    morfo::skip_input_ln();
    vector<int> arr = morfo::readln();
    cout << a_very_big_sum(arr);
    return 0;
}

// n: length of arr
// T: O(n)
// S: O(1) extra space
long long a_very_big_sum(const vector<int>& arr)
{
    return *ranges::fold_left_first(arr, plus<long long>{});
}
