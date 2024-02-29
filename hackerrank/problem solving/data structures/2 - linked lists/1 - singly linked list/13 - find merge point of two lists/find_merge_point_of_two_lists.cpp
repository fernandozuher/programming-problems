// https://www.hackerrank.com/challenges/find-the-merge-point-of-two-joined-linked-lists/problem?isFullScreen=true

// BAD INPUT COMPOSED (ADAPTED FROM) BY HACKERRANK SOURCE

#include <algorithm>
#include <forward_list>
#include <iostream>
#include <vector>

using namespace std;

forward_list<int> initialize_list(const int n);
int get_node_value(const forward_list<int>& list, const int position);

template<class T>
void print_array(const vector<T>& array);

int main()
{
    int test_cases;
    cin >> test_cases;
    vector<int> merged_point_values(test_cases);

    for (int index{}, n{}; auto& x : merged_point_values) {
        cin >> index >> n;
        forward_list<int> list1 {initialize_list(n)};
        cin >> n;
        forward_list<int> list2 {initialize_list(n)};
        x = get_node_value(list1, index);
    }

    print_array(merged_point_values);

    return 0;
}

    forward_list<int> initialize_list(const int n)
    {
        forward_list<int> list(n);
        ranges::generate(list, [] {int x; cin >> x; return x;});
        return list;
    }

    int get_node_value(const forward_list<int>& list, const int position)
    {
        return *std::next(list.begin(), position);
    }

    template<class T>
    void print_array(const vector<T>& array)
    {
        ranges::for_each(array, [](const auto x) {cout << x << '\n';});
    }
