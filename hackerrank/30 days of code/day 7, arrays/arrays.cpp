// https://www.hackerrank.com/challenges/30-arrays/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> array(n);
    ranges::generate(array, []{int element; cin >> element; return element;});

    for_each(array.crbegin(), array.crend(), [](const auto& element){cout << element << ' ';});

    return 0;
}
