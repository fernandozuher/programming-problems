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
vector<tuple<Singly_Linked_List<T>, Singly_Linked_List<T>, shared_ptr<Node<T>>>> data_test();
template<class T = int>
tuple<Singly_Linked_List<T>, Singly_Linked_List<T>, shared_ptr<Node<T>>> input_with_intersection();
template<class T = int>
tuple<Singly_Linked_List<T>, Singly_Linked_List<T>, shared_ptr<Node<T>>> input_without_intersection();
template<class T = int>
void test(const tuple<Singly_Linked_List<T>, Singly_Linked_List<T>, shared_ptr<Node<T>>>& input);
template<class T = int>
vector<Node<T>*> get_node_references(const Singly_Linked_List<T>& list);
template<class T = int>
vector<Node<T>*> check_intersection(const Singly_Linked_List<T>& l1, const Singly_Linked_List<T>& l2);

int main()
{
    for (const auto& lists : data_test())
        test(lists);
    return 0;
}

template<class T>
vector<tuple<Singly_Linked_List<T>, Singly_Linked_List<T>, shared_ptr<Node<T>>>> data_test()
{
    return {input_with_intersection(), input_without_intersection()};
}

template<class T>
tuple<Singly_Linked_List<T>, Singly_Linked_List<T>, shared_ptr<Node<T>>> input_with_intersection()
{
    Singly_Linked_List l1;
    l1.append_to_tail(1);
    l1.append_to_tail(2);
    auto node{make_shared<Node<>>(3)};
    l1.append_to_tail(node);
    l1.append_to_tail(4);

    Singly_Linked_List l2;
    l2.append_to_tail(5);
    l2.append_to_tail(node);
    l2.append_to_tail(7);
    l2.append_to_tail(8);

    cout << "Node supposed to be intersection point in lists: " << node->data << ", " << node.get() << '\n';
    return {l1, l2, node};
}

template<class T>
tuple<Singly_Linked_List<T>, Singly_Linked_List<T>, shared_ptr<Node<T>>> input_without_intersection()
{
    Singly_Linked_List l1;
    l1.append_to_tail(1);
    l1.append_to_tail(2);
    l1.append_to_tail(3);

    Singly_Linked_List l2;
    l2.append_to_tail(1);
    l2.append_to_tail(2);
    l2.append_to_tail(3);

    return {l1, l2, nullptr};
}

template<class T>
void test(const tuple<Singly_Linked_List<T>, Singly_Linked_List<T>, shared_ptr<Node<T>>>& input)
{
    const auto [l1, l2, node]{input};

    print("List 1: ");
    l1.print_list();
    print("List 2: ");
    l2.print_list();

    print("List 1: ");
    ranges::copy(get_node_references(l1), ostream_iterator<Node<>*>(cout, " -> "));
    println("");
    print("List 2: ");
    ranges::copy(get_node_references(l2), ostream_iterator<Node<>*>(cout, " -> "));
    println("");

    if (const auto intersection{check_intersection(l1, l2)}; intersection.empty())
        cout << "There is not intersection.";
    else
        cout << "Intersection node: " << intersection.front()->data << ", " << intersection.front();
    println("\n");
}

template<class T>
vector<Node<T>*> get_node_references(const Singly_Linked_List<T>& list)
{
    if (!list.head())
        return {};
    vector array{list.head().get()};
    for (auto node{list.head()->next}; node; node = node->next)
        array.push_back(node.get());
    return array;
}

template<class T>
vector<Node<T>*> check_intersection(const Singly_Linked_List<T>& l1, const Singly_Linked_List<T>& l2)
{
    if (!l1.head() || !l2.head())
        return {};

    vector l1_nodes{get_node_references(l1)};
    vector l2_nodes{get_node_references(l2)};
    ranges::sort(l1_nodes);
    ranges::sort(l2_nodes);

    vector<Node<T>*> out;
    ranges::set_intersection(l1_nodes, l2_nodes, back_inserter(out));
    return out;
}
