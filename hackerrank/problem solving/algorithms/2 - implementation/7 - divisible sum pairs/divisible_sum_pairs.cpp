// https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true
// From C++23 onwards

#include <algorithm>
#include <iostream>
#include <iterator>
#include <ranges>
#include <vector>

using namespace std;

template<class T = int>
vector<T> read(int n);
int divisible_sum_pairs(const vector<int>& array, int k);

int main()
{
    int n, k;
    cin >> n >> k;
    vector array{read(n)};
    ranges::sort(array);
    cout << divisible_sum_pairs(array, k);
    return 0;
}

template<class T>
vector<T> read(const int n)
{
    vector<T> array(n);
    copy_n(istream_iterator<T>(cin), n, array.begin());
    return array;
}

int divisible_sum_pairs(const vector<int>& array, const int k)
{
    int n_divisible_sum_pairs{};
    for (const auto [i, num1] : array | views::take(array.size() - 1) | views::enumerate)
        for (const int num2 : array | views::drop(i + 1))
            if (num1 <= num2 && !((num1 + num2) % k))
                ++n_divisible_sum_pairs;
    return n_divisible_sum_pairs;
}
