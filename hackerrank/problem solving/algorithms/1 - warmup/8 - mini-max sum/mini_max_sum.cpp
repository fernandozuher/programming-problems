// https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true
// C++23

#include <iostream>
#include <ranges>
#include <vector>

using namespace std;

template<class T = int>
vector<T> read_numbers(int n);
pair<long long, long long> calc_min_max_sum(const vector<long long>& numbers);

int main()
{
    constexpr int n{5};
    vector numbers{read_numbers<long long>(n)};
    auto [min_sum, max_sum]{calc_min_max_sum(numbers)};
    cout << min_sum << ' ' << max_sum;
    return 0;
}

template<class T>
vector<T> read_numbers(int n)
{
    return views::iota(0, n) | views::transform([](auto) {
        T x;
        cin >> x;
        return x;
    }) | ranges::to<vector>();
}

pair<long long, long long> calc_min_max_sum(const vector<long long>& numbers)
{
    long long sum, minValue, maxValue;
    sum = minValue = maxValue = numbers.front();

    for (auto x : numbers | views::drop(1)) {
        sum += x;
        minValue = min(x, minValue);
        maxValue = max(x, maxValue);
    }

    return {sum - maxValue, sum - minValue};
}
