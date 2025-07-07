// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true
// C++23

#include <algorithm>
#include <iostream>
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
    unordered_map<int, int> number_counts;
    for (int x; n-- && cin >> x;)
        ++number_counts[x];
    return number_counts;
}

int sock_merchant(const unordered_map<int, int>& sock_counts)
{
    return ranges::fold_left(sock_counts, 0, [](int pairs, const auto& x) { return pairs + x.second / 2; });
}
