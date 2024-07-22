// From C++23

#include <iostream>
#include <memory>
#include <print>
#include <ranges>
#include <vector>

#include "Singly_Linked_List.h"

using namespace std;
using namespace list_exercises;

ranges::iota_view<int, int> data_test(int size_list);
template<class T = int>
void test(const Singly_Linked_List<T>& list, int i);
template<class T = int>
void print_from_node(shared_ptr<Node<T>> node);

int main()
{
    vector data{9, 8, 7, 6, 5, 4, 3, 2, 1};
    Singly_Linked_List list(data);
    list.print_list();
    for (const auto& i : data_test(data.size()))
        test(list, i);
    return 0;
}

ranges::iota_view<int, int> data_test(const int size_list)
{
    const auto nth_nodes{size_list + 3};
    return views::iota(1, nth_nodes);
}

template<class T>
void test(const Singly_Linked_List<T>& list, const int i)
{
    const auto node{list.kth_node(i)};
    if (!node) {
        println("There is not {}th node in the list.", i);
        return;
    }
    print("From {}th node: ", i);
    print_from_node(node);
}

template<class T>
void print_from_node(shared_ptr<Node<T>> node)
{
    if (!node)
        return;
    for (; node->next; node = node->next)
        print("{} -> ", node->data);
    println("{}", node->data);
}
