// From C++23

#include <iostream>
#include <limits>
#include <memory>
#include <print>
#include <ranges>
#include <vector>

using namespace std;

template<class T = int>
struct Binary_Tree_Node {
    T data;
    shared_ptr<Binary_Tree_Node> left, right;
};

template<class T = int>
shared_ptr<Binary_Tree_Node<T>> generate_binary_search_tree(bool search = true);
template<class T = int>
void in_order_traversal(const shared_ptr<Binary_Tree_Node<T>>& node);
template<class T = int>
bool is_binary_search_tree(const shared_ptr<Binary_Tree_Node<T>>& node,
                           const shared_ptr<T>& previous_visited_data = make_shared<T>(numeric_limits<T>::min()));

int main()
{
    for (const auto search : {true, false}) {
        auto tree{generate_binary_search_tree(search)};
        cout << "In-order tree traversal: ";
        in_order_traversal(tree);
        println("\nIs binary search tree: {}", is_binary_search_tree(tree));
        println("");
    }
    return 0;
}

template<class T>
shared_ptr<Binary_Tree_Node<T>> generate_binary_search_tree(const bool search)
{
    vector<shared_ptr<Binary_Tree_Node<T>>> nodes;
    constexpr int n{7};
    for (const auto i : views::iota(0, n))
        nodes.emplace_back(make_shared<Binary_Tree_Node<T>>(i));

    auto root{nodes.at(3)};
    auto node0{nodes.at(0)};
    auto node1{nodes.at(1)};
    auto node2{nodes.at(2)};
    root->left = node1;
    node1->left = node0;
    node1->right = node2;

    auto node4{nodes.at(4)};
    auto node5{nodes.at(5)};
    auto node6{nodes.at(6)};
    root->right = node5;

    if (search) {
        node5->left = node4;
        node5->right = node6;
    }
    else {
        node5->left = node6;
        node5->right = node4;
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
bool is_binary_search_tree(const shared_ptr<Binary_Tree_Node<T>>& node, const shared_ptr<T>& previous_visited_data)
{
    if (node) {
        if (!is_binary_search_tree(node->left, previous_visited_data) || *previous_visited_data > node->data)
            return false;
        *previous_visited_data = node->data;
        return is_binary_search_tree(node->right, previous_visited_data);
    }
    return true;
}
