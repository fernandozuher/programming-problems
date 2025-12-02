// https://www.hackerrank.com/challenges/append-and-delete/problem?isFullScreen=true
// C++23

import std;
using namespace std;

bool append_and_delete(const string& s1, const string& s2, int n_ops);
int common_prefix_length(const string& s1, const string& s2);

int main()
{
    string initial_string, final_string;
    int n_operations;
    cin >> initial_string >> final_string >> n_operations;
    cout << (append_and_delete(initial_string, final_string, n_operations) ? "Yes" : "No");
    return 0;
}

bool append_and_delete(const string& s1, const string& s2, int n_ops)
{
    int prefix_len{ common_prefix_length(s1, s2) };
    int total_ops_needed = (s1.size() - prefix_len) + (s2.size() - prefix_len);
    bool can_remove_all{ n_ops >= s1.size() + s2.size() };
    return can_remove_all || (n_ops >= total_ops_needed && (n_ops - total_ops_needed) % 2 == 0);
}

int common_prefix_length(const string& s1, const string& s2)
{
    int min_len = min(s1.size(), s2.size());
    int i{ -1 };
    return ranges::any_of(views::zip(s1, s2), [&i](auto x) {++i; return get<0>(x) != get<1>(x); }) ? i : min_len;
}
