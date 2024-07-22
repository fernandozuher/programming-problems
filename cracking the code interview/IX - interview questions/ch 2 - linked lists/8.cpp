// From C++23

#include <iostream>
#include <memory>
#include <set>

#include "Singly_Linked_List.h"

using namespace std;
using namespace list_exercises;

template<class T = int>
Singly_Linked_List<T> data_test();
template<class T = int>
shared_ptr<Node<T>> find_circular_node_in_list(const Singly_Linked_List<T>& list);

int main()
{
    auto input{data_test<char>()};
    auto circular_node{find_circular_node_in_list(input)};
    cout << "Circular node: " << circular_node->data << ", " << circular_node.get();
    return 0;
}

template<class T>
Singly_Linked_List<T> data_test()
{
    Singly_Linked_List<T> list;
    auto a{make_shared<Node<T>>('A')};
    auto b{make_shared<Node<T>>('B')};
    auto c{make_shared<Node<T>>('C')};
    auto d{make_shared<Node<T>>('D')};
    auto e{make_shared<Node<T>>('E')};

    list.append_to_tail(a);
    list.append_to_tail(b);
    list.append_to_tail(c);
    list.append_to_tail(d);
    list.append_to_tail(e);
    list.append_to_tail(c);

    println("{} -> {} -> {} -> {} -> {} -> {}", a->data, b->data, c->data, d->data, e->data, c->data);
    cout << "Circular node to be found: " << c->data << ", " << c.get() << '\n';
    return list;
}

template<class T>
shared_ptr<Node<T>> find_circular_node_in_list(const Singly_Linked_List<T>& list)
{
    if (!list.head())
        return {};
    set nodes{list.head().get()};
    auto node{list.head()->next};
    for (; node && !nodes.contains(node.get()); node = node->next)
        nodes.insert(node.get());
    return node;
}
