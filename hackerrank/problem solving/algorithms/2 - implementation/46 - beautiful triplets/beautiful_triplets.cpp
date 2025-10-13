// https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<int> read_numbers(int n);
int find_beautiful_triplets(const vector<int>& arr, int beautiful_difference);

int main()
{
    int n, beautiful_difference;
    cin >> n >> beautiful_difference;
    vector arr{read_numbers(n)};
    cout << find_beautiful_triplets(arr, beautiful_difference) << '\n';

    return 0;
}

vector<int> read_numbers(int n)
{
    vector<int> arr(n);
    for (auto& x : arr)
        cin >> x;
    return arr;
}

int find_beautiful_triplets(const vector<int> &arr, int beautiful_difference)
{
    int count{};
    for (auto values{set(arr.begin(), arr.end())}; auto x : arr)
        count += values.contains(x + beautiful_difference) && values.contains(x + 2 * beautiful_difference);
    return count;
}
