// https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true
// C++23

#include <iostream>
#include <ranges>
#include <vector>

using namespace std;

vector<int> read_numbers(int n);
vector<int> sequence_equation(const vector<int>& arr);

int main()
{
    int n;
    cin >> n;
    vector arr{read_numbers(n)};

    for (auto val : sequence_equation(arr))
        cout << val << '\n';

    return 0;
}

vector<int> read_numbers(int n)
{
    vector<int> arr(n);
    for (auto& val : arr)
        cin >> val;
    return arr;
}

vector<int> sequence_equation(const vector<int>& arr)
{
    vector<int> values_to_index(arr.size());
    for (auto [i, val] : views::enumerate(arr))
        values_to_index.at(val - 1) = i;

    vector<int> res(arr.size());
    for (auto [i, val] : views::enumerate(values_to_index))
        res.at(i) = values_to_index.at(val) + 1;

    return res;
}
