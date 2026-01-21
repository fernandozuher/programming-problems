// https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true
// C++23

import std;
using namespace std;

vector<int> read_numbers(int n);
vector<int> sequence_equation(const vector<int>& arr);

int main()
{
    int n;
    cin >> n;
    vector arr{ read_numbers(n) };
    for (auto x : sequence_equation(arr))
        println("{}", x);
    return 0;
}

vector<int> read_numbers(int n)
{
    vector<int> arr(n);
    for (auto& x : arr)
        cin >> x;
    return arr;
}

// n: length of array arr/output
// T: O(n)
// S: O(n) extra space
vector<int> sequence_equation(const vector<int>& arr)
{
    vector<int> values_to_index(arr.size());
    for (auto [i, val] : views::enumerate(arr))
        values_to_index.at(val - 1) = i;
    return values_to_index 
        | views::transform([&values_to_index](auto val) {return values_to_index.at(val) + 1; }) 
        | ranges::to<vector>();
}
