// https://www.hackerrank.com/challenges/dynamic-array/problem?isFullScreen=true
// C++23

import std;
using namespace std;

constexpr int query_size{ 3 };

class Dynamic_Array {
    int n;
    vector<vector<int>> array;
    vector<int> answers_to_queries;
    int last_answer;

public:
    explicit Dynamic_Array(int n) : n{ n }, array{ vector<vector<int>>(n) }, last_answer{} {}

    void handle_query(const std::array<int, query_size>& query)
    {
        const auto [type, x, y] {query};
        int index{ (x ^ last_answer) % n };

        if (type == 1)
            array.at(index).push_back(y);
        else {
            int j = y % array.at(index).size();
            last_answer = array.at(index).at(j);
            answers_to_queries.push_back(last_answer);
        }
    }

    vector<int> answers() const
    {
        return answers_to_queries;
    }
};

int main()
{
    int n, n_queries;
    cin >> n >> n_queries;

    Dynamic_Array obj{ n };
    for (int i{}; i < n_queries; ++i) {
        array<int, query_size> query;
        ranges::generate(query, [] {int x; cin >> x; return x;});
        obj.handle_query(query);
    }

    for (auto x : obj.answers())
        println("{}", x);

    return 0;
}
