// https://www.hackerrank.com/challenges/get-the-value-of-the-node-at-a-specific-position-from-the-tail/problem?isFullScreen=true

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
    vector<int> nodes_values(test_cases);

    for (int n{}; auto& x : nodes_values) {
        cin >> n;
        forward_list<int> list {initialize_list(n)};

        int position_from_tail;
        cin >> position_from_tail;

        int position {n - position_from_tail - 1};
        x = get_node_value(list, position);
    }

    print_array(nodes_values);

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
