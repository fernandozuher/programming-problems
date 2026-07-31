// https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true
// C++23

import std;
using namespace std;

vector<long> read_nums(int n);
pair<long, long> calc_min_max_sum(const vector<long>& arr);

int main()
{
    constexpr int n{ 5 };
    vector arr{ read_nums(n) };
    auto [min_sum, max_sum] { calc_min_max_sum(arr) };
    println("{} {}", min_sum, max_sum);
    return 0;
}

vector<long> read_nums(int n)
{
    vector<long> arr(n);
    for (auto& x : arr)
        cin >> x;
    return arr;
}

// n: length of arr
// T: O(n)
// S: O(1) extra space
pair<long, long> calc_min_max_sum(const vector<long>& arr)
{
    long total, min_value, max_value;
    total = min_value = max_value = arr.front();

    for (auto x : arr | views::drop(1)) {
        total += x;
        min_value = min(x, min_value);
        max_value = max(x, max_value);
    }

    return { total - max_value, total - min_value };
}
