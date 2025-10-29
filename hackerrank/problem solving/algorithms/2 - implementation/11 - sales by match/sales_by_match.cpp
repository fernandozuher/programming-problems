// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true
// C++23

#include <algorithm>
#include <iostream>
#include <ranges>
#include <unordered_map>

using namespace std;

unordered_map<int, int> read_numbers_into_map(int n);
int sock_merchant(const unordered_map<int, int>& sock_counts);

int main()
{
    int n;
    cin >> n;
    auto sock_counts{read_numbers_into_map(n)};
    cout << sock_merchant(sock_counts) << '\n';
    return 0;
}

unordered_map<int, int> read_numbers_into_map(int n)
{
    unordered_map<int, int> counter;
    for (int x; n-- && cin >> x;)
        ++counter[x];
    return counter;
}

int sock_merchant(const unordered_map<int, int>& sock_counts)
{
    return ranges::fold_left(views::values(sock_counts), 0, [](int pairs, int count) { return pairs + count / 2; });
}
