// https://www.hackerrank.com/challenges/crush/problem?isFullScreen=true

#include <climits>
#include <iostream>
#include <vector>

using namespace std;

long array_manipulation(const int n, int n_queries);

int main()
{
    int n, n_queries;
    cin >> n >> n_queries;
    cout << array_manipulation(n, n_queries);
    return 0;
}

    long array_manipulation(const int n, int n_queries)
    {
        vector<int> array(n + 2); // n + 2 = 1-indexed array + range-end

        for (int b, e, summand; n_queries--;) {
            cin >> b >> e >> summand;
            array.at(b) += summand;
            array.at(e + 1) -= summand;
        }

        long max {LONG_MIN};
        for (long sum {}; const auto x : array) {
            if (!x)
                continue;
            sum += x;
            max = std::max(max, sum);
        }

        return max;
    }
