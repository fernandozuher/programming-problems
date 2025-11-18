// https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

#include <iostream>
#include <vector>

using namespace std;

vector<int> read_numbers(int n);
void print_queries(const vector<int>& arr, int n_rotation, int n_queries);

int main()
{
    int n, n_rotation, n_queries;
    cin >> n >> n_rotation >> n_queries;
    vector arr{read_numbers(n)};
    print_queries(arr, n_rotation, n_queries);
    return 0;
}

vector<int> read_numbers(int n)
{
    vector<int> arr(n);
    for (auto& x : arr)
        cin >> x;
    return arr;
}

void print_queries(const vector<int>& arr, int n_rotation, int n_queries)
{
    int n = arr.size();
    int r{n_rotation % n};
    for (int i{}; i < n_queries; ++i) {
        int query;
        cin >> query;
        int idx{(query + n - r) % n};
        cout << arr[idx] << '\n';
    }
}
