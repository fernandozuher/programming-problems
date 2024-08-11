// From C++23

#include <algorithm>
#include <iostream>
#include <iterator>
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
vector<ptr_node<T>> data_test(const vector<ptr_node<T>>& nodes);
template<class T = int>
vector<ptr_node<T>> generate_binary_tree(int n);
template<class T = int>
void in_order(const ptr_node<T>& node, vector<T>& path);
template<class T = int>
bool is_tree_subtree_of(const ptr_node<T>& bigger_tree, const ptr_node<T>& potential_subtree);
template<class T = int>
bool check_subtree(const ptr_node<T>& tree_a, const ptr_node<T>& tree_b);

int main()
{
    constexpr int n{10};
    auto nodes{generate_binary_tree(n)};

    auto root{nodes.front()};
    vector<int> path;
    in_order(root, path);

    cout << "Tree A in-order traversal: ";
    ranges::copy(path, ostream_iterator<int>(cout, " "));
    println("");

    for (const auto& potential_subtree : data_test(nodes)) {
        cout << "Tree B in-order traversal - is subtree of A?: ";
        path.clear();
        in_order(potential_subtree, path);
        ranges::copy(path, ostream_iterator<int>(cout, " "));
        println(" - {}", is_tree_subtree_of(root, potential_subtree));
    }

    return 0;
}

template<class T>
vector<ptr_node<T>> data_test(const vector<ptr_node<T>>& nodes)
{
    constexpr int n_nodes_to_test{3};
    int first_index = (nodes.size() / n_nodes_to_test);
    vector<ptr_node<T>> data;

    // -1 because index starts at 0
    auto current_index{first_index - 1};

    // Subtrees of tree
    for ([[maybe_unused]] const auto i : views::iota(0, n_nodes_to_test)) {
        data.push_back(nodes.at(current_index));
        current_index += first_index;
    }

    auto node_bigger_than_root{*nodes.at(2)};
    node_bigger_than_root.right = make_shared<Binary_Tree_Node<T>>(8);
    node_bigger_than_root.right->right = make_shared<Binary_Tree_Node<T>>(9);
    data.push_back(make_shared<Binary_Tree_Node<T>>(node_bigger_than_root));

    // Not subtrees of Tree
    auto node_bigger_than_root_2{*nodes.at(2)};
    node_bigger_than_root_2.right = make_shared<Binary_Tree_Node<T>>(8);
    data.push_back(make_shared<Binary_Tree_Node<T>>(node_bigger_than_root_2));

    auto last_rightest_leaf{*nodes.back()};
    last_rightest_leaf.right = make_shared<Binary_Tree_Node<T>>(11);
    data.push_back(make_shared<Binary_Tree_Node<T>>(last_rightest_leaf));

    return data;
}

template<class T>
vector<ptr_node<T>> generate_binary_tree(const int n)
{
    vector<T> elements(n);
    ranges::iota(elements, 0);

    int left{};
    int right{n - 1};
    int middle{left + (right - left) / 2};

    auto data{elements.at(middle)};
    auto root{make_shared<Binary_Tree_Node<T>>(data)};

    Queue<pair<ptr_node<T>, pair<int, int>>> queue;
    queue.add({root, {left, right}});
    vector<ptr_node<T>> nodes;

    while (!queue.is_empty()) {
        auto [node, range]{queue.remove()};
        tie(left, right) = range;
        middle = left + (right - left) / 2;
        nodes.push_back(node);

        auto temp_right{middle - 1};
        if (left <= temp_right) {
            auto left_middle{left + (temp_right - left) / 2};
            auto left_data{elements.at(left_middle)};
            auto left_node{make_shared<Binary_Tree_Node<T>>(left_data)};
            node->left = left_node;
            queue.add({left_node, {left, temp_right}});
        }

        auto temp_left{middle + 1};
        if (temp_left <= right) {
            auto right_middle{temp_left + (right - temp_left) / 2};
            auto right_data{elements.at(right_middle)};
            auto right_node{make_shared<Binary_Tree_Node<T>>(right_data)};
            node->right = right_node;
            queue.add({right_node, {temp_left, right}});
        }
    }

    return nodes;
}

template<class T>
void in_order(const ptr_node<T>& node, vector<T>& path)
{
    if (node) {
        in_order(node->left, path);
        path.push_back(node->data);
        in_order(node->right, path);
    }
}

template<class T>
bool is_tree_subtree_of(const ptr_node<T>& bigger_tree, const ptr_node<T>& potential_subtree)
{
    if (!bigger_tree || !potential_subtree)
        throw invalid_argument("At least one of the arguments is null");

    Queue<ptr_node<T>> queue;
    queue.add(bigger_tree);

    while (!queue.is_empty()) {
        auto node{queue.remove()};

        if (node->data == potential_subtree->data && check_subtree(node, potential_subtree))
            return true;

        if (node->left)
            queue.add(node->left);

        if (node->right)
            queue.add(node->right);
    }
    return false;
}

template<class T>
bool check_subtree(const ptr_node<T>& tree_a, const ptr_node<T>& tree_b)
{
    if (!tree_a || !tree_b)
        throw invalid_argument("At least one of the arguments is null");

    Queue<ptr_node<T>> queue_subtree, queue_tree;
    queue_subtree.add(tree_a);
    queue_tree.add(tree_b);

    while (!queue_subtree.is_empty() && !queue_tree.is_empty()) {
        auto subtree{queue_subtree.remove()};
        auto tree{queue_tree.remove()};

        if (
            subtree->data != tree->data ||
            (subtree->left && !tree->left || !subtree->left && tree->left) ||
            (subtree->right && !tree->right || !subtree->right && tree->right)
        )
            return false;

        if (subtree->left && tree->left) {
            queue_subtree.add(subtree->left);
            queue_tree.add(tree->left);
        }

        if (subtree->right && tree->right) {
            queue_subtree.add(subtree->right);
            queue_tree.add(tree->right);
        }
    }
    return true;
}
