#pragma once

#include <memory>
#include <print>
#include <vector>

using namespace std;

namespace list_exercises {
    template<class T = int>
    struct Node {
        shared_ptr<Node> next;
        T data{};
        explicit Node(const T& data);
    };

    template<class T = int>
    class Singly_Linked_List {
        shared_ptr<Node<T>> head_list;

    public:
        Singly_Linked_List() = default;
        explicit Singly_Linked_List(const shared_ptr<Node<T>>& node);
        template<class container = vector<T>>
        explicit Singly_Linked_List(const container& data);

        [[nodiscard]] const shared_ptr<Node<T>>& head() const;
        void head(const shared_ptr<Node<T>>& node);
        void append_to_tail(T data);
        void append_to_tail(const shared_ptr<Node<T>>& node);
        [[nodiscard]] shared_ptr<Node<T>> kth_node(int k) const;
        void print_list() const;
    };
}

#include "Singly_Linked_List.tpp"
