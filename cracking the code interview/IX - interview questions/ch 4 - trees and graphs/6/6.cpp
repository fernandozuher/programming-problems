// From C++23

#include <algorithm>
#include <iostream>
#include <memory>
#include <print>
#include <ranges>
#include <vector>

#include "Queue.h"

using namespace std;
using namespace queue_exercises;

template<class T = int>
struct Binary_Tree_Node {
    T data;
    shared_ptr<Binary_Tree_Node> parent, left, right;
};

template<class T = int>
using ptr_node = shared_ptr<Binary_Tree_Node<T>>;

template<class T = int>
vector<ptr_node<T>> create_binary_search_tree(int n);
template<class T = int>
vector<ptr_node<T>> data_test(const vector<ptr_node<T>>& nodes, int step = 1);
template<class T = int>
void in_order(const ptr_node<T>& node);
template<class T = int>
void print_while_find_next_nodes_of(const vector<ptr_node<T>>& nodes_to_test);
template<class T = int>
ptr_node<T> next_node(const ptr_node<T>& node);

int main()
{
    constexpr int n{50};
    auto tree{create_binary_search_tree(n)};
    print("Binary search tree in-order traversal: ");
    in_order(tree.front());
    println("");

    try {
        auto nodes_to_test{data_test(tree)};
        println("Node -> in-order sucessor:");
        print_while_find_next_nodes_of(nodes_to_test);
    }
    catch (const invalid_argument& error) {
        cerr << error.what() << '\n';
    }

    return 0;
}

template<class T>
vector<ptr_node<T>> create_binary_search_tree(const int n)
{
    vector<T> elements(n);
    ranges::iota(elements, 0);

    int left{};
    int right{n - 1};
    int middle{left + (right - left) / 2};

    using node_in_range = pair<ptr_node<T>, pair<int, int>>;

    auto root{make_shared<Binary_Tree_Node<T>>(elements.at(middle))};
    Queue<node_in_range> queue;
    queue.add({root, {left, right}});

    vector<ptr_node<T>> nodes{root};

    while (!queue.is_empty()) {
        auto [node, range]{queue.remove()};
        auto [left, right]{range};
        middle = left + (right - left) / 2;

        int temp_right{middle - 1};
        if (left <= temp_right) {
            auto left_middle{left + (temp_right - left) / 2};
            auto left_node{make_shared<Binary_Tree_Node<T>>(elements.at(left_middle))};
            left_node->parent = node;
            node->left = left_node;
            queue.add({left_node, {left, temp_right}});
            nodes.push_back(left_node);
        }

        int temp_left{middle + 1};
        if (temp_left <= right) {
            auto right_middle{temp_left + (right - temp_left) / 2};
            auto right_node{make_shared<Binary_Tree_Node<T>>(elements.at(right_middle))};
            right_node->parent = node;
            node->right = right_node;
            queue.add({right_node, {temp_left, right}});
            nodes.push_back(right_node);
        }
    }

    return nodes;
}

template<class T>
vector<ptr_node<T>> data_test(const vector<ptr_node<T>>& nodes, const int step)
{
    if (step <= 0)
        throw invalid_argument("Argument 'step' must be more than 0");

    vector<ptr_node<T>> data_test;
    int i{};
    auto every_step_elements{[&i, step]([[maybe_unused]] const auto x) { return i++ % step == 0; }};
    ranges::copy_if(nodes, back_inserter(data_test), every_step_elements);
    return data_test;
}

template<class T>
void in_order(const ptr_node<T>& node)
{
    if (node) {
        in_order(node->left);
        print("{} ", node->data);
        in_order(node->right);
    }
}

template<class T>
void print_while_find_next_nodes_of(const vector<ptr_node<T>>& nodes_to_test)
{
    for (const auto& node : nodes_to_test) {
        print("{} -> ", node->data);
        if (auto sucessor{next_node(node)}; sucessor)
            println("{}", sucessor->data);
        else
            println("");
    }
}

template<class T>
ptr_node<T> next_node(const ptr_node<T>& node)
{
    if (!node)
        return nullptr;

    if (!node->left && !node->right && node->parent && node->parent->left == node)
        return node->parent;

    if (!node->left && !node->right && node->parent && node->parent->right == node) {
        auto parent{node->parent};
        for (; parent && parent->data < node->data; parent = parent->parent);
        return parent;
    }

    if (node->left && node->right) {
        auto child{node->right};
        for (; child->left; child = child->left);
        return child;
    }

    return node->right; //if (!node->left && node->right)
}
