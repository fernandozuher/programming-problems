#pragma once

template<class T>
list_exercises::Node<T>::Node(const T data): data{data} {}

template<class T>
list_exercises::Singly_Linked_List<T>::Singly_Linked_List(const shared_ptr<Node<T>>& node): head_list{node} {}

template<class T>
template<class container>
list_exercises::Singly_Linked_List<T>::Singly_Linked_List(const container& data)
{
    for (const auto x : data)
        append_to_tail(x);
}

template<class T>
[[nodiscard]] const shared_ptr<list_exercises::Node<T>>& list_exercises::Singly_Linked_List<T>::head() const
{
    return head_list;
}

template<class T>
void list_exercises::Singly_Linked_List<T>::head(const shared_ptr<Node<T>>& node)
{
    head_list = node;
}

template<class T>
void list_exercises::Singly_Linked_List<T>::append_to_tail(const T data)
{
    if (head_list) {
        auto node{head_list};
        while (node->next)
            node = node->next;
        node->next = make_shared<Node<T>>(data);
    }
    else
        head_list = make_shared<Node<T>>(data);
}

template<class T>
void list_exercises::Singly_Linked_List<T>::append_to_tail(const shared_ptr<Node<T>>& node)
{
    if (head_list) {
        auto node_list{head_list};
        while (node_list->next)
            node_list = node_list->next;
        node_list->next = node;
    }
    else
        head_list = node;
}

template<class T>
[[nodiscard]] shared_ptr<list_exercises::Node<T>> list_exercises::Singly_Linked_List<T>::kth_node(int k) const
{
    auto node{head()};
    if (k < 1)
        return nullptr;
    while (--k > 0 && node != nullptr)
        node = node->next;
    return node;
}

template<class T>
void list_exercises::Singly_Linked_List<T>::print_list() const
{
    auto node{head_list};
    for (; node->next; node = node->next)
        print("{} -> ", node->data);
    println("{}", node->data);
}
