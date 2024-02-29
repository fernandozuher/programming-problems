// https://www.hackerrank.com/challenges/insert-a-node-into-a-sorted-doubly-linked-list/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

list<int> initialize_list(const int n);
list<int> sorted_insert(list<int>& list, const int data);
void print_list(const list<int>& list);

int main()
{
    int test_cases;
    cin >> test_cases;
    vector<list<int>> sorted_lists(test_cases);

    for (int n{}, data{}; auto& x : sorted_lists) {
        cin >> n;
        list<int> list {initialize_list(n)};
        cin >> data;
        x = sorted_insert(list, data);
    }

    for (const auto& list : sorted_lists) {
        print_list(list);
        cout << '\n';
    }

    return 0;
}

    list<int> initialize_list(const int n)
    {
        list<int> list(n);
        ranges::generate(list, [] {int x; cin >> x; return x;});
        return list;
    }

    list<int> sorted_insert(list<int>& list, const int data)
    {
        auto it {ranges::lower_bound(list, data)};
        list.insert(it, data);
        return list;
    }

    void print_list(const list<int>& list)
    {
        ranges::for_each(list, [](const auto x) {cout << x << ' ';});
    }
