// From C++23

#include <iostream>
#include <memory>
#include <print>
#include <vector>

#include "Singly_Linked_List.h"

using namespace std;
using namespace list_exercises;

template<class T = int>
vector<shared_ptr<Node<T>>> data_test(const Singly_Linked_List<T>& list, int size_list);
template<class T = int>
void test(const Singly_Linked_List<T>& list, const shared_ptr<Node<T>>& node);
template<class T = int>
void delete_middle_node(const Singly_Linked_List<T>& list, const shared_ptr<Node<T>>& node_to_delete);

int main()
{
    auto data{"abcdef"s};
    Singly_Linked_List<char> list(data);
    list.print_list();
    for (const auto& node : data_test(list, data.size()))
        test(list, node);
    return 0;
}

template<class T>
vector<shared_ptr<Node<T>>> data_test(const Singly_Linked_List<T>& list, const int size_list)
{
    auto first_node{1};
    const auto first_node_to_delete{list.kth_node(first_node)};
    auto third_node{3};
    const auto third_node_to_delete{list.kth_node(third_node)};
    auto last_node{size_list};
    const auto last_node_to_delete{list.kth_node(last_node)};
    auto null_node{size_list + 1};
    const auto null_node_to_delete{list.kth_node(null_node)};
    return {first_node_to_delete, third_node_to_delete, last_node_to_delete, null_node_to_delete};
}

template<class T>
void test(const Singly_Linked_List<T>& list, const shared_ptr<Node<T>>& node)
{
    cout << "\nNode to be deleted: ";
    if (node)
        cout << node->data << ", " << node.get() << "\n";
    else
        cout << "null node\n";
    delete_middle_node(list, node);
    list.print_list();
}

template<class T>
void delete_middle_node(const Singly_Linked_List<T>& list, const shared_ptr<Node<T>>& node_to_delete)
{
    if (!node_to_delete)
        println("You can't delete a null node.");
    else if (node_to_delete == list.head())
        println("You can't delete the head node.");
    else if (!node_to_delete->next)
        println("You can't delete the last node.");

    if (!node_to_delete || node_to_delete == list.head() || !node_to_delete->next)
        return;

    for (auto node{list.head()}; node->next; node = node->next)
        if (node->next.get() == node_to_delete.get()) {
            node->next = node->next->next;
            node_to_delete->next = nullptr;
            break;
        }
}
