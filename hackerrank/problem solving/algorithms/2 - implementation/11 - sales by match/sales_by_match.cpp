// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true
// C++23

import std;
using namespace std;

unordered_map<int, int> counter(int n);
int sock_merchant(const unordered_map<int, int>& socks_to_counts);

int main()
{
    int n;
    cin >> n;
    unordered_map<int, int> socks_to_counts{ counter(n) };
    println("{}", sock_merchant(socks_to_counts));
    return 0;
}

// n: length of user input
// k: length of distinct numbers in user input
// k <= n
// T: O(n)
// S: O(k) extra space
unordered_map<int, int> counter(int n)
{
    unordered_map<int, int> freq_map;
    for (int i{}; i < n; ++i) {
        int x;
        cin >> x;
        ++freq_map[x];
    }
    return freq_map;
}

// n: length of initial user input
// k: length of entries in socks_to_counts
// k <= n
// T: O(k)
// S: O(1) extra space
int sock_merchant(const unordered_map<int, int>& socks_to_counts)
{
    return *ranges::fold_left_first(views::values(socks_to_counts) | views::transform([](int x) { return x / 2; }), plus{});
}
