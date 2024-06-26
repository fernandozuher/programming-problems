// https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

vector<int> read_int_array(int n);
tuple<int, int> breaking_records(const vector<int>& scores);

int main()
{
    int n;
    cin >> n;
    vector array{read_int_array(n)};
    const auto [most_points_records, least_points_records] {breaking_records(array)};
    cout << most_points_records << ' ' << least_points_records;
    return 0;
}

    vector<int> read_int_array(const int n)
    {
        vector<int> array(n);
        copy_n(istream_iterator<int>(cin), n, array.begin());
        return array;
    }

    tuple<int, int> breaking_records(const vector<int>& scores)
    {
        int breaking_most_points_records{}, breaking_least_points_records{};

        for (int most_points{scores.front()}, least_points{scores.front()}; const int score : scores)
            if (score > most_points) {
                most_points = score;
                ++breaking_most_points_records;
            }
            else if (score < least_points) {
                least_points = score;
                ++breaking_least_points_records;
            }

        return {breaking_most_points_records, breaking_least_points_records};
    }
