// https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=truehttps://www.hackerrank.com/challenges/the-divisibleSumPairs-bar/problem?isFullScreen=true
// From C++23

#include <algorithm>
#include <iostream>
#include <iterator>
#include <ranges>
#include <vector>

using namespace std;

vector<int> read_int_array(int n);
int divisible_sum_pairs(const vector<int>& array, int k);

int main()
{
    int n, k;
    cin >> n >> k;
    vector array{read_int_array(n)};
    ranges::sort(array);
    cout << divisible_sum_pairs(array, k);
    return 0;
}

    vector<int> read_int_array(const int n)
    {
        vector<int> array(n);
        copy_n(istream_iterator<int>(cin), n, array.begin());
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
