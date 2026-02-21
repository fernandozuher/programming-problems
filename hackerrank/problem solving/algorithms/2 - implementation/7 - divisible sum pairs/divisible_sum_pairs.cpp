// https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true
// C++23

import std;
using namespace std;

vector<int> read_numbers(int n);
int divisible_sum_pairs(const vector<int>& numbers, int k);
vector<int> init_remainder_frequency(const vector<int>& numbers, int k);
int count_pairs_with_remainder_0(const vector<int>& frequency);
int pair_count(int n);
int count_complementary_remainder_pairs(const vector<int>& frequency);
int count_pairs_with_remainder_k_half(const vector<int>& frequency);

int main()
{
    int n, k;
    cin >> n >> k;
    vector numbers{ read_numbers(n) };
    cout << divisible_sum_pairs(numbers, k);
    return 0;
}

vector<int> read_numbers(int n)
{
    vector<int> arr(n);
    for (auto& x : arr)
        cin >> x;
    return arr;
}

// n: length of array numbers
// k: length of array frequency
// T: O(n + k)
// S: O(k) extra space
int divisible_sum_pairs(const vector<int>& numbers, int k)
{
    vector frequency{ init_remainder_frequency(numbers, k) };
    return count_pairs_with_remainder_0(frequency) + count_complementary_remainder_pairs(frequency) +
        count_pairs_with_remainder_k_half(frequency);
}

vector<int> init_remainder_frequency(const vector<int>& numbers, int k)
{
    vector<int> frequency(k);
    for (int x : numbers)
        ++frequency.at(x % k);
    return frequency;
}

int count_pairs_with_remainder_0(const vector<int>& frequency)
{
    return pair_count(frequency.front());
}

int pair_count(int n)
{
    return n * (n - 1) / 2;
}

int count_complementary_remainder_pairs(const vector<int>& frequency)
{
    auto n{ frequency.size() };
    return *ranges::fold_left_first(
        views::iota(1ul, (n + 1) / 2) |
        views::transform([&frequency, n](auto i) { return frequency.at(i) * frequency.at(n - i); }),
        plus{}
    );
}

int count_pairs_with_remainder_k_half(const vector<int>& frequency)
{
    auto n{ frequency.size() };
    return n % 2 == 0 ? pair_count(frequency.at(n / 2)) : 0;
}
