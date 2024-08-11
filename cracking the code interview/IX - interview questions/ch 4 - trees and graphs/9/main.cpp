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
    shared_ptr<Binary_Tree_Node> left, right;
};

template<class T = int>
using ptr_node = shared_ptr<Binary_Tree_Node<T>>;

template<class T = int>
ptr_node<T> generate_binary_search_tree(int n);

template<class T = int>
void in_order(const ptr_node<T>& node);

template<class T = int>
vector<vector<T>> bst_depths(const ptr_node<T>& root);

template<class T = int>
void permutations(vector<vector<T>>& elements, vector<vector<T>>& sequences, int n, int i = 0,
                  shared_ptr<vector<T>> current = make_shared<vector<T>>());

int main()
{
    constexpr int n{6};
    auto root{generate_binary_search_tree(n)};
    cout << "Binary Tree in-order traversal: ";
    in_order(root);
    println("");

    auto nodes_in_depths{bst_depths(root)};
    println("Nodes in depth:");
    for (int i{}; const auto& vec : nodes_in_depths) {
        print("{}: ", i++);
        ranges::copy(vec, ostream_iterator<int>(cout, " "));
        println("");
    }

    vector<vector<int>> sequences;
    permutations(nodes_in_depths, sequences, n);
    println("{} possible input arrays to create above tree:", sequences.size());
    for (const auto& vec : sequences) {
        ranges::copy(vec, ostream_iterator<int>(cout, " "));
        println("");
    }

    return 0;
}

template<class T>
ptr_node<T> generate_binary_search_tree(const int n)
{
    vector<T> array(n);
    ranges::iota(array, 0);

    int left{};
    int right{n - 1};
    int middle{left + (right - left) / 2};

    auto root{make_shared<Binary_Tree_Node<T>>(array.at(middle))};
    Queue<pair<ptr_node<T>, pair<int, int>>> queue;
    queue.add({root, {left, right}});

    while (!queue.is_empty()) {
        const auto& [node, range]{queue.remove()};
        tie(left, right) = range;
        middle = left + (right - left) / 2;

        int temp_right{middle - 1};
        if (left <= temp_right) {
            auto left_middle{left + (temp_right - left) / 2};
            auto data{array.at(left_middle)};
            auto left_node{make_shared<Binary_Tree_Node<T>>(data)};
            node->left = left_node;
            queue.add({left_node, {left, temp_right}});
        }

        int temp_left{middle + 1};
        if (temp_left <= right) {
            auto right_middle{temp_left + (right - temp_left) / 2};
            auto data{array.at(right_middle)};
            auto right_node{make_shared<Binary_Tree_Node<T>>(data)};
            node->right = right_node;
            queue.add({right_node, {temp_left, right}});
        }
    }

    return root;
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
vector<vector<T>> bst_depths(const ptr_node<T>& root)
{
    if (!root)
        throw invalid_argument("Root is null");

    vector<vector<T>> nodes_in_depths{{}};
    Queue<ptr_node<T>> queue;
    queue.add(root);

    for (auto nodes_in_current_depth{1}, nodes_in_next_depth{0}; !queue.is_empty();) {
        auto node{queue.remove()};
        nodes_in_depths.back().push_back(node->data);

        if (node->left) {
            queue.add(node->left);
            ++nodes_in_next_depth;
        }
        if (node->right) {
            queue.add(node->right);
            ++nodes_in_next_depth;
        }

        if (nodes_in_current_depth-- == 1) {
            nodes_in_current_depth = nodes_in_next_depth;
            nodes_in_next_depth = 0;
            nodes_in_depths.push_back({});
        }
    }
    nodes_in_depths.pop_back();

    return nodes_in_depths;
}

template<class T>
void permutations(vector<vector<T>>& elements, vector<vector<T>>& sequences, const int n, const int i,
                  shared_ptr<vector<T>> current)
{
    if (current->size() == n) {
        sequences.push_back(*current);
        return;
    }

    do {
        ranges::copy(elements.at(i), back_inserter(*current));
        permutations(elements, sequences, n, i + 1, current);
        for (int size = elements.at(i).size(); [[maybe_unused]] const auto j : views::iota(0, size))
            current->pop_back();
    }
    while (ranges::next_permutation(elements.at(i)).found);
}
