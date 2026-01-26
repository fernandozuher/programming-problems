// https://www.hackerrank.com/challenges/append-and-delete/problem?isFullScreen=true
// C++23

import std;
using namespace std;

bool append_and_delete(string_view s1, string_view s2, int n_ops);
int common_prefix_length(string_view s1, string_view s2);

int main()
{
    string s1, s2;
    int n_ops;
    cin >> s1 >> s2 >> n_ops;
    cout << (append_and_delete(s1, s2, n_ops) ? "Yes" : "No");
    return 0;
}

// n1: length of string s1
// n2: length of string s2
// T: O(min(n1, n2))
// S: O(1) extra space
bool append_and_delete(string_view s1, string_view s2, int n_ops)
{
    int prefix_len{ common_prefix_length(s1, s2) };
    int ops_needed = (s1.size() - prefix_len) + (s2.size() - prefix_len);
    if (n_ops < ops_needed)
        return false;

    if (n_ops >= s1.size() + s2.size())
        return true;

    return (n_ops - ops_needed) % 2 == 0;
}

int common_prefix_length(string_view s1, string_view s2)
{
    for (auto [i, t] : views::zip(s1, s2) | views::enumerate)
        if (auto [x, y] = t; x != y)
            return i;
    return min(s1.size(), s2.size());
}
