// From C++23

#include <algorithm>
#include <memory>
#include <print>
#include <set>
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
shared_ptr<Binary_Tree_Node<T>> generate_balanced_binary_search_tree();
template<class T = int>
shared_ptr<Binary_Tree_Node<T>> generate_balanced_binary_tree(bool balanced = true);
template<class T = int>
void in_order_traversal(const shared_ptr<Binary_Tree_Node<T>>& node);
template<class T = int>
bool is_tree_balanced(const shared_ptr<Binary_Tree_Node<T>>& node, int height = 0,
                      const shared_ptr<set<int>>& max_heights = make_shared<set<int>>());
bool compare_heights(int height, const shared_ptr<set<int>>& max_heights = make_shared<set<int>>());

int main()
{
    vector trees{
        generate_balanced_binary_search_tree(), generate_balanced_binary_tree(false), generate_balanced_binary_tree()
    };
    for (const auto& tree : trees) {
        print("In-order tree traversal: ");
        in_order_traversal(tree);
        println("\n\tIs tree balanced: {}", is_tree_balanced(tree));
    }
    return 0;
}

template<class T>
shared_ptr<Binary_Tree_Node<T>> generate_balanced_binary_search_tree()
{
    constexpr int n{10};
    vector<int> elements(n);
    ranges::iota(elements, 0);

    int left{};
    int right{n - 1};
    int middle{left + (right - left) / 2};

    using node_in_range = pair<shared_ptr<Binary_Tree_Node<T>>, pair<int, int>>;

    Queue<node_in_range> queue;
    auto root{make_shared<Binary_Tree_Node<T>>(elements.at(middle))};
    queue.add({root, {left, right}});

    while (!queue.is_empty()) {
        auto [node, range]{queue.remove()};
        tie(left, right) = range;
        middle = left + (right - left) / 2;

        auto temp_right{middle - 1};
        if (left <= temp_right) {
            auto left_middle{left + (temp_right - left) / 2};
            auto left_node{make_shared<Binary_Tree_Node<T>>(elements.at(left_middle))};
            node->left = left_node;
            queue.add({left_node, {left, temp_right}});
        }

        auto temp_left{middle + 1};
        if (temp_left <= right) {
            auto right_middle{temp_left + (right - temp_left) / 2};
            auto right_node{make_shared<Binary_Tree_Node<T>>(elements.at(right_middle))};
            node->right = right_node;
            queue.add({right_node, {temp_left, right}});
        }
    }

    return root;
}

template<class T>
shared_ptr<Binary_Tree_Node<T>> generate_balanced_binary_tree(const bool balanced)
{
    auto root{make_shared<Binary_Tree_Node<T>>(0)};
    auto node1{make_shared<Binary_Tree_Node<T>>(1)};
    auto node2{make_shared<Binary_Tree_Node<T>>(2)};
    auto node3{make_shared<Binary_Tree_Node<T>>(3)};

    root->left = node1;
    node1->left = node2;
    if (balanced)
        root->right = node3;
    else
        node1->right = node3;

    return root;
}

template<class T>
void in_order_traversal(const shared_ptr<Binary_Tree_Node<T>>& node)
{
    if (node) {
        in_order_traversal(node->left);
        print("{} ", node->data);
        in_order_traversal(node->right);
    }
}

template<class T>
bool is_tree_balanced(const shared_ptr<Binary_Tree_Node<T>>& node, const int height,
                      const shared_ptr<set<int>>& max_heights)
{
    if (node)
        return is_tree_balanced(node->left, height + 1, max_heights)
            && is_tree_balanced(node->right, height + 1, max_heights);

    return compare_heights(height - 1, max_heights);
}

bool compare_heights(const int height, const shared_ptr<set<int>>& max_heights)
{
    if (max_heights->empty() || (max_heights->size() == 1 && abs(height - *max_heights->begin()) == 1))
        max_heights->insert(height);
    return max_heights->contains(height);
}
