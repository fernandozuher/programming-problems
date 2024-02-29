// https://www.hackerrank.com/challenges/merge-two-sorted-linked-lists/problem?isFullScreen=true

#include <algorithm>
#include <forward_list>
#include <iostream>
#include <vector>

using namespace std;

forward_list<int> initialize_list(const int n);
void print_list(const forward_list<int>& list);

int main()
{
    int test_cases;
    cin >> test_cases;
    vector<forward_list<int>> merged_lists(test_cases);

    for (int n{}; auto& x : merged_lists) {
        cin >> n;
        forward_list<int> list1 {initialize_list(n)};
        cin >> n;
        forward_list<int> list2 {initialize_list(n)};

        list1.merge(list2);
        x = list1;
    }

    for (const auto& list : merged_lists) {
        print_list(list);
        cout << '\n';
    }

    return 0;
}

    forward_list<int> initialize_list(const int n)
    {
        forward_list<int> list(n);
        ranges::generate(list, []{int x; cin >> x; return x;});
        return list;
    }

    void print_list(const forward_list<int>& list)
    {
        ranges::for_each(list, [](const auto x) {cout << x << ' ';});
    }
