// https://www.hackerrank.com/challenges/reverse-a-linked-list/problem?isFullScreen=true

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
    vector<forward_list<int>> reversed_lists(test_cases);

    int n{};
    for (auto& x : reversed_lists) {
        cin >> n;
        forward_list<int> list {initialize_list(n)};
        list.reverse();
        x = list;
    }

    for (const auto& list : reversed_lists) {
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

    void print_list(const forward_list<int>& list)
    {
        ranges::for_each(list, [](const auto x) {cout << x << ' ';});
    }
