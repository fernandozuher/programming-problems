// https://www.hackerrank.com/challenges/delete-duplicate-value-nodes-from-a-sorted-linked-list/problem?isFullScreen=true

#include <algorithm>
#include <forward_list>
#include <iostream>
#include <vector>

using namespace std;

forward_list<int> initialize_list(const int n);
forward_list<int> remove_duplicates(forward_list<int>& list);
void print_list(const forward_list<int>& list);

int main()
{
    int test_cases;
    cin >> test_cases;
    vector<forward_list<int>> unique_lists(test_cases);

    for (int n{}; auto& x : unique_lists) {
        cin >> n;
        forward_list<int> list {initialize_list(n)};
        x = remove_duplicates(list);
    }

    for (const auto& list : unique_lists) {
        print_list(list);
        cout << '\n';
    }

    return 0;
}

    forward_list<int> initialize_list(const int n)
    {
        forward_list<int> list(n);
        ranges::generate(list, [] {int x; cin >> x; return x;});
        return list;
    }

    forward_list<int> remove_duplicates(forward_list<int>& list)
    {
        list.unique();
        return list;
    }

    void print_list(const forward_list<int>& list)
    {
        ranges::for_each(list, [](const auto x) {cout << x << ' ';});
    }
