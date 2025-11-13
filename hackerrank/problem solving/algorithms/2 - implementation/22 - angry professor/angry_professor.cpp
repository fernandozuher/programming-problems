// https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> read_numbers(int n);
bool angry_professor(const vector<int>& arrival_times, int threshold);

int main()
{
    int n;
    cin >> n;

    for (int i{}; i < n; ++i) {
        int size, threshold;
        cin >> size >> threshold;
        vector arrival_times{read_numbers(size)};
        puts(angry_professor(arrival_times, threshold) ? "YES" : "NO");
    }

    return 0;
}

vector<int> read_numbers(int n)
{
    vector<int> arr(n);
    for (auto& x : arr)
        cin >> x;
    return arr;
}

bool angry_professor(const vector<int>& arrival_times, int threshold)
{
    int count = ranges::count_if(arrival_times, [](auto t) { return t <= 0; });
    return count < threshold;
}
