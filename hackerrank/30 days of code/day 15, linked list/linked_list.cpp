// https://www.hackerrank.com/challenges/30-linked-list/problem?isFullScreen=true

#include <algorithm>
#include <forward_list>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    forward_list<int> singly_list;

    for (auto end = singly_list.before_begin(); cin >> n; end = singly_list.insert_after(end, n));
    ranges::for_each(singly_list, [](auto& node){cout << node << ' ';});

    return 0;
}
