// https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

vector<int> read_int_array(const int n);
void mini_max_sum(const vector<int>& array);

int main()
{
    const int n = 5;
    vector<int> array {read_int_array(n)};
    ranges::sort(array);
    mini_max_sum(array);

    return 0;
}

    vector<int> read_int_array(const int n)
    {
        vector<int> array(n);
        ranges::generate(array, [] {int x; cin >> x; return x;});
        return array;
    }

    void mini_max_sum(const vector<int>& array)
    {
        long total_sum {accumulate(array.begin(), array.end(), 0l)};
        long min_sum {total_sum - array.back()};
        long max_sum {total_sum - array.front()};
        cout << min_sum << ' ' << max_sum;
    }
