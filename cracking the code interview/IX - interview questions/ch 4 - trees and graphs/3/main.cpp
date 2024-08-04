// From C++23

#include <algorithm>
#include <memory>
#include <print>
#include <ranges>
#include <vector>

#include "Queue.h"
#include "Singly_Linked_List.h"

using namespace std;
using namespace queue_exercises;
using namespace list_exercises;

template<class T = int>
struct Binary_Tree_Node {
    T data;
    shared_ptr<Binary_Tree_Node> left, right;
};

template<class T = int>
shared_ptr<Binary_Tree_Node<T>> generate_binary_tree();
template<class T = int>
void in_order_traversal(const shared_ptr<Binary_Tree_Node<T>>& node);
template<class T = int>
vector<Singly_Linked_List<T>> generate_list_of_depths_from_tree(const shared_ptr<Binary_Tree_Node<T>>& root);

int main()
{
    auto tree{generate_binary_tree()};
    println("In-order tree traversal:");
    in_order_traversal(tree);
    println("\n");

    println("Nodes from 0 to n-th depth of tree:");
    auto lists{generate_list_of_depths_from_tree(tree)};
    println("\n");
    println("Lists of depths from tree:");
    for (const auto& [i, list] : lists | views::enumerate) {
        print("{}: ", i);
        list.print_list();
    }
    return 0;
}

template<class T>
shared_ptr<Binary_Tree_Node<T>> generate_binary_tree()
{
    constexpr int n{10};
    vector<int> elements(n);
    ranges::iota(elements, 0);

    int left{};
    int right = elements.size() - 1;
    int middle{left + (right - left) / 2};
    auto root{make_shared<Binary_Tree_Node<T>>(elements.at(middle))};

    using node_with_parents = pair<shared_ptr<Binary_Tree_Node<T>>, pair<int, int>>;

    Queue<node_with_parents> queue;
    queue.add({root, {left, right}});

    while (!queue.is_empty()) {
        auto [node, index]{queue.remove()};
        tie(left, right) = index;
        middle = left + (right - left) / 2;

        auto temp_right{middle - 1};
        if (left <= temp_right) {
            int left_middle = left + (temp_right - left) / 2;
            auto left_node{make_shared<Binary_Tree_Node<T>>(elements.at(left_middle))};
            node->left = left_node;
            queue.add({left_node, {left, temp_right}});
        }

        auto temp_left{middle + 1};
        if (temp_left <= right) {
            int right_middle = temp_left + (right - temp_left) / 2;
            auto right_node{make_shared<Binary_Tree_Node<T>>(elements.at(right_middle))};
            node->right = right_node;
            queue.add({right_node, {temp_left, right}});
        }
    }

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
vector<Singly_Linked_List<T>> generate_list_of_depths_from_tree(const shared_ptr<Binary_Tree_Node<T>>& root)
{
    if (!root)
        return {};

    Queue<shared_ptr<Binary_Tree_Node<T>>> queue;
    queue.add(root);
    vector<Singly_Linked_List<T>> lists{Singly_Linked_List<T>()};

    int depth{};
    print("{}: ", depth++);

    for (int children_parent{1}, children_depth{}; !queue.is_empty();) {
        auto tree_node{queue.remove()};

        if (tree_node->left) {
            ++children_depth;
            queue.add(tree_node->left);
        }
        if (tree_node->right) {
            ++children_depth;
            queue.add(tree_node->right);
        }

        print("{} ", tree_node->data);
        lists.back().append_to_tail(tree_node->data);
        if (!--children_parent) {
            children_parent = children_depth;
            children_depth = 0;

            if (!queue.is_empty()) {
                lists.emplace_back(Singly_Linked_List<T>());
                println("");
                print("{}: ", depth);
            }
            ++depth;
        }
    }

    return lists;
}
