// https://www.hackerrank.com/challenges/30-arrays/problem?isFullScreen=true
// From C++20 onwards

#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> array(n);
    copy_n(istream_iterator<int>(cin), n, array.begin());
    ranges::copy(array | views::reverse, ostream_iterator<int>(cout, " "));

    return 0;
}
