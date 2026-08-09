// https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true
// C++23

import morfo;
import std;
using namespace std;

pair<int, int> breaking_records(const vector<int>& scores);

int main()
{
    morfo::skip_input_ln();
    auto [most_record_breaks, least_record_breaks] { breaking_records(morfo::readln<vector<int>>()) };
    println("{} {}", most_record_breaks, least_record_breaks);
    return 0;
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
