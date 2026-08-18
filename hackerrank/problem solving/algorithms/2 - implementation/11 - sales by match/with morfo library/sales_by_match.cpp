// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true
// C++23

import morfo;
import std;
using namespace std;

size_t sock_merchant(const unordered_map<int, size_t>& socks_to_counts);

int main()
{
    morfo::skip_input_ln();
    vector<int> arr = morfo::readln();
    auto socks_to_counts = morfo::counter(arr);
    println("{}", sock_merchant(socks_to_counts));
    return 0;
}

// k: length of entries in socks_to_counts
// T: O(k)
// S: O(1) extra space
size_t sock_merchant(const unordered_map<int, size_t>& socks_to_counts)
{
    return morfo::sum(views::values(socks_to_counts) | views::transform([](int x) { return x / 2; }));
}
