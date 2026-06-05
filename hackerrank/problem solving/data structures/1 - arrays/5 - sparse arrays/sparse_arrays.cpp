// https://www.hackerrank.com/challenges/sparse-arrays/problem?isFullScreen=true
// C++23

import std;
using namespace std;

vector<string> read_lines(int n);
unordered_map<string, int> counter(const vector<string>& strings);
vector<int> counts_from(unordered_map<string, int>& freq_map, const vector<string>& queries);

int main()
{
    int n;
    cin >> n;
    vector strings{ read_lines(n) };
    unordered_map strings_to_counts{ counter(strings) };

    cin >> n;
    vector queries{ read_lines(n) };

    for (auto x : counts_from(strings_to_counts, queries))
        println("{}", x);
}

vector<string> read_lines(int n)
{
    vector<string> arr(n);
    for (auto& x : arr)
        cin >> x;
    return arr;
}

unordered_map<string, int> counter(const vector<string>& strings)
{
    unordered_map<string, int> freq_map;
    for (const auto& x : strings)
        ++freq_map[x];
    return freq_map;
}

// n: length of queries
// max_query_string_length: 20
// T: O(n * max_query_string_length) = O(n * 20) = O(n)
// S: O(n) extra space
vector<int> counts_from(unordered_map<string, int>& freq_map, const vector<string>& queries)
{
    return queries | views::transform([&freq_map](const string& q) { return freq_map[q]; }) | ranges::to<vector>();
}
