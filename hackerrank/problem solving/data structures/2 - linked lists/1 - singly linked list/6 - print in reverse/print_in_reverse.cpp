// https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list-in-reverse/problem?isFullScreen=true

#include <algorithm>
#include <forward_list>
#include <iostream>
#include <vector>

using namespace std;

forward_list<int> initialize_list(const int n);
void print_reverse_list(forward_list<int>& list);

int main()
{
    int test_cases;
    cin >> test_cases;
    vector<forward_list<int>> reversed_lists(test_cases);

    for (int n{}; auto& x : reversed_lists) {
        cin >> n;
        forward_list<int> list {initialize_list(n)};
        x = list;
    }

    for (auto& list : reversed_lists)
        print_reverse_list(list);

    return 0;
}

    forward_list<int> initialize_list(const int n)
    {
        forward_list<int> list(n);
        ranges::generate(list, [] {int x; cin >> x; return x;});
        return list;
    }

    void print_reverse_list(forward_list<int>& list)
    {
        list.reverse();
        ranges::for_each(list, [](const auto x) {cout << x << '\n';});
        list.reverse();
    }
