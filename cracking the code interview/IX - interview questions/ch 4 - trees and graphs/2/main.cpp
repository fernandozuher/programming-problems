#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <print>
#include <vector>

#include "Queue.h"

using namespace std;
using namespace queue_exercises;

template<class T = int>
struct Tree_Node {
    T data;
    shared_ptr<Tree_Node> left, right;
    explicit Tree_Node(const T& data): data{data} {}
};

template<class T = int>
shared_ptr<Tree_Node<T>> generate_balanced_binary_search_tree_from(const vector<T>& elements);
template<class T = int>
void in_order(const shared_ptr<Tree_Node<T>>& node);

int main()
{
    constexpr int n(10);
    vector<int> elements(n);
    ranges::iota(elements, 0);
    print("Sorted input array: ");
    ranges::copy(elements, ostream_iterator<int>(cout, " "));
    println("");

    // =P
    // set tree(elements.begin(), elements.end());
    // ranges::copy(tree, ostream_iterator<int>(cout, " "));
    // println("");

    auto tree_root{generate_balanced_binary_search_tree_from(elements)};
    print("In-order tree traversal: ");
    in_order(tree_root);

    return 0;
}

template<class T>
shared_ptr<Tree_Node<T>> generate_balanced_binary_search_tree_from(const vector<T>& elements)
{
    const int n = elements.size();
    int left{};
    int right{n - 1};
    int middle{left + (right - left) / 2};
    auto root{make_shared<Tree_Node<T>>(elements.at(middle))};

    Queue<pair<shared_ptr<Tree_Node<T>>, pair<int, int>>> queue;
    queue.add({root, {left, right}});

    println("Generating Balanced Binary Search Tree from array...");

    while (!queue.is_empty()) {
        const auto [node, index]{queue.remove()};
        tie(left, right) = index;
        middle = left + (right - left) / 2;
        print("{}: ", node->data);

        int temp_right{middle - 1};
        unique_ptr<T> potential_left_child;
        if (left <= temp_right) {
            int left_middle{left + (temp_right - left) / 2};
            auto left_node{make_shared<Tree_Node<T>>(elements.at(left_middle))};
            node->left = left_node;
            queue.add({left_node, {left, temp_right}});
            potential_left_child = make_unique<T>(left_node->data);
        }

        int temp_left{middle + 1};
        unique_ptr<T> potential_right_child;
        if (temp_left <= right) {
            int right_middle{temp_left + (right - temp_left) / 2};
            auto right_node{make_shared<Tree_Node<T>>(elements.at(right_middle))};
            node->right = right_node;
            queue.add({right_node, {temp_left, right}});
            potential_right_child = make_unique<T>(right_node->data);
        }

        cout << "[";
        if (potential_left_child)
            cout << *potential_left_child;
        cout << "|";
        if (potential_right_child)
            cout << *potential_right_child;
        println("]");
    }

    println("Tree (min) height: log {} = {}", n, log2(n));

    return root;
}

template<class T>
void in_order(const shared_ptr<Tree_Node<T>>& node)
{
    if (node) {
        in_order(node->left);
        print("{} ", node->data);
        in_order(node->right);
    }
}
