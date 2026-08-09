// https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true
// C++23

import morfo;
import std;
using namespace std;
using namespace ranges;
using namespace views;

vector<int> sequence_equation(const vector<int>& arr);

int main()
{
    morfo::skip_input_ln();
    vector<int> arr = morfo::readln();
    morfo::println(sequence_equation(arr));
    return 0;
}

// n: length of arr/output
// T: O(n)
// S: O(n) extra space
vector<int> sequence_equation(const vector<int>& arr)
{
    vector<int> values_to_index(arr.size());
    for (auto [i, val] : enumerate(arr))
        values_to_index.at(val - 1) = i;

    return values_to_index
        | views::transform([&values_to_index](auto val) { return values_to_index.at(val) + 1; })
        | to<vector>();
}
