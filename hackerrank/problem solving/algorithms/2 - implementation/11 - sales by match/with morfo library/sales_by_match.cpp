// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true
// C++23

import morfo;
import std;
using namespace std;

int sock_merchant(const unordered_map<int, int>& socks_to_counts);

int main()
{
    morfo::skip_input_ln();
    vector<int> arr = morfo::readln();
    println("{}", sock_merchant(morfo::counter<unordered_map<int, int>>(arr)));
    return 0;
}

// k: length of entries in socks_to_counts
// T: O(k)
// S: O(1) extra space
int sock_merchant(const unordered_map<int, int>& socks_to_counts)
{
    return *ranges::fold_left_first(views::values(socks_to_counts) | views::transform([](int x) { return x / 2; }), plus{});
}
