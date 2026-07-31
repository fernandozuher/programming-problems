// https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true
// C++23

import morfo;
import std;
using namespace std;

pair<long long, long long> calc_min_max_sum(const vector<long long>& arr);

int main()
{
    auto arr = morfo::readln<long long, vector>();
    auto [min_sum, max_sum] { calc_min_max_sum(arr) };
    println("{} {}", min_sum, max_sum);
    return 0;
}

// n: length of arr
// T: O(n)
// S: O(1) extra space
pair<long long, long long> calc_min_max_sum(const vector<long long>& arr)
{
    long long total, min_value, max_value;
    total = min_value = max_value = arr.front();

    for (auto x : arr | views::drop(1)) {
        total += x;
        min_value = min(x, min_value);
        max_value = max(x, max_value);
    }

    return { total - max_value, total - min_value };
}
