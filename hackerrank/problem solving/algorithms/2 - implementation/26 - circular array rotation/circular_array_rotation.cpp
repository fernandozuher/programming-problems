// https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

#include <iostream>
#include <vector>

using namespace std;

vector<int> read_numbers(int n);
void print_queries(const vector<int>& arr, const vector<int>& queries, int n_rotation);

int main()
{
    int n, n_rotation, n_queries;
    cin >> n >> n_rotation >> n_queries;
    vector arr{read_numbers(n)};
    vector queries{read_numbers(n_queries)};
    print_queries(arr, queries, n_rotation);
    return 0;
}

vector<int> read_numbers(int n)
{
    vector<int> arr(n);
    for (auto& x : arr)
        cin >> x;
    return arr;
}

void print_queries(const vector<int>& arr, const vector<int>& queries, int n_rotation)
{
    int n = arr.size();
    int r{n_rotation % n};
    for (auto q : queries) {
        int idx{(q + n - r) % n};
        cout << arr[idx] << '\n';
    }
}
