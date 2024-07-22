// From C++23

#include <algorithm>
#include <iostream>
#include <memory>
#include <print>
#include <ranges>
#include <vector>

#include "Singly_Linked_List.h"

using namespace std;
using namespace list_exercises;

template<class T = int>
vector<T> data_test();

template<class T = int>
Singly_Linked_List<T> digits_to_list(long long n, bool forward_order);

vector<int> break_number_to_digits(long long n);

void test(int n1, int n2, bool forward_order);

template<class T = int>
Singly_Linked_List<T>
sum_lists_in_forward_order(const Singly_Linked_List<T>& list1, const Singly_Linked_List<T>& list2);

template<class T = int>
int list_to_int(const Singly_Linked_List<T>& list);

template<class T = int>
Singly_Linked_List<T> sum_lists_in_backward_order(const Singly_Linked_List<T>& list1,
                                                  const Singly_Linked_List<T>& list2);
template<class T = int>
T if_node_get_data(shared_ptr<Node<T>>& node);

tuple<int, int> filter_sum_and_carry(int sum, int carry);

int main()
{
    for (bool forward_order{}; const auto _ : views::iota(0, 2)) {
        cout << "Sum digits stored in " << (forward_order ? "forward" : "backward") << " order:\n";
        for (auto number_pair : data_test() | views::chunk(2))
            test(number_pair.front(), number_pair.back(), forward_order);
        forward_order = !forward_order;
    }
    return 0;
}

template<class T>
vector<T> data_test()
{
    return {617, 295, 99, 99, 10, 1, 1, 10, 9, 19, 19, 9, 9, 99, 99, 9};
}

template<class T>
Singly_Linked_List<T> digits_to_list(const long long n, const bool forward_order)
{
    Singly_Linked_List<T> list;
    const auto insert_digit_to_list{[&list](const auto d) { list.append_to_tail(d); }};
    if (const auto x{break_number_to_digits(n)}; forward_order)
        ranges::for_each(x, insert_digit_to_list);
    else
        ranges::for_each(x | views::reverse, insert_digit_to_list);
    return list;
}

vector<int> break_number_to_digits(long long n)
{
    vector<int> digits;
    for (; n; n /= 10)
        digits.push_back(n % 10);
    ranges::reverse(digits);
    return digits;
}

void test(const int n1, const int n2, const bool forward_order)
{
    println("{} + {} = {}", n1, n2, n1 + n2);
    auto l1{digits_to_list(n1, forward_order)};
    auto l2{digits_to_list(n2, forward_order)};
    l1.print_list();
    l2.print_list();
    forward_order
        ? sum_lists_in_forward_order(l1, l2).print_list()
        : sum_lists_in_backward_order(l1, l2).print_list();
    println("");
    /*
        617 + 295 = 912
        99 + 99 = 198
        10 + 1 = 11
        1 + 10 = 11
        9 + 19 = 28
        19 + 9 = 28
        9 + 99 = 108
        99 + 9 = 108
    */
}

template<class T>
Singly_Linked_List<T> sum_lists_in_forward_order(const Singly_Linked_List<T>& list1, const Singly_Linked_List<T>& list2)
{
    int sum{list_to_int(list1) + list_to_int(list2)};
    vector vec_sum{break_number_to_digits(sum)};
    Singly_Linked_List list3;
    ranges::for_each(vec_sum, [&list3](const auto x) { list3.append_to_tail((x)); });
    return list3;
}

template<class T>
int list_to_int(const Singly_Linked_List<T>& list)
{
    int num{};
    for (auto it{list.head()}; it; it = it->next)
        num = num * 10 + it->data;
    return num;
}

template<class T>
Singly_Linked_List<T> sum_lists_in_backward_order(const Singly_Linked_List<T>& list1,
                                                  const Singly_Linked_List<T>& list2)
{
    shared_ptr<Node<T>> head, node;

    for (auto [carry, l1, l2]{tuple(0, list1.head(), list2.head())}; l1 || l2 || carry;) {
        int sum{if_node_get_data(l1)};
        sum += if_node_get_data(l2);
        tie(sum, carry) = filter_sum_and_carry(sum, carry);

        if (auto node_sum{make_shared<Node<T>>(sum)}; head) {
            node->next = node_sum;
            node = node->next;
        }
        else
            head = node = node_sum;
    }

    return Singly_Linked_List{head};
}

template<class T>
T if_node_get_data(shared_ptr<Node<T>>& node)
{
    T x{};
    if (node) {
        x = node->data;
        node = node->next;
    }
    return x;
}

tuple<int, int> filter_sum_and_carry(int sum, int carry)
{
    if (sum += carry; sum > 9) {
        auto result{div(sum, 10)};
        carry = result.quot;
        sum = result.rem;
    }
    else
        carry = 0;
    return {sum, carry};
}
