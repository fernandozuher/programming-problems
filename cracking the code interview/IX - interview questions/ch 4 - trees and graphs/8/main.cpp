// From C++23

#include <algorithm>
#include <iostream>
#include <memory>
#include <print>
#include <ranges>
#include <stdexcept>
#include <unordered_set>
#include <vector>

#include "Queue.h"

using namespace std;
using namespace queue_exercises;

template<class T = int>
struct Binary_Tree_Node {
    T data;
    bool visited{};
    shared_ptr<Binary_Tree_Node> parent, left, right;
};

template<class T = int>
using ptr_node = shared_ptr<Binary_Tree_Node<T>>;

template<class T = int>
using vector_pair_ptr_node = vector<pair<ptr_node<T>, ptr_node<T>>>;

template<class T = int>
vector<ptr_node<T>> generate_binary_tree(int n);

template<class T = int>
void in_order(const ptr_node<T>& node);

template<class T = int>
vector_pair_ptr_node<T> data_test(const vector<ptr_node<T>>& nodes);

template<class T = int>
void permutation_with_repetition(const vector<ptr_node<T>>& elements, int n, vector_pair_ptr_node<T>& permutations,
                                 shared_ptr<vector<ptr_node<T>>> current_permutation = make_shared<vector<ptr_node<
                                     T>>>());

template<class T = int>
ptr_node<T> first_common_ancestor(const ptr_node<T>& a, const ptr_node<T>& b);

int main()
{
    constexpr int n{10};
    auto nodes{generate_binary_tree(n)};
    print("Binary tree in-order traversal: ");
    in_order(nodes.front());
    println("");

    println("First common ancestor of nodes:");
    for (const auto& [a, b] : data_test(nodes)) {
        print("{} {}: ", a->data, b->data);
        try {
            println("{}", first_common_ancestor(a, b)->data);
        }
        catch (const invalid_argument& error) {
            println("{}", error.what());
        }
    }
    return 0;
}

template<class T>
vector<ptr_node<T>> generate_binary_tree(const int n)
{
    vector<T> elements(n);
    ranges::iota(elements, 0);

    int left{};
    int right{n - 1};
    int middle{left + (right - left) / 2};

    Queue<pair<ptr_node<T>, pair<int, int>>> queue;
    auto root{make_shared<Binary_Tree_Node<T>>(elements.at(middle))};
    queue.add({root, {left, right}});

    vector<ptr_node<T>> nodes{root};

    while (!queue.is_empty()) {
        const auto& [node, range]{queue.remove()};
        tie(left, right) = range;
        middle = left + (right - left) / 2;

        int temp_right{middle - 1};
        if (left <= temp_right) {
            auto left_middle{left + (temp_right - left) / 2};
            auto data{elements.at(left_middle)};
            auto left_node{make_shared<Binary_Tree_Node<T>>(data)};
            left_node->parent = node;
            node->left = left_node;
            queue.add({left_node, {left, temp_right}});
            nodes.push_back(left_node);
        }

        int temp_left{middle + 1};
        if (temp_left <= right) {
            auto right_middle{temp_left + (right - temp_left) / 2};
            auto data{elements.at(right_middle)};
            auto right_node{make_shared<Binary_Tree_Node<T>>(data)};
            right_node->parent = node;
            node->right = right_node;
            queue.add({right_node, {temp_left, right}});
            nodes.push_back(right_node);
        }
    }

    return nodes;
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
vector_pair_ptr_node<T> data_test(const vector<ptr_node<T>>& nodes)
{
    vector_pair_ptr_node<T> permutations;
    constexpr int size_permutation{2};
    permutation_with_repetition(nodes, size_permutation, permutations);
    return permutations;
}

template<class T>
void permutation_with_repetition(const vector<ptr_node<T>>& elements, const int n,
                                 vector_pair_ptr_node<T>& permutations,
                                 shared_ptr<vector<ptr_node<T>>> current_permutation)
{
    if (current_permutation->size() == n) {
        permutations.push_back({current_permutation->front(), current_permutation->back()});
        return;
    }

    for (const auto& x : elements) {
        current_permutation->push_back(x);
        permutation_with_repetition(elements, n, permutations, current_permutation);
        current_permutation->pop_back();
    }
}

template<class T>
ptr_node<T> first_common_ancestor(const ptr_node<T>& a, const ptr_node<T>& b)
{
    if (!a || !b)
        throw invalid_argument("At least one of the nodes is null");

    if (!a->parent || !b->parent)
        throw invalid_argument("At least one of the nodes is the root, then there is not common ancestor");

    auto node_a{a->parent};
    unordered_set<ptr_node<T>> visited_nodes{node_a};
    for (; node_a && node_a != b; node_a = node_a->parent)
        visited_nodes.insert(node_a);

    if (node_a == b)
        return node_a->parent;

    auto node_b{b->parent};
    for (; node_b && !visited_nodes.contains(node_b); node_b = node_b->parent);
    return node_b;
}
