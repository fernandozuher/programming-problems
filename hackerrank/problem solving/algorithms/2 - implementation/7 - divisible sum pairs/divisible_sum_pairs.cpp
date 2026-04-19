// https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true
// C++23

import std;
using namespace std;

vector<int> read_numbers(int n);
int divisible_sum_pairs(const vector<int>& numbers, int k);
vector<int> init_remainder_frequency(const vector<int>& numbers, int k);
int count_pairs_with_remainder_0(const vector<int>& freq);
int pair_count(int n);
int count_complementary_remainder_pairs(const vector<int>& freq);
int count_pairs_with_remainder_k_half(const vector<int>& freq);

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

// n: length of numbers
// k: length of freq
// T: O(n + k)
// S: O(k) extra space
int divisible_sum_pairs(const vector<int>& numbers, int k)
{
    vector freq{ init_remainder_frequency(numbers, k) };
    return count_pairs_with_remainder_0(freq) + count_complementary_remainder_pairs(freq) +
        count_pairs_with_remainder_k_half(freq);
}

vector<int> init_remainder_frequency(const vector<int>& numbers, int k)
{
    vector<int> freq(k);
    for (int x : numbers)
        ++freq.at(x % k);
    return freq;
}

int count_pairs_with_remainder_0(const vector<int>& freq)
{
    return pair_count(freq.front());
}

int pair_count(int n)
{
    return n * (n - 1) / 2;
}

int count_complementary_remainder_pairs(const vector<int>& freq)
{
    auto n{ freq.size() };
    return *ranges::fold_left_first(
        views::iota(1ul, (n + 1) / 2) |
        views::transform([&freq, n](auto i) { return freq.at(i) * freq.at(n - i); }),
        plus{}
    );
}

int count_pairs_with_remainder_k_half(const vector<int>& freq)
{
    auto n{ freq.size() };
    return n % 2 == 0 ? pair_count(freq.at(n / 2)) : 0;
}
