// https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true
// C++23

import std;
using namespace std;
using namespace ranges;

vector<int> read_numbers(int n);
pair<int, int> breaking_records(const vector<int>& scores);

int main()
{
    int n;
    cin >> n;
    auto [most_record_breaks, least_record_breaks] { breaking_records(read_numbers(n)) };
    println("{} {}", most_record_breaks, least_record_breaks);
    return 0;
}

vector<int> read_numbers(int n)
{
    return views::iota(0, n) | views::transform([](auto) {int x; cin >> x; return x; }) | to<vector>();
}

// n: length of scores
// T: O(n)
// S: O(1) extra space
pair<int, int> breaking_records(const vector<int>& scores)
{
    int most_record_breaks{}, least_record_breaks{};

    for (int most_points{ scores.front() }, least_points{ scores.front() }; int score : scores)
        if (score > most_points) {
            most_points = score;
            ++most_record_breaks;
        }
        else if (score < least_points) {
            least_points = score;
            ++least_record_breaks;
        }

    return { most_record_breaks, least_record_breaks };
}
