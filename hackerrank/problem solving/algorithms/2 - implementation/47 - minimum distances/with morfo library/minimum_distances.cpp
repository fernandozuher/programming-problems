// https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true
// C++23

import morfo;
import std;
using namespace std;

int min_distance(const vector<int>& arr);

int main()
{
    morfo::skip_input_ln();
    vector<int> arr = morfo::readln();
    println("{}", min_distance(arr));
    return 0;
}

// n: length of arr
// T: O(n)
// S: O(n) extra space
int min_distance(const vector<int>& arr)
{
    unordered_map<int, int> last_seen;
    int min_dist{ -1 };

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
