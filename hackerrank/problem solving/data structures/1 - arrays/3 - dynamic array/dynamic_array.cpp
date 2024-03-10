// https://www.hackerrank.com/challenges/dynamic-array/problem?isFullScreen=true

#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

constexpr int query_size {3};

class Dynamic_Array {
public:
    explicit Dynamic_Array(const int n);
    void handle_query(const std::array<int, query_size>& query);
    vector<int> answers() const;

private:
    int n;
    vector<vector<int>> array;
    vector<int> answers_to_queries;
    int last_answer;
};

    Dynamic_Array::Dynamic_Array(const int n): n{n}, array{vector<vector<int>>(n)}, last_answer{} {}

    void Dynamic_Array::handle_query(const std::array<int, query_size>& query)
    {
        const auto [type, x, y] {query};
        int index {(x ^ last_answer) % n};

        if (type == 1)
            array.at(index).push_back(y);
        else {
            int j = y % array.at(index).size();
            last_answer = array.at(index).at(j);
            answers_to_queries.push_back(last_answer);
        }
    }

    vector<int> Dynamic_Array::answers() const
    {
        return answers_to_queries;
    }

//////////////////////////////////////////////////

int main()
{
    int n, n_queries;
    cin >> n >> n_queries;

    Dynamic_Array obj{n};
    for (array<int, query_size> query; n_queries--;) {
        ranges::generate(query, [] {int x; cin >> x; return x;});
        obj.handle_query(query);
    }

    ranges::for_each(obj.answers(), [](const auto x) {cout << x << '\n';});

    return 0;
}
