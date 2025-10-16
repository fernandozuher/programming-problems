// https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

#include <iostream>
#include <ranges>
#include <vector>

using namespace std;

vector<int> read_numbers(int n);
pair<int, int> breaking_records(const vector<int>& scores);

int main()
{
    int n;
    cin >> n;
    auto scores{read_numbers(n)};
    auto [most_record_breaks, least_record_breaks]{breaking_records(scores)};
    cout << most_record_breaks << ' ' << least_record_breaks << '\n';
    return 0;
}

vector<int> read_numbers(int n)
{
    vector<int> arr(n);
    for (auto& x : arr)
        cin >> x;
    return arr;
}

pair<int, int> breaking_records(const vector<int>& scores)
{
    int most_record_breaks{}, least_record_breaks{};

    for (int most_points{scores.front()}, least_points{scores.front()}; int score : scores | views::drop(1))
        if (score > most_points) {
            most_points = score;
            ++most_record_breaks;
        } else if (score < least_points) {
            least_points = score;
            ++least_record_breaks;
        }

    return {most_record_breaks, least_record_breaks};
}
