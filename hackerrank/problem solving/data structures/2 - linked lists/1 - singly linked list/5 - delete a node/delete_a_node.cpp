// https://www.hackerrank.com/challenges/delete-a-node-from-a-linked-list/problem?isFullScreen=true

#include <algorithm>
#include <forward_list>
#include <iostream>

using namespace std;

forward_list<int> initialize_list(const int n);
forward_list<int> delete_node(forward_list<int>& list, const int position);
void print_list(const forward_list<int>& list);

int main()
{
    int n;
    cin >> n;
    forward_list<int> list {initialize_list(n)};

    int position;
    cin >> position;
    list = delete_node(list, position);

    print_list(list);

    return 0;
}

    forward_list<int> initialize_list(const int n)
    {
        forward_list<int> list(n);
        ranges::generate(list, [] {int x; cin >> x; return x;});
        return list;
    }

    forward_list<int> delete_node(forward_list<int>& list, const int position)
    {
        auto it {position ? std::next(list.begin(), position - 1) : list.before_begin()};
        list.erase_after(it);
        return list;
    }

    void print_list(const forward_list<int>& list)
    {
        ranges::for_each(list, [](const auto x) {cout << x << ' ';});
    }
