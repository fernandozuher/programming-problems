// https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true
// From C++20

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

template<class T = int>
vector<T> read(int n);
vector<int> breaking_records(const vector<int>& scores);

int main()
{
    int n;
    cin >> n;
    ranges::copy(breaking_records(read(n)), ostream_iterator<int>(cout, " "));
    return 0;
}

    template<class T>
    vector<T> read(const int n)
    {
        vector<T> array(n);
        copy_n(istream_iterator<T>(cin), n, array.begin());
        return array;
    }

    vector<int> breaking_records(const vector<int>& scores)
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
