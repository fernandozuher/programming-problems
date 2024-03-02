// https://www.hackerrank.com/challenges/arrays-ds/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> reverse_array(vector<int>& array);

int main()
{
    int n;
    cin >> n;
    vector<int> array(n);
    ranges::generate(array, [] {int x; cin >> x; return x;});
    array = reverse_array(array);

    for (const auto x : array)
        cout << x << ' ';

    return 0;
}

    vector<int> reverse_array(vector<int>& array)
    {
        ranges::reverse(array);
        return array;
    }
