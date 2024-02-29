// https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list/problem?isFullScreen=true

#include <algorithm>
#include <forward_list>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    forward_list<int> list(n);
    ranges::generate(list, [] {int x; cin >> x; return x;});
    ranges::for_each(list, [](const auto x) {cout << x << '\n';});

    return 0;
}