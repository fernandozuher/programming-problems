// https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true
// C++23

import morfo;
import std;
using namespace std;

pair<long long, long long> calc_min_max_sum(const vector<long long>& arr);

int main()
{
    vector<long long> arr = morfo::readln();
    auto [min_sum, max_sum] { calc_min_max_sum(arr) };
    println("{} {}", min_sum, max_sum);
    return 0;
}

// n: length of arr
// T: O(n)
// S: O(1) extra space
pair<long long, long long> calc_min_max_sum(const vector<long long>& arr)
{
    auto [total, min_value, max_value] = morfo::reduce_many(
        arr,
        plus{}, 0LL,
        ranges::min, arr.front(),
        ranges::max, arr.front()
    );

    return {total - max_value, total - min_value};
}
