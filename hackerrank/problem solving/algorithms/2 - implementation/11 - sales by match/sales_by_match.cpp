// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true
// C++23

import std;
using namespace std;

vector<int> read_nums(int n);
unordered_map<int, int> counter(const vector<int>& arr);
int sock_merchant(const unordered_map<int, int>& socks_to_counts);

int main()
{
    int n;
    cin >> n;
    vector<int> arr{ read_nums(n) };
    unordered_map<int, int> socks_to_counts{ counter(arr) };
    println("{}", sock_merchant(socks_to_counts));
    return 0;
}

vector<int> read_nums(int n)
{
    vector<int> arr(n);
    for (auto& x : arr)
        cin >> x;
    return arr;
}

// n: length of user input
// k: length of distinct numbers in user input
// k <= n
// T: O(n)
// S: O(k) extra space
unordered_map<int, int> counter(const vector<int>& arr)
{
    unordered_map<int, int> freq_map;
    for (int x : arr)
        ++freq_map[x];
    return freq_map;
}

// k: length of entries in socks_to_counts
// T: O(k)
// S: O(1) extra space
int sock_merchant(const unordered_map<int, int>& socks_to_counts)
{
    return *ranges::fold_left_first(views::values(socks_to_counts) | views::transform([](int x) { return x / 2; }), plus{});
}
