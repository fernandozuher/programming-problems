// https://www.hackerrank.com/challenges/insert-a-node-at-a-specific-position-in-a-linked-list/problem?isFullScreen=true

#include <algorithm>
#include <forward_list>
#include <iostream>

using namespace std;

forward_list<int> initialize_list(const int n);
forward_list<int> insert_at_position(forward_list<int>& list, const int position, const int data);
void print_list(const forward_list<int>& list);

int main()
{
    int n;
    cin >> n;
    forward_list<int> list {initialize_list(n)};

    int data, position;
    cin >> data >> position;
    list = insert_at_position(list, position, data);

    print_list(list);

    return 0;
}

    forward_list<int> initialize_list(const int n)
    {
        forward_list<int> list(n);
        ranges::generate(list, [] {int x; cin >> x; return x;});
        return list;
    }

    forward_list<int> insert_at_position(forward_list<int>& list, const int position, const int data)
    {
        auto it {position ? std::next(list.begin(), position - 1) : list.before_begin()};
        list.insert_after(it, data);
        return list;
    }

    void print_list(const forward_list<int>& list)
    {
        ranges::for_each(list, [](const auto x) {cout << x << ' ';});
    }
