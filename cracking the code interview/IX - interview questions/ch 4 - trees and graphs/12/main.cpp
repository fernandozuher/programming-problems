// From C++23

#include <algorithm>
#include <cmath>
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
vector<ptr_node<T>> generate_binary_tree(int n);
template<class T = int>
void paths_with_sum(const ptr_node<T>& node, int wanted_sum, int& matched_sums, int current_sum = 0);

int main()
{
    constexpr int n{10};
    auto nodes{generate_binary_tree(n)};
    int n_wanted_sums{log2(n) * nodes.back()->data};

    println("Paths with sum X: Y");
    for (const int wanted_sum : views::iota(0, n_wanted_sums)) {
        int matched_sums{};
        for (const auto& node : nodes)
            paths_with_sum(node, wanted_sum, matched_sums);
        println("{}: {}", wanted_sum, matched_sums);
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

        int temp_right{middle - 1};
        if (left <= temp_right) {
            auto left_middle{left + (temp_right - left) / 2};
            auto left_data{elements.at(left_middle)};
            auto left_node{make_shared<Binary_Tree_Node<T>>(left_data)};
            node->left = left_node;
            queue.add({left_node, {left, temp_right}});
        }

        int temp_left{middle + 1};
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
void paths_with_sum(const ptr_node<T>& node, const int wanted_sum, int& matched_sums, int current_sum)
{
    if (node) {
        current_sum += node->data;
        if (current_sum == wanted_sum)
            ++matched_sums;
        paths_with_sum(node->left, wanted_sum, matched_sums, current_sum);
        paths_with_sum(node->right, wanted_sum, matched_sums, current_sum);
    }
}
