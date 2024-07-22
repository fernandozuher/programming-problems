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
vector<vector<T>> data_test();
template<class T = int>
void test(const vector<T>& array);
template<class T = int>
Singly_Linked_List<T> digits_to_list(long long n, bool forward_order = true);
vector<int> break_number_to_digits(long long n);
template<class T = int>
bool is_palindrome(const Singly_Linked_List<T>& list);

int main()
{
    for (const auto& array : data_test()) {
        test(array);
        println("");
    }
    return 0;
}

template<class T>
vector<vector<T>> data_test()
{
    vector palindromes{121, 1331, 12321, 14641};
    vector not_palindromes{123, 45, 321, 100};
    return {palindromes, not_palindromes};
}

template<class T>
void test(const vector<T>& array)
{
    println("Is palindrome?");
    for (const auto n : array)
        println("{}: {}", n, is_palindrome(digits_to_list(n)));
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

template<class T>
bool is_palindrome(const Singly_Linked_List<T>& list)
{
    if (!list.head())
        return false;

    vector array{list.head()->data};
    for (auto node{list.head()->next}; node; node = node->next)
        array.push_back(node->data);

    auto forward = array | views::take(array.size() / 2);
    auto backward = array | views::reverse | views::take(array.size() / 2);
    return ranges::equal(forward, backward);
}
