// https://www.hackerrank.com/challenges/insert-a-node-at-the-head-of-a-linked-list/problem?isFullScreen=true
// C++23

import std;
using namespace std;

int main()
{
    int n;
    cin >> n;
    forward_list<int> list;

    for (int i{}, x{}; i < n; ++i) {
        cin >> x;
        list.push_front(x);
    }

    for (auto x : list)
        println("{}", x);

    return 0;
}
