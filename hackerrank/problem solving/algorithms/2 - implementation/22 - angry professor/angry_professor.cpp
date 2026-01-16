// https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true
// C++23

import std;
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
        vector arrival_times{ read_numbers(size) };
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

// k: length of array arrival_times
// T: O(k)
// S: O(1) extra space
bool angry_professor(const vector<int>& arrival_times, int threshold)
{
    int on_time = ranges::count_if(arrival_times, [](auto t) { return t <= 0; });
    return on_time < threshold;
}
