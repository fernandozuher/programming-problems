// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true
// C++23

import std;
using namespace std;

unordered_map<int, int> counter(int n);
int sock_merchant(const unordered_map<int, int>& sock_counts);

int main()
{
    int n;
    cin >> n;
    unordered_map<int, int> sock_counts{ counter(n) };
    println("{}", sock_merchant(sock_counts));
    return 0;
}

unordered_map<int, int> counter(int n)
{
    unordered_map<int, int> counter;
    for (int x; n-- && cin >> x;)
        ++counter[x];
    return counter;
}

// n: quantity of entries in sock_counts
// T: O(n)
// S: O(1) extra space
int sock_merchant(const unordered_map<int, int>& sock_counts)
{
    return ranges::fold_left(views::values(sock_counts), 0, [](int pairs, int count) { return pairs + count / 2; });
}
