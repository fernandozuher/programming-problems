// https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true
// C++23

import std;
using namespace std;

vector<int> read_numbers(int n);
int equalize_array(const vector<int>& arr);
map<int, int> counter(const vector<int>& arr);

int main()
{
    int n;
    cin >> n;
    cout << equalize_array(read_numbers(n)) << '\n';
    return 0;
}

vector<int> read_numbers(int n)
{
    vector<int> arr(n);
    for (auto& x : arr)
        cin >> x;
    return arr;
}

int equalize_array(const vector<int>& arr)
{
    auto counts{ counter(arr) };
    int max_count{ *ranges::max_element(views::values(counts)) };
    return arr.size() - max_count;
}

map<int, int> counter(const vector<int>& arr)
{
    map<int, int> counter;
    for (auto x : arr)
        ++counter[x];
    return counter;
}