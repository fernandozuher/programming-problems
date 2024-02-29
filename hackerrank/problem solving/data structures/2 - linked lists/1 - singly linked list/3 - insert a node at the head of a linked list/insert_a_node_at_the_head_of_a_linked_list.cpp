// https://www.hackerrank.com/challenges/insert-a-node-at-the-head-of-a-linked-list/problem?isFullScreen=true

#include <algorithm>
#include <forward_list>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    forward_list<int> list;
    for (int x{}; n-- && cin >> x;)
        list.push_front(x);
    ranges::for_each(list, [](const auto x) {cout << x << '\n';});

    return 0;
}
