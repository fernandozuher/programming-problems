// https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> read_int_array(const int n);

class Breaking_Best_And_Worst_Records {

public:
    Breaking_Best_And_Worst_Records(const vector<int>& array): scores{array},
        breaking_most_points_records{}, breaking_least_points_records{}
    {
        breaking_records();
    }

    int most_points_records() const
    {
        return breaking_most_points_records;
    }

    int least_points_records() const
    {
        return breaking_least_points_records;
    }

private:
    vector<int> scores;
    int breaking_most_points_records, breaking_least_points_records;

    void breaking_records()
    {
        int most_points {scores.front()};
        int least_points {scores.front()};

        for (const int score : scores)
            if (score > most_points) {
                most_points = score;
                ++breaking_most_points_records;
            }
            else if (score < least_points) {
                least_points = score;
                ++breaking_least_points_records;
            }
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> array {read_int_array(n)};

    Breaking_Best_And_Worst_Records records{array};
    cout << records.most_points_records() << ' ' << records.least_points_records();

    return 0;
}

    vector<int> read_int_array(const int n)
    {
        vector<int> array(n);
        generate(array.begin(), array.end(), []{int x; cin >> x; return x;});
        return array;
    }
