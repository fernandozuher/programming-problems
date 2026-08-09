// https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true
// C++23

import morfo;
import std;
using namespace std;

int find_beautiful_triplets(const vector<int>& arr, int beautiful_difference);

int main()
{
    morfo::skip_input();
    int beautiful_difference = morfo::read();
    vector<int> arr = morfo::readln();
    println("{}", find_beautiful_triplets(arr, beautiful_difference));
    return 0;
}

// n: length of arr
// k: distinct numbers of arr
// k <= n
// T: O(n)
// S: O(k) = O(n) extra space
int find_beautiful_triplets(const vector<int>& arr, int beautiful_difference)
{
    auto values{ unordered_set(arr.begin(), arr.end()) };
    int double_bd{ 2 * beautiful_difference };
    return ranges::count_if(arr, [beautiful_difference, double_bd, &values](auto x) {
        return values.contains(x + beautiful_difference) && values.contains(x + double_bd);
        });
}
