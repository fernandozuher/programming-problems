// https://www.hackerrank.com/challenges/crush/problem?isFullScreen=true
// C++23

import std;
using namespace std;

long long array_manipulation(long long n, long long n_queries);
vector<long long> populate_arr(long long n, long long n_queries);
long long max_sequential_sum(const vector<long long>& arr);

int main()
{
    long long n, n_queries;
    cin >> n >> n_queries;
    cout << array_manipulation(n, n_queries);
    return 0;
}

// T: O(n + n_queries)
// S: O(n) extra space
long long array_manipulation(long long n, long long n_queries)
{
    vector arr{ populate_arr(n, n_queries) };
    return max_sequential_sum(arr);
}

vector<long long> populate_arr(long long n, long long n_queries)
{
    vector<long long> arr(n + 2); // +2 = 1-indexed array + range-end

    for (long long i{}; i < n_queries; ++i) {
        long long b, e, summand;
        cin >> b >> e >> summand;
        arr.at(b) += summand;
        arr.at(e + 1) -= summand;
    }

    return arr;
}

long long max_sequential_sum(const vector<long long>& arr)
{
    long long res{};
    for (long long sum{}; auto x : arr) {
        sum += x;
        res = max(res, sum);
    }
    return res;
}
