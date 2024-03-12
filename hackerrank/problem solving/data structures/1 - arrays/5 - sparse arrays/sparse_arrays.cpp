// https://www.hackerrank.com/challenges/sparse-arrays/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<string, int> read_input(int n);
vector<int> read_queries_and_count_matches(map<string, int>& input, const int n);

int main()
{
    int n;

    cin >> n;
    map<string, int> input {read_input(n)};

    cin >> n;
    vector<int> result {read_queries_and_count_matches(input, n)};
    for (const auto x : result)
        cout << x << '\n';
}

    map<string, int> read_input(int n)
    {
        map<string, int> input;
        for (string x; n-- && cin >> x; ++input[x]);
        return input;
    }

    vector<int> read_queries_and_count_matches(map<string, int>& input, const int n)
    {
        vector<int> result(n);
        ranges::generate(result, [&input] {string query; cin >> query; return input[query];});
        return result;
    }
