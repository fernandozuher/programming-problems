// From C++23

#include <memory>
#include <print>
#include <vector>

#include "Singly_Linked_List.h"

using namespace std;
using namespace list_exercises;

template<class T = int>
vector<Singly_Linked_List<T>> data_test();
template<class T = int>
void test(Singly_Linked_List<T>& list, T x);
template<class T = int>
void partition(Singly_Linked_List<T>& list, T x);

int main()
{
    constexpr auto x_partition{5};
    println("Partition: {}", x_partition);
    for (auto& list : data_test())
        test(list, x_partition);
    return 0;
}

template<class T>
vector<Singly_Linked_List<T>> data_test()
{
    return {Singly_Linked_List{{3, 5, 8, 5, 10, 2, 1}}, Singly_Linked_List{{5, 3, 8, 2, 10, 2, 5}}};
}

template<class T>
void test(Singly_Linked_List<T>& list, const T x)
{
    print("Original list: ");
    list.print_list();
    partition(list, x);
    print("Partitioned list: ");
    list.print_list();
}

template<class T>
void partition(Singly_Linked_List<T>& list, const T x)
{
    shared_ptr<Node<T>> first_node_less_than_x;
    if (!list.head() && !list.head()->next)
        return;

    for (auto previous_node{list.head()}, node{previous_node->next}, next_node{shared_ptr<Node<T>>{}}; node;
         node = next_node) {
        if (next_node = node->next; node->data < x) {
            node->next = list.head();
            list.head(node);
            previous_node->next = next_node;
        }
        else
            previous_node = node;
         }
}
