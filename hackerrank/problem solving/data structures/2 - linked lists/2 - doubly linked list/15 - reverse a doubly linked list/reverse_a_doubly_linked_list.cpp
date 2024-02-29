// https://www.hackerrank.com/challenges/reverse-a-doubly-linked-list/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

list<int> initialize_list(const int n);
list<int> reverse(list<int>& list);
void print_list(const list<int>& list);

int main()
{
    int test_cases;
    cin >> test_cases;
    vector<list<int>> reversed_lists(test_cases);

    for (int n{}; auto& x : reversed_lists) {
        cin >> n;
        list<int> list {initialize_list(n)};
        x = reverse(list);
    }

    for (const auto& list : reversed_lists) {
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

    list<int> reverse(list<int>& list)
    {
        list.reverse();
        return list;
    }

    void print_list(const list<int>& list)
    {
        ranges::for_each(list, [](const auto x) {cout << x << ' ';});
    }
