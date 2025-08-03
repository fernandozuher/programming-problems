// https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true
// C++23

#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

using namespace std;

vector<int> read_numbers(int n);
bool angry_professor(const vector<int>& arrival_times, int threshold);

int main()
{
    int n;
    cin >> n;
    vector<bool> cancelled_classes(n);

    for (auto&& cancelled : cancelled_classes) {
        int n, threshold;
        cin >> n >> threshold;
        vector arrival_times{read_numbers(n)};
        cancelled = angry_professor(arrival_times, threshold);
    }

    for (auto cancelled : cancelled_classes)
        puts(cancelled ? "YES" : "NO");

    return 0;
}

vector<int> read_numbers(int n)
{
    return views::repeat(0, n) | views::transform([](auto) {
        int x;
        cin >> x;
        return x;
    }) | ranges::to<vector>();
}

bool angry_professor(const vector<int>& arrival_times, int threshold)
{
    int count = ranges::count_if(arrival_times, [](auto t) { return t <= 0; });
    return count < threshold;
}
