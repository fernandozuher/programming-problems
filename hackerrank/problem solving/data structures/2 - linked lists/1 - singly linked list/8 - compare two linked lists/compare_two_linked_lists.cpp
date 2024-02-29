// https://www.hackerrank.com/challenges/compare-two-linked-lists/problem?isFullScreen=true

#include <algorithm>
#include <forward_list>
#include <iostream>
#include <vector>

using namespace std;

forward_list<int> initialize_list(const int n);

template<class T>
void print_array(const vector<T>& array);

int main()
{
    int test_cases;
    cin >> test_cases;
    vector<bool> are_lists_equals(test_cases);

    for (int n{}; auto&& x : are_lists_equals) {
        cin >> n;
        forward_list<int> list1 {initialize_list(n)};
        cin >> n;
        forward_list<int> list2 {initialize_list(n)};
        x = list1 == list2;
    }

    print_array(are_lists_equals);

    return 0;
}

    forward_list<int> initialize_list(const int n)
    {
        forward_list<int> list(n);
        ranges::generate(list, [] {int x; cin >> x; return x;});
        return list;
    }

    template<class T>
    void print_array(const vector<T>& array)
    {
        ranges::for_each(array, [](const auto x) {cout << x << '\n';});
    }
