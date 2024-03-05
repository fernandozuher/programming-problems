// https://www.hackerrank.com/challenges/dynamic-array/problem?isFullScreen=true

#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

constexpr int query_size {3};

vector<array<int, query_size>> read_queries(const int n);
vector<int> dynamic_array(const vector<array<int, query_size>>& queries, const int n);

int main()
{
    int n, n_queries;
    cin >> n >> n_queries;
    vector<array<int, query_size>> queries {read_queries(n_queries)};
    vector<int> result {dynamic_array(queries, n)};
    ranges::for_each(result, [](const auto x) {cout << x << '\n';});

    return 0;
}

    vector<array<int, query_size>> read_queries(const int n)
    {
        vector<array<int, query_size>> queries(n, array<int, query_size>());
        for (auto& query : queries)
            ranges::generate(query, [] {int x; cin >> x; return x;});
        return queries;
    }

    vector<int> dynamic_array(const vector<array<int, query_size>>& queries, const int n)
    {
        vector<vector<int>> array(n);
        vector<int> answers;

        for (int last_answer {}; const auto& query : queries) {
            const auto [type, x, y] {query};

            int index {(x ^ last_answer) % n};

            if (type == 1)
                array.at(index).push_back(y);
            else {
                int j = y % array.at(index).size();
                last_answer = array.at(index).at(j);
                answers.push_back(last_answer);
            }
        }

        return answers;
    }
