// https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true
// C++23

#include <iostream>
#include <ranges>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> read_numbers(int n);
int min_distance(const vector<int>& arr);

int main()
{
    int n;
    cin >> n;
    vector arr{read_numbers(n)};
    cout << min_distance(arr) << '\n';
    return 0;
}

vector<int> read_numbers(int n)
{
    vector<int> arr(n);
    for (auto& x: arr)
        cin >> x;
    return arr;
}

int min_distance(const vector<int>& arr)
{
    unordered_map<int, int> last_seen;
    int min_dist{-1};

    for (auto [i, x] : arr | views::enumerate) {
        if (last_seen.contains(x))
            if (int dist = i - last_seen[x]; min_dist == -1 || dist < min_dist) {
                min_dist = dist;
                if (min_dist == 1)
                    return 1;
            }
        last_seen[x] = i;
    }

    return min_dist;
}
